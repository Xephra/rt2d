/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include "grid.h"

/// @brief The MyEntity class is the Entity implementation.
class Player : public Entity
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	

	enum directions {
		up, down, left, right
	};

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	bool Player::checkColission(directions dir);



	Point2 lastPos;
	Point2 pos;

	Grid* grid;

	Point2 gridPos;

private:
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
