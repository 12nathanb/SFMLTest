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
protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;
	virtual void endState() = 0;
	virtual void checkForEnd();

	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

