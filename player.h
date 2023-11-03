#ifndef PLAYER_H

#define PLAYER_H
#include <raylib.h>
class Player
{
public:
	Player(float x, float y);
	void Draw();
	void Move();
	Vector2 position;
	Rectangle player;
	int size;
private:

};

#endif