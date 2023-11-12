#include "tile.h"

Tile::Tile(float posX, float posY, float width, float height, Color _color)
{
    position.x = posX;
    position.y = posY;
    size.x = width;
    size.y = height;
    color = _color;
}

void Tile::draw()
{
    DrawRectangleV(position, size, color);
}

SavePoint::SavePoint(float posX, float posY, float width, float height, Color _color) : Tile(posX, posY, width, height, _color)
{

}

void SavePoint::save(Player& player)
{
    if (
        player.position.x > position.x - player.size.x / 2 &&
        player.position.x < position.x + size.x + player.size.x / 2 &&
        player.position.y > position.y - player.size.y / 2 &&
        player.position.y < position.y + size.y + player.size.y / 2 &&
        savecheck < 1
        )
    {
        savecheck++;
    }
}

SpeedUpTile::SpeedUpTile(float posX, float posY, float width, float height, Color _color) : Tile(posX, posY, width, height, _color)
{
}

void SpeedUpTile::SpeedUp(Player& player)
{
    if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        direction = 2;
    }
}

SpeedDownTile::SpeedDownTile(float posX, float posY, float width, float height, Color _color) : Tile(posX, posY, width, height, _color)
{

}

void SpeedDownTile::SpeedDown(Player& player)
{
    if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        direction = 0.1;
    }
}

Portal::Portal(float posX, float posY, float width, float height, Color _color) : Tile(posX, posY, width, height, _color)
{

}

bool Portal::Check(Player& player)
{
    if (
        player.position.x > position.x - player.size.x / 2 &&
        player.position.x < position.x + size.x + player.size.x / 2 &&
        player.position.y > position.y - player.size.y / 2 &&
        player.position.y < position.y + size.y + player.size.y / 2
        )
    {
        return true;
    }
    return false;
}

void PressureGate::draw()
{
    if (!isActivated) {
        DrawRectangleV(position, size, color);
    }
}

bool PressureGate::checkActivation(Player& player)
{
    if (!isActivated &&
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2) {
        isActivated = true;
        return true;
    }
    return false;
}
