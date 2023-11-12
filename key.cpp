#include "key.h"


int keycheck = 0;
int keyused = 0;

Key::Key(float posX, float posY, float width, float height, Color _color)
{
    position.x = posX;
    position.y = posY;
    size.x = width;
    size.y = height;
    color = _color;
}

void Key::draw()
{
    DrawRectangleV(position, size, color);
}

void Key::get(Player& player)
{
    if (
        player.position.x > position.x - player.size.x / 2 &&
        player.position.x < position.x + size.x + player.size.x / 2 &&
        player.position.y > position.y - player.size.y / 2 &&
        player.position.y < position.y + size.y + player.size.y / 2
        )
    {
        keycheck++;
        color = { 0,0,0,0 };
    }
}
