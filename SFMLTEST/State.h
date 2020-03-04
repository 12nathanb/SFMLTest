#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

class State
{
private:

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;
	virtual void endState() = 0;
	virtual void checkForEnd();

	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const float& dt, sf::RenderWindow* window) = 0;
	virtual void updateMousePositions();
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

