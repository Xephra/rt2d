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
	pos = Point2(32 / 2, 32 / 2);
	Grid grid;
	int fastWalkTimer = 0;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	std::cout << lastPos << std::endl;
	//Synchronising player position with position on grid
	this->position = Point2(pos.x, pos.y);

	gridPos = Point2(pos.x / 32 - 0.5f, pos.y / 32 - 0.5f);

	// Fast walk implementation
	if (input()->getKey(KeyCode::W) && fastWalkTimer > 0 &&
		fastWalkTimer < 5 && fastWalkTimer == true)
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		
		fastWalkTimer = 5;
		this->pos.y -= 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}

	if (input()->getKey(KeyCode::A) && fastWalkTimer > 0 &&
		fastWalkTimer < 5 && fastWalkTimer == true)
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 5;
		this->pos.x -= 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}
	
	if (input()->getKey(KeyCode::S) && fastWalkTimer > 0 &&
		fastWalkTimer < 5 && fastWalkTimer == true)
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 5;
		this->pos.y += 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}

	if (input()->getKey(KeyCode::D) && fastWalkTimer > 0 &&
		fastWalkTimer < 5 && fastWalkTimer == true)
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 5;
		this->pos.x += 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}

	//Slow movement
	if (input()->getKeyDown(KeyCode::W))
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 10;
		fastWalkToggle = true;
		this->pos.y -= 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}
	
	if (input()->getKeyDown(KeyCode::A))
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 10;
		fastWalkToggle = true;
		this->pos.x -= 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}
	
	if (input()->getKeyDown(KeyCode::S))
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 10;
		fastWalkToggle = true;
		this->pos.y += 32;
		
		if (gridPos.x == 15 && gridPos.y ==	20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}

	}

	if (input()->getKeyDown(KeyCode::D))
	{
		lastPos = Point2(gridPos.x, gridPos.y);
		fastWalkTimer = 10;
		fastWalkToggle = true;
		this->pos.x += 32;

		if (gridPos.x == 15 && gridPos.y == 20)
		{
			this->gridPos.x = lastPos.x;
			this->gridPos.y = lastPos.y;
		}
	}


	//Fastwalk counters and trackers
	if (fastWalkTimer > 0) {
		fastWalkTimer -= 1;
	}
	if (fastWalkTimer > 10){
		fastWalkToggle = false;
	}

	//Border Implementation (hard coded)
	if (pos.x / 32 - 0.5f < 0) 
	{
		pos.x + 1;
		this->pos.x += 32;
	}
	if (pos.x / 32 - 0.5f > 39) 
	{
		pos.x - 1;
		this->pos.x -= 32;
	}

	if (pos.y / 32 - 0.5f < 0)
	{
		pos.y + 1;
		this->pos.y += 32;
	}
	if (pos.y / 32 - 0.5f > 21)
	{
		pos.y - 1;
		this->pos.y -= 32;
	}
	//std::cout << fastWalkTimer << std::endl;
}
