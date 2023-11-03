#ifndef MAP_H

#define MAP_H
#include <raylib.h>

class Map
{
public:
    Map(int _numRows, int _numColums);
    void MakeStage(int stage[][100], int numRows, int numColumn);
    void Draw();
    void Wall();
    Rectangle walls[10000];
    int map[100][100];
    int width;
    int height;
private:
    int numRows;
    int numColumns;
    int cellSize;
};

#endif