#include "player.h"

Player::Player(float posX, float posY, float width, float height, Color _color)
{
    position.x = posX;
    position.y = posY;
    size.x = width;
    size.y = height;
    color = _color;
}

void Player::draw()
{
    //draw player
    DrawRectangleV({ position.x - size.x / 2.0f, position.y - size.y / 2.0f }, size, color);
}

void Player::move()
{
    if (IsKeyDown(KEY_UP))position.y -= direction * speed;
    if (IsKeyDown(KEY_DOWN))position.y += direction * speed;
    if (IsKeyDown(KEY_RIGHT))position.x += direction * speed;
    if (IsKeyDown(KEY_LEFT))position.x -= direction * speed;
}
