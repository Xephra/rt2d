/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	Audio::init();
	
	Sound* sound = new Sound("assets/treasure.wav");

	sound->loop(true);
	sound->gain(1.0f);
	sound->pitch(1.0f);
	//sound->play();

	////myentity = new MyEntity();
	grid = new Grid();
	//player = new Player();___________________________________________
	text = new Text();

	//player->grid = grid;_________________________________________
	text->position = Point2(10, 713);
	text->scale = Point2(0.25f, 0.25f);

	//player->scale = Point(0.25f, 0.25f);____________________________________
	grid->position = Point2(0, 0);

	this->addChild(grid);
	//this->addChild(player);___________________________________________	
	this->addChild(text);
}


MyScene::~MyScene()
{	
	//this->removeChild(player);___________________________________________	
	
	this->removeChild(grid);

	//delete player;___________________________________________	
	
	delete grid;
}

void MyScene::update(float deltaTime)
{	
	//playerPos = player->pos;
	//text->message("Player position | x: " + std::to_string(playerPos.x/32 - 0.5f) +"  | y: "+ std::to_string(playerPos.y / 32 - 0.5f));

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
