#include "player.h"
#include "map.h"
#include <iostream>
Player::Player(float x, float y)
{
	size = 50;
	player = { x / 2.0f-size/2.0f, y / 2.0f-size/2.0f,(float)size,(float)size };
	position = { x / 2.0f, y / 2.0f };
}

void Player::Draw()
{
	DrawRectangleRec(player,RED);
	DrawRectangle(position.x - size / 2, position.y - size / 2, size, size, RED);
}

void Player::Move()
{
	

	if (IsKeyDown(KEY_UP))
	{
		this->position.y -= 5;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		this->position.y += 5;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		this->position.x += 5;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		this->position.x -= 5;
	}
}
