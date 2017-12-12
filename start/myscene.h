/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include "audio/audio.h"
#include "audio/sound.h"

#include <rt2d/scene.h>
#include "grid.h"
#include "player.h"
#include "text.h"


#include "myentity.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	//MyEntity* myentity;
	Player* player;
	Grid* grid;
	Text* text;

	Sound* sound;

	Point2 playerPos;
	/// @brief a Timer to rotate the color every n seconds
};

#endif /* SCENE00_H */
