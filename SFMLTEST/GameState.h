#pragma once

#include "State.h"
#include "Player.h"
#include "Ground.h"

class GameState : 
	public State
{
private:
	Player player;
	Ground ground;
	
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	
	void endState();

	void updateCollision(const float& dt);
	void updateKeyBinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);


};

