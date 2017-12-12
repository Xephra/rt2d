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
	//Synchronising player position with position on grid
	this->position = Point2(pos.x, pos.y);


	gridPos = Point2(pos.x / 32 - 0.5f, pos.y / 32 - 0.5f);

	//Slow movement
	if (input()->getKeyDown(KeyCode::S))
	{
		if (!checkColission(down)) 
		{
			this->pos.y += 32;
		}
	}
	
	if (input()->getKeyDown(KeyCode::D))
	{
		if (!checkColission(right)) 
		{
			this->pos.x += 32;
		}
	}
	
	if (input()->getKeyDown(KeyCode::W))
	{
		if (!checkColission(up))
		{
			this->pos.y -= 32;
		}
	}

	if (input()->getKeyDown(KeyCode::A))
	{
		if (!checkColission(left))
		{
			this->pos.x -= 32;
		}
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
	//std::cout << lastPos << std::endl;
}


bool Player::checkColission(directions dir) 
{
	int xoffset = 0;
	int yoffset = 0;

	switch (dir)
	{
	case Player::up:
		yoffset = -32;
		break;
	case Player::down:
		yoffset = 32;
		break;
	case Player::left:
		xoffset = -32;
		break;
	case Player::right:
		xoffset = 32;
		break;
	default:
		break;
	}
	
	//Collision implementation
	for (size_t i = 0; i < grid->tileList.size(); i++)
	{
		if (grid->tileList[i]->isWall &&
			(this->position.x + xoffset) == grid->tileList[i]->position.x &&
			(this->position.y + yoffset) == grid->tileList[i]->position.y)
		{
			return true;
		}
		
	}
	//End of collision implementation
	return false;
}