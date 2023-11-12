#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"


//�÷��̾�
float direction = 1;
constexpr float speed = 5;

class Player { //player info
public:
    Player(float posX, float posY, float width, float height, Color _color);
    Vector2 position;
    Vector2 size;
    Color color;

    void draw();

    void move();
};
#endif