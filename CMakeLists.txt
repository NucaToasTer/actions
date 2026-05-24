cmake_minimum_required(VERSION 3.28)
project(ConsoleLogger LANGUAGES CXX)
 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
 
add_executable(main)
 
# CXX_MODULES configured as PRIVATE for the executable target
target_sources(main
    PRIVATE
        src/main.cpp
    PRIVATE FILE_SET CXX_MODULES FILES
        modules/test_modules.cppm
)
 
# Updated directory configuration to match your exact vendor path structure
target_include_directories(main PRIVATE
)
 
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(main PRIVATE -fuse-ld=lld)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(main PRIVATE stdc++exp)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(main PRIVATE /EHsc)
endif()
 
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(LLVM_BIN "D:/llvm-mingw/llvm-mingw-20260505-ucrt-x86_64/bin")
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LLVM_BIN}/libunwind.dll"
            "${LLVM_BIN}/libc++.dll"
            "${LLVM_BIN}/libwinpthread-1.dll"
            $<TARGET_FILE_DIR:main>
        COMMENT "Copying runtime DLLs..."
    )
endif()