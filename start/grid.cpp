/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "grid.h"
#include "myentity.h"
#include <bitset>


Grid::Grid() : Entity()
{
	createGrid();
	createMaze();

	//Testing bitsets, remove when done!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	std::bitset<4> bitset1;
	std::cout << bitset1 << std::endl;

	for (int i = 0; i<bitset1.size(); i++)
	{
		if (bitset1.test(i)) {
			std::cout << "bit" << i << "is set" << std::endl;
		}
		else
		{
			std::cout << "bit" << i << "is not set" << std::endl;
		}
	}
	//End testing bitsets!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}



Grid::~Grid()
{

}

void Grid::createGrid() 
{
	time_t t = time(0); //get time now
	struct tm * now = localtime(&t);

	std::srand(now->tm_sec*now->tm_min);

	unsigned int random1 = rand() % 100 + 1;

	gridWidth = SWIDTH / 32;
	gridHeight = SHEIGHT / 32;

	std::cout << gridWidth << std::endl;
	std::cout << gridHeight << std::endl;

	gridStepX = 32;
	gridStepY = 32;



	
	for (int i = 0; i < gridWidth; i++)	//rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			Tile* tile = new Tile(); //Instantiate tiles
			
			tile->scale = Point(0.25f, 0.25f); //Set scale of the grid lower so the grid is bigger
			
			tile->position = Point2(tile->pos.x + 32 * i, tile->pos.y + 32 * j); //Position the tiles in the grid
			
			tile->addSprite("assets/wall.tga"); //Adds sprite to the tiles, an actual tile sprite with bricks and all

			tile->tileGridPos = Point2(tile->position.x / 32 - 0.5f, tile->position.y / 32 - 0.5f); //This defines the coordinate on the grid and not in individual pixels

			tile->sprite()->color = RGBAColor(200, 200, 255, 255); //Add a nice looking color to the tiles. In this case (200,200,255,255) I went for a nICE blue
			
			tile->Xcord->message(std::to_string((int)floor(tile->tileGridPos.x))); //define values to be displayed in tiles on the x coord
			tile->Ycord->message(std::to_string((int)floor(tile->tileGridPos.y))); //define values to be displayed in tiles on the y coord

			tile->isWall = false; //Every tile is set to wall, so a maze can be carved out later.
						
			tileList.push_back(tile); //Add tiles to array

			this->addChild(tile); //Add tiles to the scene

			if (tile->tileGridPos == Point2(1, 1)) {
				tile->sprite()->color = BLUE;
			}
		}
	}
}

void Grid::update(float deltaTime)
{
	
}
void Grid::createMaze()
{

}
