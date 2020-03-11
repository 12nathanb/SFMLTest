#pragma once
#include "state.h"

class DrawInk
{
private:
	sf::RectangleShape shape;
	std::string inkName;
	int X = 0;
	int Y = 0;
	sf::Color color;

public:
	DrawInk();
	~DrawInk();
	void init(std::string name, int sizeX, int sizeY, float mouseX, float mouseY);
	int getX() { return X; }
	int getY() { return Y; }
	sf::Color getColor() { return color; }
	sf::RectangleShape getShape() { return shape; }
	std::string getName() { return inkName; }

	void draw(sf::RenderTarget* target);
};

