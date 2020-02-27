#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
	this->ground.initGround(window,50, 300,0,0);
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending game";
}


void GameState::updateCollision(const float& dt)
{
		if (this->player.getShape().getGlobalBounds().intersects(this->ground.getShape().getGlobalBounds()))
		{
			this->player.isPlayerFalling(false);
			this->player.setGroundHeight(this->ground.getShape().getSize().y);
		}
		else
		{
			this->player.isPlayerFalling(true);
		}	
}

void GameState::updateKeyBinds(const float& dt)
{
	this->checkForEnd();
}

void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);
	this->updateCollision(dt);
	this->player.update(dt);
	
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);

	
		this->ground.render(this->window);
	
}
