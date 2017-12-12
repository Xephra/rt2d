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
	
	Sound* sound = new Sound("assets/pyramidsong_s16.wav");
	sound->loop(true);
	sound->gain(0.5f);
	sound->play();



	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	
	////myentity = new MyEntity();
	grid = new Grid();
	player = new Player();
	text = new Text();



	player->grid = grid;
	text->position = Point2(10, 713);
	text->scale = Point2(0.25f, 0.25f);

	player->scale = Point(0.25f, 0.25f);
	grid->position = Point2(0, 0);
	////myentity->position = Point2(SWIDTH/2,SHEIGHT/2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	////this->addChild(myentity);
	this->addChild(grid);
	this->addChild(player);	
	this->addChild(text);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	
	////this->removeChild(myentity);
	
	this->removeChild(player);
	this->removeChild(grid);

	// delete myentity from the heap (there was a 'new' in the constructor)
	////delete myentity;
	delete player;
	delete grid;
}

void MyScene::update(float deltaTime)
{	
	playerPos = player->pos;
	text->message("Player position | x: " + std::to_string(playerPos.x/32 - 0.5f) +"  | y: "+ std::to_string(playerPos.y / 32 - 0.5f));

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
