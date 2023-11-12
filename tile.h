#ifndef TILE_H
#define TILE_H
#include "raylib.h"
#include "player.h"

class Tile { //setting tiles
public:
    Tile(float posX, float posY, float width, float height, Color _color);
    Vector2 position;
    Vector2 size;
    Color color;

    void draw();
};
class SavePoint : public Tile {
public:
    int savecheck = 0;
    SavePoint(float posX, float posY, float width, float height, Color _color);
    void save(Player& player);
};
class SpeedUpTile : public Tile { //enter this area, player's speed increased.
public:
    SpeedUpTile(float posX, float posY, float width, float height, Color _color);
    void SpeedUp(Player& player);
};
class SpeedDownTile : public Tile {//enter this area, player's speed decresed.
public:
    SpeedDownTile(float posX, float posY, float width, float height, Color _color);
    void SpeedDown(Player& player);
};
//다음 맵으로 이동
class Portal : public Tile {
public:
    int in_portal = false;
    Portal(float posX, float posY, float width, float height, Color _color);
    bool Check(Player& player);
};
class PressureGate : public Tile {
public:
    PressureGate(float posX, float posY, float width, float height, Color _color, int requiredPressure) : Tile(posX, posY, width, height, _color) { //pressuregate info
        isActivated = false;
    };
    
    bool isActivated = false;

    void draw();

    bool checkActivation(Player& player);
};
#endif
