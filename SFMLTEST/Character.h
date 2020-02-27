#pragma once
#include "state.h"


class Character
{
protected:

public:
	Character();
	virtual ~Character();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;

};

