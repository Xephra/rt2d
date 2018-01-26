/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file tile.h
*
* @brief description of tile behavior.
*/

#ifndef TILE_H
#define TILE_H

#include <rt2d/entity.h>
#include <rt2d/text.h>
#include <stdlib.h>
#include <time.h>

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

	bool visited;


	Point2 pos;

	int col;
	int row;

	Point2 tileGridPos;

	//bool hasWalls[4];

	Text* Xcord;
	Text* Ycord;

private:

	int random1;

	float textSize;

	//RGBAColor currentColor;
};

#endif /* TILE */
