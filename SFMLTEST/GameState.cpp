#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
	level1.initLevel(window);
}

GameState::~GameState()
{
}

void GameState::endState()
{
	//std::cout << "Ending game";
}




void GameState::updateKeyBinds(const float& dt)
{
	this->checkForEnd();
}

void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);
	//this->updateCollision(dt);

	if (level1.updateCollision(dt, player) == false)
	{
		player.isPlayerFalling(true);
		
	}
	else
	{
		player.isPlayerFalling(false);
	}
	this->player.update(dt);
	
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);

	this->level1.renderLevel(this->window);
	
}
