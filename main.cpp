#include <raylib.h>
#include "key.h"
#include "map.h"
#include "player.h"
#include "tile.h"
#include "wall.h"

//시야, 창
constexpr float window_width{ 500 };
constexpr float window_height{ 500 };

enum GameState {
    SplashScreen,
    Gameplay,
    GameOver,
    Win
};
GameState gamestate = GameState::SplashScreen;
enum GameStage {
    Stage1=1,
    Stage2,
    Stage3,
    Stage4
};
GameStage gamestage = GameStage::Stage1;

void start_game() {
    gamestate = GameState::Gameplay;
  
}

void splash_screen() {
    

    DrawText("DigiPen 2023", 0, 50, 10, WHITE);

    DrawText("Press Space To Start", 0, 100, 10, WHITE);

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
}

void gameplay() {
    
    
}

void gameover_screen() {
   
    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
}





struct map {

    Vector2 position;
    Vector2 size;
    Color color;

    void draw() {
        DrawRectangleV(position, size, map_color);
    }

};
//시도하다 안한거
class Map {
public:
    Map(float posX, float posY, float width, float height, Color _color) {
        position.x = posX;
        position.y = posY;
        size.x = width;
        size.y = height;
        color = _color;
    };
    Vector2 position;
    Vector2 size;
    Color color;

    void draw() {
        DrawRectangleV(position, size, map_color);
    }
};



int main(void) {
    InitWindow(window_width, window_height, "GAM100_2%_Prototype");
    int GameStage= 0;
    map main_map{
        0.0f,
        0.0f,
        map_width,
        map_height,
        map_color
    };

    Player player(300, map_height / 2, 50, 50, RED);

    Portal portal0_1(490, 200, 10, 100, WHITE);
    Portal portal1_1(0, 600 / 2 - 50, 10, 100, WHITE);
    Portal portal1_2(990, 600 / 2 - 50, 10, 100, WHITE);
    Portal portal2_1(0, 100, 10, 100, WHITE);
    Portal portal2_2(500, 0, 100, 10, RED);
    Portal portal3_1(0, 600 / 2 - 50, 10, 100, WHITE);

    //case1
    GeneralWall case1Wall1(0, 0, 1000, 200, DARKGRAY);
    GeneralWall case1Wall2(0, 400, 1000, 200, DARKGRAY);
    SpeedUpTile case1SpeedUpTile1(0, 200, 1000, 200, ORANGE);

    //case2
    GeneralWall wall1(0.0f, 200.0f, 100.0f, 400.0f, DARKGRAY);
    GeneralWall wall2(300, 100, 200, 100, DARKGRAY);
    GeneralWall wall3(200, 200, 300, 100, DARKGRAY);
    GeneralWall wall4(200, 400, 400, 100, DARKGRAY);
    MovableWall movablewall(300, 0, 100, 100, GRAY);
    SpeedDownTile tile1(300, 300, 100, 100, BLUE);
    SpeedUpTile tile2(500, 100, 100, 200, ORANGE);
    Key key(125, 425, 50, 50, YELLOW);
    LockedWall lockedwall(400, 0, 100, 100, PURPLE);

    //case3
    GeneralWall case3Wall1(0, 0, 1000, 200, DARKGRAY);
    GeneralWall case3Wall2(0, 400, 1000, 200, DARKGRAY);
    SpeedDownTile case3SpeedDownTile1(0, 200, 1000, 200, BLUE);

    PressureGate pressureGate(400, 300, 100, 100, GREEN, 2);
    bool isPortal2_2Visible = false;


    int b0 = 1;
    int b1 = 1;
    int b2 = 1;
    int b3 = 1;
    Camera2D camera = {
    Vector2{window_width / 2.0f, window_height / 2.0f},
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

        switch (gamestate)
        {
        case GameState::SplashScreen:
            splash_screen();
            break;
        case GameState::Gameplay:
            switch (gamestage)
            {
            case GameStage::Stage1:
                map_width = 500;
                map_height = 500;
                map_color = BLACK;
                portal0_1.draw();
                portal0_1.Check(player);
                if (portal0_1.Check(player))
                {
                    gamestage = GameStage::Stage2;
                    player.position.x = 50;
                    player.position.y = 300;
                }
                if (b0) {
                    player.position.x = 50;
                    player.position.y = map_height / 2;
                    b0--;
                }
                break;
            case GameStage::Stage2:
                map_width = 1000;
                map_height = 600;
                map_color = BLACK;
                portal1_1.draw();
                portal1_1.Check(player);
                if (portal1_1.Check(player))
                {
                    gamestage = GameStage::Stage1;
                    player.position.x = 450;
                    player.position.y = 250;
                }
                portal1_2.draw();
                if (portal1_2.Check(player))
                {
                    gamestage = GameStage::Stage3;
                    player.position.x = 50;
                    player.position.y = 150;
                }
                case1Wall1.draw();
                case1Wall2.draw();
                case1Wall1.Collision(player);
                case1Wall2.Collision(player);

                case1SpeedUpTile1.draw();
                case1SpeedUpTile1.SpeedUp(player);
                break;
            case GameStage::Stage3:
                map_width = 600;
                map_height = 500;
                map_color = BLACK;
                portal2_1.draw();

                if (portal2_1.Check(player))
                {
                    gamestage = GameStage::Stage2;
                    player.position.x = 950;
                    player.position.y = 300;
                }

                if (portal2_2.Check(player))
                {
                    gamestage = GameStage::Stage4;
                    player.position.x = 50;
                    player.position.y = 300;
                }
                tile1.draw();
                tile2.draw();
                wall1.draw();
                wall2.draw();
                wall3.draw();
                wall4.draw();
                key.draw();
                movablewall.draw();
                lockedwall.draw();
                movablewall.push(player);
                movablewall.CollisionGeneralWall(wall4, player);
                movablewall.CollisionGeneralWall(wall3, player);
                movablewall.CollisionGeneralWall(wall2, player);
                movablewall.CollisionGeneralWall(wall1, player);
                movablewall.CollisionLockedWall(lockedwall, player);


                pressureGate.draw();
                if (pressureGate.checkActivation(player)) { //if player pressed pressuregate, portal2_2 became visible.
                    isPortal2_2Visible = true;;
                }
                if (isPortal2_2Visible) { //if boolean portal2_2 visible is true, draw it.
                    portal2_2.draw();
                }
                if (keycheck > 0) {

                }
                else {
                    key.get(player);
                }

                wall1.Collision(player);
                wall2.Collision(player);
                wall3.Collision(player);
                wall4.Collision(player);
                if (keyused > 0) {
                }
                else {
                    lockedwall.Collision(player);
                }
                direction = 1;
                tile1.SpeedDown(player);
                tile2.SpeedUp(player);

                break;
            case GameStage::Stage4:
                map_width = 1000;
                map_height = 600;
                map_color = BLACK;
                portal3_1.draw();

                if (portal3_1.Check(player))
                {
                    gamestage = GameStage::Stage3;
                    player.position.x = 550;
                    player.position.y = 100;
                }
                case3Wall1.draw();
                case3Wall2.draw();
                case3Wall1.Collision(player);
                case3Wall2.Collision(player);

                case3SpeedDownTile1.draw();
                case3SpeedDownTile1.SpeedDown(player);

                break;


            }
            gameplay();
            break;
        case GameState::GameOver:
            gameover_screen();
            break;
        }
       


        player.draw();
        player.move();

        //맵 벽
        if (player.position.x <= player.size.x / 2) {
            player.position.x = player.size.x / 2;
        }
        else if (player.position.x >= map_width - player.size.x / 2) {
            player.position.x = map_width - player.size.x / 2;
        }

        if (player.position.y <= player.size.y / 2) {
            player.position.y = player.size.y / 2;
        }
        else if (player.position.y >= map_height - player.size.y / 2) {
            player.position.y = map_height - player.size.y / 2;
        }



        //카메라 벽
        camera.target = player.position;

        if (player.position.x <= window_width / 2) {
            camera.target.x = window_width / 2;
        }
        else if (player.position.x >= map_width - window_width / 2) {
            camera.target.x = map_width - window_width / 2;
        }

        if (player.position.y <= window_height / 2) {
            camera.target.y = window_height / 2;
        }
        else if (player.position.y >= map_height - window_height / 2) {
            camera.target.y = map_height - window_height / 2;
        }


        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;

}
