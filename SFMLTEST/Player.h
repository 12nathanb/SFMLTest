#pragma once
#include "Character.h"

class Player : 
	public Character
{
private:
	sf::RectangleShape shape;
	int movementSpeed = 20;
	bool falling = false;
	float groundHeight = 0;
	bool canJump = false;
	float gravity = 2.0f;

public:
	Player();
	virtual ~Player();

	void isPlayerFalling(bool temp);
	void move(sf::Vector2f distance) { shape.move(distance); }
	void setGroundHeight(float h) { groundHeight = h; }


	void setPos(sf::Vector2f newPos) { shape.setPosition(newPos); }
	const sf::RectangleShape& getShape() const;
	//void move(const float& dt, const float x, const float y);
	void update(const float& dt);
	void render(sf::RenderTarget* target);

};

