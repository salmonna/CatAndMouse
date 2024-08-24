
#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool isObject(sf::Sprite& sprite) = 0;

	virtual ~GameObject();

protected:
	
};



