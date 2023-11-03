#include "map.h"
#include <vector>
#include <iostream>
Map::Map(int _numRows, int _numColums)
{
	numRows = _numRows;
	numColumns = _numColums;
	cellSize = 50;
	width = numColumns * cellSize;
	height = numRows * cellSize;
}

void Map::MakeStage(int stage[][100], int numRows, int numColumn)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumn; column++)
		{
			map[row][column] = stage[row][column];
		}
	}
}

void Map::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			if (map[row][column] == 1) {
				DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, WHITE);
			}
			else {
				DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, YELLOW);
			}
		}
	}
}

void Map::Wall()
{
	int index = 0;
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			if (map[row][column] == 1) {
				walls[index] = Rectangle{ (float)row * cellSize, (float)row * cellSize ,(float)cellSize ,(float)cellSize };
				index++;
				std::cout << row * cellSize << " ";
			}
			else {
				DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, YELLOW);
			}
		}
	}
}
