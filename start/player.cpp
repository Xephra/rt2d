/**
 * This class describes Player behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"
#include "myentity.h"

Player::Player() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RGBAColor(255,255,255,255); //white
	pos = Point2(32 / 2, 32 / 2);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	
	this->position = Point2(pos.x, pos.y);

	if (input()->getKeyDown(KeyCode::W)) {
		this->pos.y -= 32;
	}
	if (input()->getKeyDown(KeyCode::A)) {
		this->pos.x -= 32;
	}	
	if (input()->getKeyDown(KeyCode::S)) {
		this->pos.y += 32;
	}	
	if (input()->getKeyDown(KeyCode::D)) {
		this->pos.x += 32;
	}
}
