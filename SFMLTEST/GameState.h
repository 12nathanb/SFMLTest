#pragma once

#include "State.h"
#include "Player.h"
class GameState : 
	public State
{
private:
	Player player;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	void endState();

	void updateKeyBinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);


};

