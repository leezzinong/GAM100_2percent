#ifndef WALL_H
#define WALL_H
#include "raylib.h"
#include "player.h"
#include "key.h"
#include "map.h"
class Wall {//setting wall
public:
    Wall(float posX, float posY, float width, float height, Color _color);
    Vector2 position;
    Vector2 size;
    Color color;

    void draw();
};

class LockedWall : public  Wall {
public:
    LockedWall(float posX, float posY, float width, float height, Color _color);
    void Collision(Player& player);
};

class GeneralWall : public  Wall {//통과하지 못하는 벽
public:
    GeneralWall(float posX, float posY, float width, float height, Color _color);
    void Collision(Player& player);
};
class MovableWall : public Wall {//움직일수잇는벽 플레이어에 의해
public:
    MovableWall(float posX, float posY, float width, float height, Color _color);
    void Collision(Player& player);
    void CollisionGeneralWall(GeneralWall& generalwall, Player& player);
    void CollisionLockedWall(LockedWall& lockedwall, Player& player);
    void push(Player& player);
};

#endif