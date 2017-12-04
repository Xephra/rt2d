/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "tile.h"
#include "myentity.h"

Tile::Tile() : Entity()
{
	unsigned int random1 = rand() % 255 + 1;
	unsigned int random2 = rand() % 255 + 1;
	unsigned int random3 = rand() % 255 + 1;
	
	this->addSprite("assets/wall.tga");
	
	if (random2 > 30) {
		this->sprite()->color = RGBAColor(0, 0, 255, 255);
	}
	else 
	{
		isWall = true;
		this->sprite()->color = RGBAColor(255, 255, 255, 255);
	}
	

	this->pos = Point2(16, 16);
	
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
	srand((unsigned)time(NULL));

}
