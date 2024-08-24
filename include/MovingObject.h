
//================================ include =========================//

#pragma once
#include "GameObject.h"
#include "Location.h"

class Controller;

class MovingObject: public GameObject
{
public:
	MovingObject();

	virtual void move(Controller& controller) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setLocation(Location loc) = 0;
	virtual void setPosition(sf::Vector2f newPosition) = 0;

	~MovingObject();
private:

};

