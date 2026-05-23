cmake_minimum_required(VERSION 3.28)
project(ModuleTest LANGUAGES CXX)

# ============================================================================
# C++ SYSTEM STANDARDS & SETTINGS
# ============================================================================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================================
# 1. FETCH RAYLIB SOURCE (Locked to the Stable 6.0 Milestone Release)
# ============================================================================
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
)

# Force raylib to compile as a minimal static library with Position Independent Code
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(WITH_PIC ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# ============================================================================
# 2. EXECUTABLE & MODULE TARGET CONFIGURATION
# ============================================================================
add_executable(main)

target_sources(main
    PRIVATE
        main.cpp
    PUBLIC
    FILE_SET CXX_MODULES FILES
        test_modules.cppm
        raylib_gui.cppm
)

target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${raylib_SOURCE_DIR}/src
)

target_link_libraries(main PRIVATE raylib)

# ============================================================================
# 3. MACOS FRAMEWORK LINKING
# ============================================================================
if(APPLE)
    target_link_libraries(main PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
    )
endif()

# ============================================================================
# 4. COMPILER SPECIFIC CONFIGURATIONS
# ============================================================================
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT APPLE)
    target_compile_options(main PRIVATE -fuse-ld=lld)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(main PRIVATE -fmodules-ts)
    target_link_libraries(main PRIVATE stdc++exp)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(main PRIVATE /std:c++23 /EHsc)
endif()

# ============================================================================
# 5. AUTO-COPY LLVM-MINGW RUNTIME DLLS (Windows only)
# ============================================================================
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND WIN32)
    set(LLVM_BIN "D:/llvm-mingw/llvm-mingw-20260505-ucrt-x86_64/bin")
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LLVM_BIN}/libunwind.dll"
            "${LLVM_BIN}/libc++.dll"
            "${LLVM_BIN}/libwinpthread-1.dll"
            $<TARGET_FILE_DIR:main>
        COMMENT "Copying LLVM runtime DLLs..."
    )
endif()
