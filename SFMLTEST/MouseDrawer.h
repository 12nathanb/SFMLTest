#pragma once
#include "state.h"

class MouseDrawer
{
private:
	sf::Vector2i mouseTrack;
	
	std::vector< sf::RectangleShape> shapeContain;
public:
	MouseDrawer();
	~MouseDrawer();

	void init(sf::RenderWindow* window);
	void update(const float& dt);
	void draw(sf::RenderTarget* target);

};

