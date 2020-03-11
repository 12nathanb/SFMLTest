#pragma once
#include "Character.h"

class Player : 
	public Character
{
private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	sf::Vector2f gravity = { 0.0f, 9.8f };
	sf::Vector2f jumpVel = { 0.0f, -270.3f };
	int movementSpeed = 200;
	bool falling = false;
	float groundHeight = 0;
	bool canJump = false;
	bool doubleJ = false;
	bool jumping = false;
	float jumpHeight = 50;
	int maxjumpHeight = 0;
	int playerNum;
	float controllerX = 0;
	//float gravity = 2.0f;

public:
	Player();
	virtual ~Player();

	void init(sf::Vector2f v);
	void isPlayerFalling(bool temp);
	void move(sf::Vector2f distance) { shape.move(distance); }
	void setGroundHeight(float h) { groundHeight = h; }
	void setPlayerNumber(int i) { playerNum = i; }
	int getPlayerNumber() { return playerNum; };

	void jump();
	void setPos(sf::Vector2f newPos) { shape.setPosition(newPos); }
	const sf::RectangleShape& getShape() const;
	//void move(const float& dt, const float x, const float y);
	void update(const float& dt);
	void render(sf::RenderTarget* target);

};

