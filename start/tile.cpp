/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "tile.h"
#include "myentity.h"


Tile::Tile() : Entity()
{
	this->pos = Point2(16, 16);

	visited = false;

	col = 0;
	row = 0;

	textSize = 0.75f;

	this->position = Point2(pos.x, pos.y);

	Xcord = new Text();
	Ycord = new Text();

	Xcord->position = Point2(0, -20);
	Xcord->scale = Point2(textSize, textSize);
	Ycord->position = Point2(0, 20);
	Ycord->scale = Point2(textSize, textSize);
	
	this->addChild(Xcord);
	this->addChild(Ycord);

	targetTime = -0.4; //0.238*12;
	beatInterval = 0;
}

Tile::~Tile()
{
	this->removeChild(Xcord);
	this->removeChild(Ycord);

	delete Xcord;
	delete Ycord;
}

void Tile::update(float deltaTime)
{
	/*targetTime -= deltaTime;
	if (targetTime < 0) 
	{
		//this->sprite()->color.r -= 100;

		this->sprite()->color = WHITE;
		//beatInterval += 1;
		targetTime = 0.238*2;
	}
	/*else  if(beatInterval > 4) 
	{
		targetTime = 0.238 / 2;
		beatInterval = 0;
	} 
	else
	{
		this->sprite()->color = BLACK;
		//this->sprite()->color.r += 100;
	}*/
}
