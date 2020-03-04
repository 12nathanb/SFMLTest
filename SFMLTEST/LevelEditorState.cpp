#include "LevelEditorState.h"

LevelEditorState::LevelEditorState(sf::RenderWindow* window) : State(window)
{
	mouseMan.init(window);

}

LevelEditorState::~LevelEditorState()
{
	mouseMan.generateXML();
}

void LevelEditorState::endState()
{
	this->checkForEnd();
}

void LevelEditorState::updateKeyBinds(const float& dt)
{
	
}

void LevelEditorState::update(const float& dt, sf::RenderWindow* window)
{
	this->updateKeyBinds(dt);
	this->updateMousePositions();
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	mouseMan.update(dt, this->mousePosView);

	
}

void LevelEditorState::render(sf::RenderTarget* target)
{
	this->mouseMan.draw(this->window);
}
