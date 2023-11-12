#include "wall.h"

Wall::Wall(float posX, float posY, float width, float height, Color _color)
{
    position.x = posX;
    position.y = posY;
    size.x = width;
    size.y = height;
    color = _color;
}

void Wall::draw()
{
    DrawRectangleV(position, size, color);
}

LockedWall::LockedWall(float posX, float posY, float width, float height, Color _color) : Wall(posX, posY, width, height, _color)
{

}

void LockedWall::Collision(Player& player)
{
    if (player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2 &&
        keycheck == 1) {
        keycheck--;
        keyused++;
        color = { 0,0,0,0 };
    }
    else if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        float new_x_1 = player.position.x - position.x + player.size.x / 2;
        float new_x_2 = position.x + size.x - player.position.x + player.size.x / 2;
        float new_y_1 = player.position.y - position.y + player.size.y / 2;
        float new_y_2 = position.y + size.y - player.position.y + player.size.y / 2;


        if (player.position.x < position.x + size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                player.position.x -= new_x_1;
            }
        }
        else if (player.position.x > position.x + size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                player.position.x += new_x_2;
            }
        }

        if (player.position.y < position.y + size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                player.position.y -= new_y_1;
            }
        }
        else if (player.position.y > position.y + size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                player.position.y += new_y_2;
            }
        }

    }
}

GeneralWall::GeneralWall(float posX, float posY, float width, float height, Color _color) : Wall(posX, posY, width, height, _color)
{
}

void GeneralWall::Collision(Player& player)
{
    if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        float new_x_1 = player.position.x - position.x + player.size.x / 2;
        float new_x_2 = position.x + size.x - player.position.x + player.size.x / 2;
        float new_y_1 = player.position.y - position.y + player.size.y / 2;
        float new_y_2 = position.y + size.y - player.position.y + player.size.y / 2;


        if (player.position.x < position.x + size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                player.position.x -= new_x_1;
            }
        }
        else if (player.position.x > position.x + size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                player.position.x += new_x_2;
            }
        }

        if (player.position.y < position.y + size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                player.position.y -= new_y_1;
            }
        }
        else if (player.position.y > position.y + size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                player.position.y += new_y_2;
            }
        }

    }
}

MovableWall::MovableWall(float posX, float posY, float width, float height, Color _color) : Wall(posX, posY, width, height, _color)
{

}

void MovableWall::Collision(Player& player)
{
    if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        float new_x_1 = player.position.x - position.x + player.size.x / 2;
        float new_x_2 = position.x + size.x - player.position.x + player.size.x / 2;
        float new_y_1 = player.position.y - position.y + player.size.y / 2;
        float new_y_2 = position.y + size.y - player.position.y + player.size.y / 2;


        if (player.position.x < position.x + size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                player.position.x -= new_x_1;
            }
        }
        else if (player.position.x > position.x + size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                player.position.x += new_x_2;
            }
        }

        if (player.position.y < position.y + size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                player.position.y -= new_y_1;
            }
        }
        else if (player.position.y > position.y + size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                player.position.y += new_y_2;
            }
        }

    }
}

void MovableWall::CollisionGeneralWall(GeneralWall& generalwall, Player& player)
{
    if (
        position.x >= generalwall.position.x - size.x &&
        position.x <= generalwall.position.x + generalwall.size.x &&
        position.y >= generalwall.position.y - size.y &&
        position.y <= generalwall.position.y + generalwall.size.y
        )
    {
        float new_x_1 = position.x - generalwall.position.x + size.x;
        float new_x_2 = generalwall.position.x + generalwall.size.x - position.x;
        float new_y_1 = position.y - generalwall.position.y + size.y;
        float new_y_2 = generalwall.position.y + generalwall.size.y - position.y;


        if (position.x < generalwall.position.x + generalwall.size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                position.x -= new_x_1;
                Collision(player);

            }
        }
        else if (position.x > generalwall.position.x + generalwall.size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                position.x += new_x_2;
                Collision(player);

            }
        }

        if (position.y < generalwall.position.y + generalwall.size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                position.y -= new_y_1;
                Collision(player);

            }
        }
        else if (position.y > generalwall.position.y + generalwall.size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                position.y += new_y_2;
                Collision(player);

            }
        }

    }
}

void MovableWall::CollisionLockedWall(LockedWall& lockedwall, Player& player)
{
    if (
        position.x >= lockedwall.position.x - size.x &&
        position.x <= lockedwall.position.x + lockedwall.size.x &&
        position.y >= lockedwall.position.y - size.y &&
        position.y <= lockedwall.position.y + lockedwall.size.y
        )
    {
        float new_x_1 = position.x - lockedwall.position.x + size.x;
        float new_x_2 = lockedwall.position.x + lockedwall.size.x - position.x;
        float new_y_1 = position.y - lockedwall.position.y + size.y;
        float new_y_2 = lockedwall.position.y + lockedwall.size.y - position.y;


        if (position.x < lockedwall.position.x + lockedwall.size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                position.x -= new_x_1;
                Collision(player);

            }
        }
        else if (position.x > lockedwall.position.x + lockedwall.size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                position.x += new_x_2;
                Collision(player);

            }
        }

        if (position.y < lockedwall.position.y + lockedwall.size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                position.y -= new_y_1;
                Collision(player);

            }
        }
        else if (position.y > lockedwall.position.y + lockedwall.size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                position.y += new_y_2;
                Collision(player);

            }
        }
    }
}

void MovableWall::push(Player& player)
{
    if (
        player.position.x >= position.x - player.size.x / 2 &&
        player.position.x <= position.x + size.x + player.size.x / 2 &&
        player.position.y >= position.y - player.size.y / 2 &&
        player.position.y <= position.y + size.y + player.size.y / 2
        )
    {
        float new_x_1 = player.position.x - position.x + player.size.x / 2;
        float new_x_2 = position.x + size.x - player.position.x + player.size.x / 2;
        float new_y_1 = player.position.y - position.y + player.size.y / 2;
        float new_y_2 = position.y + size.y - player.position.y + player.size.y / 2;


        if (player.position.x < position.x + size.x / 2) {
            if (new_x_1 < new_y_1 && new_x_1 < new_y_2) {
                position.x += new_x_1;
            }
        }
        else if (player.position.x > position.x + size.x / 2) {
            if (new_x_2 < new_y_1 && new_x_2 < new_y_2) {
                position.x -= new_x_2;
            }
        }

        if (player.position.y < position.y + size.y / 2) {
            if (new_y_1 < new_x_1 && new_y_1 < new_x_2) {
                position.y += new_y_1;
            }
        }
        else if (player.position.y > position.y + size.y / 2) {
            if (new_y_2 < new_x_1 && new_y_2 < new_x_2) {
                position.y -= new_y_2;
            }
        }

    }
    //맵벽밖으로 이동할때 플레이어 못 움직이게함
    if (position.x <= 0) {
        position.x = 0;
        Collision(player);
    }
    else if (position.x >= map_width - size.x) {
        position.x = map_width - size.x;
        Collision(player);
    }

    if (position.y <= 0) {
        position.y = 0;
        Collision(player);
    }
    else if (position.y >= map_height - size.y) {
        position.y = map_height - size.y;
        Collision(player);
    }
}
