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



class Character
{
protected:

public:
	Character();
	virtual ~Character();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;

};

