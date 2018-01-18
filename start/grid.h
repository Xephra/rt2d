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
#include <rt2d/timer.h>
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

	int getIndex(int x, int y);


	std::vector<Tile*>tileList;
	//Tile* next;	   //The tile that the maze algorithm will be working on next, in a random direction (see "checkNeighbors")
	Tile* current; // The tile that the maze algorithm is currently working on

	int unvisitedNeighbors;

	int gridStepX;
	int gridStepY;
	
	//Tile* tileList [1][1];

	
	
	Tile* checkNeighbors(Tile* tile);

	//int random1;


	Timer timer;
private:
	/* add your private declarations */


	int gridWidth;
	int gridHeight;

	//#define nulL nullptr
};

#endif /* GRID_H */
