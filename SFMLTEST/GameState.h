#pragma once

#include "State.h"
#include "Player.h"
#include "LevelClass.h"
#include "MouseDrawer.h"

class GameState : 
	public State
{
private:
	Player player;
	LevelClass level1;

private:
	void generateLevel();
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	
	void endState();

	void updateKeyBinds(const float& dt);
	void update(const float& dt, sf::RenderWindow* window);
	void render(sf::RenderTarget* target = NULL);


};

