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

	gridWidth = SWIDTH / 32;
	gridHeight = SHEIGHT / 32;

	createGrid();

	current = tileList[800];
	
	timer.start();
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

	

	//std::cout << gridWidth << std::endl;
	//std::cout << gridHeight << std::endl;

	

	

	
	for (int i = 0; i < gridWidth; i++)	//rows
	{
		for (int j = 0; j < gridHeight; j++) //columns
		{
			Tile* tile = new Tile(); //Instantiate tiles

			tile->scale = Point2(0.25f, 0.25f); //Set scale of the grid lower so the grid is bigger
			
			tile->position = Point2(tile->pos.x + 32 * i, tile->pos.y + 32 * j); //Position the tiles in the grid
			
			tile->addSprite("assets/bricks.tga"); //Adds sprite to the tiles, an actual tile sprite with bricks and all

			tile->sprite()->color = RGBAColor(200, 200, 200, 200); //Add a nice looking color to the tiles. In this case (200,200,255,255) I went for a nICE blue

			tile->col = j;
			tile->row = i;

			tile->tileGridPos = Point2(tile->position.x / 32 - 0.5f, tile->position.y / 32 - 0.5f); //This defines the coordinate on the grid and not in individual pixels
			
			//tile->Xcord->message(std::to_string((int)floor(tile->tileGridPos.x))); //define values to be displayed in tiles on the x coord
			//tile->Ycord->message(std::to_string((int)floor(tile->tileGridPos.y))); //define values to be displayed in tiles on the y coord
			
			tileList.push_back(tile); //Add tiles to array

			this->addChild(tile); //Add tiles to the scene

		}
	}
}



int Grid::getIndex(int x, int y)
{
	if (x < 0 && x>gridWidth - 1 && y < 0 && y>gridHeight - 1) 
	{
		//int a = (y * gridWidth) + x;
		//return a;

		return -1;
	}
	return x + y * gridWidth;
	//return -1; //index is invalid
}



void Grid::update(float deltaTime)
{
	if (timer.seconds() > 0.5f)
	{
		std::cout << "generate" << std::endl;

		current->visited = true;

		Tile* next = checkNeighbors(current);
		
		if (next != NULL) //there's an unvisited neighbor
		{
			next->sprite()->color = YELLOW;
			next->visited = true;
			current = next;
		}
		else
		{
			//backtracking here				
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

	tile->sprite()->color = RGBAColor(50,50,50,100);

	//TOP
	index = getIndex(x, y - 1);
	if (index != -1)
	{
		tileList[index]->sprite()->color = BLUE;
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//RIGHT
	index = getIndex(x + 1, y);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//BOTTOM
	index = getIndex(x, y + 1);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	//LEFT
	index = getIndex(x - 1, y);
	if (index != -1)
	{
		if (!tileList[index]->visited)
		{
			neighbors.push_back(tileList[index]);
		}
	}

	if (neighbors.size() > 0)
	{
		int r = rand() % neighbors.size();
		return neighbors[r];
	}
	return NULL;
}





























/*Tile* Grid::checkNeighbors(Tile* tile)
{
std::vector<Tile*>neighbors;
for (size_t i = 0; i < tileList.size(); i++)
{
Tile* top =		tileList[getIndex(tileList[i]->tileGridPos.x		,tileList[i]->tileGridPos.y - 1)];
Tile* right =	tileList[getIndex(tileList[i]->tileGridPos.x + 1	,tileList[i]->tileGridPos.y)];
Tile* bottom =	tileList[getIndex(tileList[i]->tileGridPos.x		,tileList[i]->tileGridPos.y + 1)];
Tile* left =	tileList[getIndex(tileList[i]->tileGridPos.x - 1	,tileList[i]->tileGridPos.y)];

if (top != NULL && !top->visited)
{
neighbors.push_back(top);
}

if (right != NULL && !right->visited)
{
neighbors.push_back(right);
}

if (bottom != NULL && !bottom->visited)
{
neighbors.push_back(bottom);
}

if (left != NULL && !left->visited)
{
neighbors.push_back(left);
}

if (neighbors.size() > 0)
{
int r = rand() % neighbors.size();
return neighbors[r];
}
return NULL;
}
}*/