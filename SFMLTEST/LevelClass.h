#pragma once
#include "Ground.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <iterator>

class LevelClass
{
private:
	int floorAmount = 5;
	std::vector<Ground> levelFloor;
	
public:
	LevelClass();
	~LevelClass();

	void initLevel(sf::RenderWindow* window);
	void updateLevel(const float& dt);
	bool updateCollision(const float& dt, Player& player);
	void renderLevel(sf::RenderTarget* target);
};

