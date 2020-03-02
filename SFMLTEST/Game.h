#pragma once
#include"GameState.h"
#include "LevelEditorState.h"
class Game
{
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

private:

	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	void endApplication();

	void UpdateDT();
	void UpdateSFMLEvents();
	void Update();


	void Render();
	void Run();
};

