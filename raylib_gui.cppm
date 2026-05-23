module;

// 1. Include raylib normally so its structural types and color macros are available
#include "raylib.h"

// 2. Load raygui immediately right after so IT can use raylib's raw color macros internally
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
export module raylib_gui;

// 3. NOW capture raw copies of the color values for our C++ module exports
static const Color kLightGray  = LIGHTGRAY;
static const Color kGray       = GRAY;
static const Color kDarkGray   = DARKGRAY;
static const Color kYellow     = YELLOW;
static const Color kGold       = GOLD;
static const Color kOrange     = ORANGE;
static const Color kPink       = PINK;
static const Color kRed        = RED;
static const Color kMaroon     = MAROON;
static const Color kGreen      = GREEN;
static const Color kLime       = LIME;
static const Color kDarkGreen  = DARKGREEN;
static const Color kSkyBlue    = SKYBLUE;
static const Color kBlue       = BLUE;
static const Color kDarkBlue   = DARKBLUE;
static const Color kPurple     = PURPLE;
static const Color kViolet     = VIOLET;
static const Color kDarkPurple = DARKPURPLE;
static const Color kBeige      = BEIGE;
static const Color kBrown      = BROWN;
static const Color kDarkBrown  = DARKBROWN;
static const Color kWhite      = WHITE;
static const Color kBlack      = BLACK;
static const Color kBlank      = BLANK;
static const Color kMagenta    = MAGENTA;
static const Color kRayWhite   = RAYWHITE;

// 4. Clean out the preprocessor macros so they don't leak out of this file
#undef LIGHTGRAY
#undef GRAY
#undef DARKGRAY
#undef YELLOW
#undef GOLD
#undef ORANGE
#undef PINK
#undef RED
#undef MAROON
#undef GREEN
#undef LIME
#undef DARKGREEN
#undef SKYBLUE
#undef BLUE
#undef DARKBLUE
#undef PURPLE
#undef VIOLET
#undef DARKPURPLE
#undef BEIGE
#undef BROWN
#undef DARKBROWN
#undef WHITE
#undef BLACK
#undef BLANK
#undef MAGENTA
#undef RAYWHITE

// ============================================================================
// 5. Establish the actual C++ Module unit boundary
// ============================================================================

// ============================================================================
// 1. DATA TYPES & STRUCTURES
// ============================================================================
export using ::Vector2;
export using ::Vector3;
export using ::Vector4;
export using ::Matrix;
export using ::Color;
export using ::Rectangle;
export using ::Image;
export using ::Texture;
export using ::Texture2D;
export using ::TextureCubemap;
export using ::RenderTexture;
export using ::RenderTexture2D;
export using ::Font;
export using ::Camera2D;
export using ::Camera3D;
export using ::Camera; 

// ============================================================================
// 2. WINDOW & LIFECYCLE MANAGEMENT
// ============================================================================
export using ::InitWindow;
export using ::CloseWindow;
export using ::WindowShouldClose;
export using ::IsWindowReady;
export using ::IsWindowFullscreen;
export using ::IsWindowHidden;
export using ::IsWindowMinimized;
export using ::IsWindowMaximized;
export using ::IsWindowFocused;
export using ::IsWindowResized;
export using ::SetTargetFPS;
export using ::GetFPS;
export using ::GetFrameTime;
export using ::GetTime;

// ============================================================================
// 3. DRAWING & RENDERING PIPELINE
// ============================================================================
export using ::ClearBackground;
export using ::BeginDrawing;
export using ::EndDrawing;
export using ::BeginMode2D;
export using ::EndMode2D;
export using ::BeginMode3D;
export using ::EndMode3D;
export using ::BeginTextureMode;
export using ::EndTextureMode;
export using ::GetColor;

// Basic 2D Shapes
export using ::DrawRectangle;
export using ::DrawRectangleRec;
export using ::DrawRectangleLines;
export using ::DrawCircle;
export using ::DrawCircleV;
export using ::DrawLine;
export using ::DrawLineV;
export using ::DrawText;

// ============================================================================
// 4. INPUT SYSTEMS (KEYBOARD & MOUSE)
// ============================================================================
export using ::IsKeyPressed;
export using ::IsKeyDown;
export using ::IsKeyReleased;
export using ::IsKeyUp;
export using ::IsMouseButtonPressed;
export using ::IsMouseButtonDown;
export using ::IsMouseButtonReleased;
export using ::IsMouseButtonUp;
export using ::GetMouseX;
export using ::GetMouseY;
export using ::GetMousePosition;
export using ::GetMouseDelta;
export using ::GetMouseWheelMove;

export using ::KeyboardKey;
export using ::MouseButton;

// ============================================================================
// 5. RAYGUI CONTROLS & WIDGETS
// ============================================================================
export using ::GuiEnable;
export using ::GuiDisable;
export using ::GuiLock;
export using ::GuiUnlock;
export using ::GuiSetAlpha;
export using ::GuiSetState;
export using ::GuiGetState;

export using ::GuiWindowBox;
export using ::GuiGroupBox;
export using ::GuiLine;
export using ::GuiPanel;
export using ::GuiScrollPanel;

export using ::GuiLabel;
export using ::GuiButton;
export using ::GuiLabelButton;
export using ::GuiToggle;
export using ::GuiToggleGroup;
export using ::GuiCheckBox;
export using ::GuiComboBox;
export using ::GuiDropdownBox;
export using ::GuiSpinner;
export using ::GuiValueBox;
export using ::GuiTextBox;

export using ::GuiSlider;
export using ::GuiSliderBar;
export using ::GuiProgressBar;
export using ::GuiStatusBar;
export using ::GuiDummyRec;
export using ::GuiGrid;

export using ::GuiSetStyle;
export using ::GuiGetStyle;
export using ::GuiLoadStyle;
export using ::GuiLoadStyleDefault;

export using ::GuiControl;
export using ::GuiControlProperty;
export using ::GuiDefaultProperty;

// ============================================================================
// 6. TYPE-SAFE GLOBAL CONSTANT COLORS
// ============================================================================
export inline const Color LIGHTGRAY  = kLightGray;
export inline const Color GRAY       = kGray;
export inline const Color DARKGRAY   = kDarkGray;
export inline const Color YELLOW     = kYellow;
export inline const Color GOLD       = kGold;
export inline const Color ORANGE     = kOrange;
export inline const Color PINK       = kPink;
export inline const Color RED        = kRed;
export inline const Color MAROON     = kMaroon;
export inline const Color GREEN      = kGreen;
export inline const Color LIME       = kLime;
export inline const Color DARKGREEN  = kDarkGreen;
export inline const Color SKYBLUE    = kSkyBlue;
export inline const Color BLUE       = kBlue;
export inline const Color DARKBLUE   = kDarkBlue;
export inline const Color PURPLE     = kPurple;
export inline const Color VIOLET     = kViolet;
export inline const Color DARKPURPLE = kDarkPurple;
export inline const Color BEIGE      = kBeige;
export inline const Color BROWN      = kBrown;
export inline const Color DARKBROWN  = kDarkBrown;
export inline const Color WHITE      = kWhite;
export inline const Color BLACK      = kBlack;
export inline const Color BLANK      = kBlank;
export inline const Color MAGENTA    = kMagenta;
export inline const Color RAYWHITE   = kRayWhite;

export struct GuiProps {
    static constexpr int Default         = 0;  // Maps to raygui's DEFAULT
    static constexpr int BackgroundColor = 12; // Maps to raygui's BACKGROUND_COLOR
};