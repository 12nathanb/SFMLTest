#include "LevelEditorState.h"

LevelEditorState::LevelEditorState(sf::RenderWindow* window) : State(window)
{
	mouseMan.init(window);

}

LevelEditorState::~LevelEditorState()
{
}

void LevelEditorState::endState()
{
	this->checkForEnd();
}

void LevelEditorState::updateKeyBinds(const float& dt)
{
	
}

void LevelEditorState::update(const float& dt)
{
	this->updateKeyBinds(dt);

	mouseMan.update(dt);

	
}

void LevelEditorState::render(sf::RenderTarget* target)
{
	this->mouseMan.draw(this->window);
}
