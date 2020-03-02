#pragma once
#include "State.h"
#include "MouseDrawer.h"

class LevelEditorState:
	public State
{
private:
	MouseDrawer mouseMan;
public:
	LevelEditorState(sf::RenderWindow* window);
	virtual ~LevelEditorState();

	void endState();

	void updateKeyBinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

