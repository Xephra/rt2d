/**
 * This class describes Player behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"
#include "myentity.h"
#include "grid.h"


Player::Player() : Entity()
{
	this->addSprite("assets/player.tga");
	this->sprite()->color = RGBAColor(255, 255, 255, 255); //white
	pos = Point2(96 / 2, 96 / 2);
	Grid grid;
	int fastWalkTimer = 0;
	tileStep = 32;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	//Synchronising player position with position on grid
	this->position = Point2(pos.x, pos.y);

	gridPos = Point2(pos.x / 32 - 0.5f, pos.y / 32 - 0.5f);

	//Slow movement
	if (input()->getKeyDown(KeyCode::S))
	{
		this->pos.y += tileStep;
	}
	
	else if (input()->getKeyDown(KeyCode::D))
	{

		this->pos.x += tileStep;
	}
	
	else if (input()->getKeyDown(KeyCode::W))
	{
		this->pos.y -= tileStep;
	}

	else if (input()->getKeyDown(KeyCode::A))
	{
		this->pos.x -= tileStep;
	}
}