/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "tile.h"
#include "myentity.h"

Tile::Tile() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RGBAColor(255,255,255,80);

}

Tile::~Tile()
{

}

void Tile::update(float deltaTime)
{

}
