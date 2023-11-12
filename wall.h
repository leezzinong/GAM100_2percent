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

class GeneralWall : public  Wall {//������� ���ϴ� ��
public:
    GeneralWall(float posX, float posY, float width, float height, Color _color);
    void Collision(Player& player);
};
class MovableWall : public Wall {//�����ϼ��մº� �÷��̾ ����
public:
    MovableWall(float posX, float posY, float width, float height, Color _color);
    void Collision(Player& player);
    void CollisionGeneralWall(GeneralWall& generalwall, Player& player);
    void CollisionLockedWall(LockedWall& lockedwall, Player& player);
    void push(Player& player);
};

#endif