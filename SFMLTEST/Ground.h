#pragma once
#include "State.h"

class Ground
{
private:
	sf::RectangleShape shape;
	sf::Color colorTemp;
	std::string tag;
public:
	Ground();
	~Ground();

	void setTag(std::string s) { tag = s; }
	std::string getTag() { return tag; }
	void initGround(sf::RenderWindow* window, int height, int width, float x, float y, sf::Color c, std::string temp);
	const sf::RectangleShape& getShape() const;
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

