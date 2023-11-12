#ifndef KEY_H
#define KEY_H
#include "raylib.h"
#include "player.h"
extern int keycheck;
extern int keyused;

class Key{
public:
    Key(float posX, float posY, float width, float height, Color _color);
    Vector2 position;
    Vector2 size;
    Color color;
    void draw();

    void get(Player& player);

};
#endif