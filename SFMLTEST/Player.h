#pragma once
#include "Character.h"

class Player : 
	public Character
{
private:
	sf::RectangleShape shape;
	int movementSpeed = 20;
public:
	Player();
	virtual ~Player();

	void move(const float& dt, const float x, const float y);
	void update(const float& dt);
	void render(sf::RenderTarget* target);

};

