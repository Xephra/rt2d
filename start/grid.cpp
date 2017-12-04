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
	gridWidth = SWIDTH / 32;
	gridHeight = SHEIGHT / 32;


	gridStepX = 32;
	gridStepY = 32;



	
	for (int i = 0; i < gridWidth; i++) //rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			//Instantiate tiles
			Tile* tile = new Tile();
			tile->scale = Point(0.25f, 0.25f);
			tile->position = Point2(tile->pos.x + 32 * i, tile->pos.y + 32 * j);

			//define values to be displayed in tiles (in this case, the coordinates in the grid)
			//tile->Xcord->message(std::to_string((int)floor(tile->position.x / 32 - 0.5f)));
			//tile->Ycord->message(std::to_string((int)floor(tile->position.y / 32 - 0.5f)));

			//Add tiles to array
			tileList.push_back(tile);

			//Add tiles to the scene
			this->addChild(tile);

		}
	}
}

void Grid::update(float deltaTime)
{
//dosomething a whole lot
}
