#pragma once
#include "State.h"

class Ground
{
private:
	sf::RectangleShape shape;

public:
	Ground();
	~Ground();


	void initGround(sf::RenderWindow* window, int height, int width, float x, float y);
	const sf::RectangleShape& getShape() const;
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

