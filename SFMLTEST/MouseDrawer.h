#pragma once
#include "state.h"
#include "DrawInk.h"
#include <iostream>
#include <fstream>

class MouseDrawer
{
private:
	
	
	std::vector<DrawInk> shapeContain;
public:
	MouseDrawer();
	~MouseDrawer();

	void init(sf::RenderWindow* window);
	void update(const float& dt, sf::Vector2f posView);
	void generateXML();
	void draw(sf::RenderTarget* target);

};

