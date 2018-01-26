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
	gridStepX = 32;
	gridStepY = 32;

	//gridWidth = 40;
	//gridHeight = 22;

	gridWidth = 40;
	gridHeight = 22;



	ladderPosition = Point2(0, 0);

	isGenerating = true;
	timer.start();

	isGenerating = true;
	if (isGenerating == true)
	{
		create();
		current = tileList[400];
	}



	//std::cout << &isGenerating << std::endl;
}



Grid::~Grid()
{
	clean();
}

void Grid::create()
{
	time_t t = time(0); //get time now
	struct tm * now = localtime(&t);
	std::srand(now->tm_sec*now->tm_min);

	unsigned int random1 = rand() % 100 + 1;

	//std::cout << gridWidth << std::endl;
	//std::cout << gridHeight << std::endl;






	for (int i = 0; i < gridWidth; i++)	//rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			ladder = nullptr;

			Tile* tile = new Tile(); //Instantiate tiles

			tile->scale = Point2(0.25f, 0.25f); //Set scale of the grid lower so the grid is bigger

			tile->position = Point2(tile->pos.x + 32 * i, tile->pos.y + 32 * j); //Position the tiles in the grid

			tile->addSprite("assets/bricks.tga"); //Adds sprite to the tiles, an actual tile sprite with bricks and all

			tile->sprite()->color = GRAY; //Add a nice looking color to the tiles. In this case (200,200,255,255) I went for a nICE blue

			tile->row = i;
			tile->col = j;

			tile->tileGridPos = Point2(tile->position.x / 32 - 0.5f, tile->position.y / 32 - 0.5f); //This defines the coordinate on the grid and not in individual pixels

																									//tile->Xcord->message(std::to_string((int)floor(tile->tileGridPos.x))); //define values to be displayed in tiles on the x coord
																									//tile->Ycord->message(std::to_string((int)floor(tile->tileGridPos.y))); //define values to be displayed in tiles on the y coord

			tileList.push_back(tile); //Add tiles to array

			this->addChild(tile); //Add tiles to the scene
		}
	}
}



int Grid::getIndex(int x, int y, int w, int h) {
	if (x >= 0 && x<w && y >= 0 && y<h) {
		int i = (y * w) + x;
		return i;
	}
	return -1;
}



void Grid::update(float deltaTime)
{


	if (timer.seconds() > 0.00001)
	{
		if (isGenerating == true)
		{

			std::cout << isGenerating << std::endl;

			if (current != nullptr)
			{
				current->visited = true;
				Tile* next = checkNeighbors(current);



				if (next != NULL) //there's an unvisited neighbor
				{
					next->sprite()->color = BLUE;
					next->visited = true;
					current = next;
				}
				else
				{
					isGenerating = false;
					//current->isLadder = true;
					ladderPosition = current->position;
					current->sprite()->color = BLUE;
					current->addSprite("assets/ladder.tga");
					//current->addSprite("assets/player.tga");
					current = ladder;



				}
			}
		}
		timer.start(); //starting timer again resets it to 0

	}
}

Tile* Grid::checkNeighbors(Tile* tile)
{
	std::vector<Tile*>neighbors;
	int x = tile->col;
	int y = tile->row;

	//std::cout << "column is " << tile->col << std::endl;
	//std::cout << "row is " << tile->row << std::endl;

	int index = 0;

	//tile->sprite()->color = RGBAColor(50,50,50,100);

	//TOP
	index = getIndex(x, y - 1, gridHeight, gridWidth);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//RIGHT
	index = getIndex(x + 1, y, gridHeight, gridWidth);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//BOTTOM
	index = getIndex(x, y + 1, gridHeight, gridWidth);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//LEFT
	index = getIndex(x - 1, y, gridHeight, gridWidth);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	if (neighbors.size() > 0)
	{
		tile->sprite()->color = BLACK;
		int e = rand() % 100;
		if (e > 99)
		{
			tile->sprite()->color = YELLOW;
		}

		int r = rand() % neighbors.size();
		return neighbors[r];
	}
	return nullptr;
}

void Grid::reset()
{
	clean();
	create();
}

void Grid::clean()
{
	for (int i = 0; i < gridWidth; i++)	//rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			ladder = nullptr;
			current = nullptr;
			//this->removeChild(tileList[i]);
			//delete tileList[i];

		}
	}
}