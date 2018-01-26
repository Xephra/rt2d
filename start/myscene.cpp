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

	//myentity = new MyEntity();
	grid = new Grid();
	player = new Player();
	text = new Text();
	floorCounter = new Text();

	player->grid = grid;

	floorCounter->position = Point2(700, 713);
	floorCounter->scale = Point2(0.25f, 0.25f);

	currentFloor = 1;


	text->position = Point2(10, 713);
	text->scale = Point2(0.25f, 0.25f);


	player->scale = Point(0.25f, 0.25f);
	grid->position = Point2(0, 0);

	player->pos = grid->tileList[400]->position;

	this->addChild(grid);
	this->addChild(player);
	this->addChild(text);
	this->addChild(floorCounter);
}


MyScene::~MyScene()
{
	this->removeChild(player);
	this->removeChild(grid);
	this->removeChild(text);
	this->removeChild(floorCounter);

	delete player;

	delete floorCounter;
	delete grid;
}

void MyScene::update(float deltaTime)
{

	playerPos = player->pos;
	text->message("Player position | x: " + std::to_string(playerPos.x / 32 - 0.5f) + "  | y: " + std::to_string(playerPos.y / 32 - 0.5f));
	floorCounter->message("Current floor: " + std::to_string(currentFloor));
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	if (input()->getKeyUp(KeyCode::Space))
	{
		cleanGrid();
		makeGrid();
		currentFloor++;

	}
	/*if (player != nullptr && grid != nullptr && player->position == grid->ladder->position)
	{
	std::cout << " appel laaaa " << std::endl;
	}*/
}

void MyScene::cleanGrid()
{
	grid->clean();
	this->removeChild(grid);
	delete grid;
}

void MyScene::makeGrid()
{
	//myentity = new MyEntity();
	grid = new Grid();

	player->grid = grid;

	grid->position = Point2(0, 0);

	player->pos = grid->tileList[400]->position;

	this->addChild(grid);

	//grid->create();
}