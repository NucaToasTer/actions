import raylib_gui;
#include <cmath>

// ---------------------------------------------------------------------------
// Constants  –  tweak these to change the simulation
// ---------------------------------------------------------------------------
static constexpr int   SCREEN_W   = 800;
static constexpr int   SCREEN_H   = 600;
static constexpr float G_CONST    = 6.674e-11f;
static constexpr float DENSITY    = 2000.0f;       // kg/m³
static constexpr float DIST_SCALE = 1000.0f;       // pixels → metres

// ---------------------------------------------------------------------------
// Helper
// ---------------------------------------------------------------------------
static float radiusFromMass(float mass) {
    return std::cbrt((3.0f * mass) / (4.0f * 3.14159265359f * DENSITY)) / 100000.0f;
}

// ---------------------------------------------------------------------------
// Object
// ---------------------------------------------------------------------------
struct Object {
    Vector2 pos;
    Vector2 vel;
    float   mass;
    float   radius;
    Color   color;

    Object(Vector2 p, Vector2 v, float m, Color c)
        : pos(p), vel(v), mass(m), color(c) {
        radius = radiusFromMass(mass);
    }

    void draw() const {
        DrawCircleV(pos, radius, color);
    }

    void updatePos() {
        pos.x += vel.x / 94.0f;
        pos.y += vel.y / 94.0f;
    }

    void accelerate(float ax, float ay) {
        vel.x += ax;
        vel.y += ay;
    }

    void checkBoundary() {
        if (pos.x - radius < 0)        { pos.x = radius;            vel.x *= -0.8f; }
        if (pos.x + radius > SCREEN_W) { pos.x = SCREEN_W - radius; vel.x *= -0.8f; }
        if (pos.y - radius < 0)        { pos.y = radius;            vel.y *= -0.8f; }
        if (pos.y + radius > SCREEN_H) { pos.y = SCREEN_H - radius; vel.y *= -0.8f; }
    }
};

// ---------------------------------------------------------------------------
// Gravity between two objects
// ---------------------------------------------------------------------------
static void applyGravity(Object& a, Object& b) {
    float dx   = b.pos.x - a.pos.x;
    float dy   = b.pos.y - a.pos.y;
    float dist = std::sqrt(dx*dx + dy*dy);
    if (dist < 1e-3f) return;

    float distM = dist * DIST_SCALE;
    double force = ((double)G_CONST * (double)a.mass * (double)b.mass) / (distM * distM);

    float nx = dx / dist, ny = dy / dist;
    a.accelerate( nx * (float)(force / a.mass),  ny * (float)(force / a.mass));
    b.accelerate(-nx * (float)(force / b.mass), -ny * (float)(force / b.mass));
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main() {
    InitWindow(SCREEN_W, SCREEN_H, "mass_sim");
    SetTargetFPS(60);

    // -----------------------------------------------------------------------
    // Two bodies  –  edit pos, vel, mass, color, radius here
    // -----------------------------------------------------------------------
    const float MASS        = 5.0f * 1e21f;
    const float CIRCLE_SIZE = 15.0f;   // visual radius in pixels

    Object a(
        Vector2{ 250.0f, 300.0f },   // starting position
        Vector2{  0.0f,  -120.0f },   // starting velocity (pixels/s equivalent)
        MASS,
        SKYBLUE
    );
    a.radius = CIRCLE_SIZE;

    Object b(
        Vector2{ 550.0f, 300.0f },   // starting position
        Vector2{  10.0f,   120.0f },   // starting velocity
        MASS,
        RED
    );
    b.radius = CIRCLE_SIZE;
    // -----------------------------------------------------------------------

    while (!WindowShouldClose()) {
        applyGravity(a, b);

        a.updatePos();
        b.updatePos();

        a.checkBoundary();
        b.checkBoundary();

        BeginDrawing();
        ClearBackground(BLACK);
        a.draw();
        b.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}