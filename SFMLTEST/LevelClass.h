#pragma once
#include "Ground.h"
#include "Player.h"
#include "DrawInk.h"
#include <iostream>
#include <fstream>
#include <iterator>

struct datas
{
	float x;
	float y;
	std::string name;
};

class LevelClass
{
private:
	int floorAmount = 0;
	std::vector<std::string> split(std::string str, char delimiter);
	std::vector<DrawInk> levelFloor;
	sf::Vector2f spawnVec;

public:
	LevelClass();
	~LevelClass();

	void initLevel(sf::RenderWindow* window);
	void updateLevel(const float& dt);
	bool updateCollision(const float& dt, Player& player);
	void renderLevel(sf::RenderTarget* target);
	sf::Vector2f getSpawn() { return spawnVec; }
};

