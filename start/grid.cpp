/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "grid.h"
#include "myentity.h"

Grid::Grid() : Entity()
{
	createGrid();
	
}



Grid::~Grid()
{

}

void Grid::createGrid() 
{
	tilePosition = Point2(32/2,32/2);
	gridWidth = SWIDTH / 32;
	gridHeight = SHEIGHT / 32;
	for (int i = 0; i < gridWidth; i++) //rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			Tile* tile = new Tile();
			tile->scale = Point(0.25f, 0.25f);
			tile->position = Point2(tilePosition.x + 32 * i, tilePosition.y + 32 * j);
			tileList.push_back(tile);
			this->addChild(tile);
		}
	}
}

void Grid::update(float deltaTime)
{
	
}
