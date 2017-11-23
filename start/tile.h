/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file tile.h
*
* @brief description of MyEntity behavior.
*/

#ifndef TILE_H
#define TILE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Tile : public Entity
{
public:
	/// @brief Constructor
	Tile();
	/// @brief Destructor
	virtual ~Tile();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	bool isOccupied;
	int posX;
	int posY;
	float _WallRatio;
};

#endif /* TILE */
