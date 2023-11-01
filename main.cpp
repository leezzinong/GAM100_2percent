#include "raylib.h"
constexpr int map_width{ 2000 };
constexpr int map_height{ 2000 };
constexpr Color map_color = { BLACK };

constexpr int window_width{ 500 };
constexpr int window_height{ 500 };
constexpr int size{ 50 };

struct map {

    int x;
    int y;
    int width;
    int height;
    Color color;

    void draw(){
        DrawRectangle(x, y, width, height, BLACK);
    }

};


Vector2 position{ map_width / 2, map_height / 2 };


int main(void) {
    InitWindow(window_width, window_height, "um");

    map main_map{
        0,
        0,
        map_width,
        map_height,
        map_color
    };


    Camera2D camera = {
    Vector2{ window_width / 2.0f, window_height / 2.0f },
    Vector2{ 0.0f, 0.0f },
    0.0f,
    1.0f,
    };

    


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        BeginMode2D(camera);


        main_map.draw();
        DrawRectangle(100, 100, 100, 100, WHITE);
        DrawRectangle(500, 500, 100, 100, BLUE);
        DrawRectangle(1500, 1500, 100, 100, BLUE);
        DrawRectangle(position.x - size / 2, position.y - size / 2, size, size, RED);

        if (IsKeyDown(KEY_UP))position.y -= 5;
        if (IsKeyDown(KEY_DOWN))position.y += 5;
        if (IsKeyDown(KEY_RIGHT))position.x += 5;
        if (IsKeyDown(KEY_LEFT))position.x -= 5;

        if (position.x <= size/2) {
            position.x = size/2;
        }else if (position.x >= map_width - size/2) {
            position.x = map_width - size/2;
        }

        if (position.y <= size/2) {
            position.y = size/2;
        }else if (position.y >= map_height - size/2) {
            position.y = map_height - size/2;
        }


/// Joo
        camera.target = position;

        if (position.x <= window_width/2) {
            camera.target.x = window_width/2;
        }else if (position.x >= map_width - window_width/2) {
            camera.target.x = map_width - window_width/2;
        }

        if (position.y <= window_height/2) {
            camera.target.y = window_height/2;
        }else if (position.y >= map_height - window_height/2) {
            camera.target.y = map_height - window_height/2;
        }


        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}