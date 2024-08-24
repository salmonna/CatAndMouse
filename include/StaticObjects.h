
#pragma once
#include "GameObject.h"
#include <vector>
#include "Location.h"

class StaticObjects: public GameObject
{
public:
	StaticObjects();

	virtual Location getPosition() = 0;
	virtual sf::Sprite getSprite() = 0;

	~StaticObjects();

private:

};

