/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file grid.h
*
* @brief description of MyEntity behavior.
*/

#ifndef GRID_H
#define GRID_H

#include <rt2d/entity.h>
#include <rt2d/text.h>
#include "tile.h"

/// @brief The MyEntity class is the Entity implementation.
class Grid : public Entity
{
public:
	/// @brief Constructor
	Grid();
	/// @brief Destructor
	virtual ~Grid();

	/// @brief createGrid makes a grid
	/// @return void
	virtual void createGrid();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	int gridStepX;
	int gridStepY;
	
	bool occupied;
private:
	/* add your private declarations */
	std::vector<Tile*>tileList;
	int gridWidth;
	int gridHeight;

};

#endif /* GRID_H */
