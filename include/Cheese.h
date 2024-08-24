

#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Cheese : public StaticObjects
{
public:
	Cheese();

	virtual void draw(sf::RenderWindow& window) override;
	virtual Location getPosition()override;
	virtual sf::Sprite getSprite()override;
	virtual bool isObject(sf::Sprite& sprite) override;

	void setTexture(sf::Texture textur);
	void setLocation(Location loc);
	void setTopLeft(sf::Vector2f topLeft);
	

	~Cheese();

private:

	sf::Vector2f m_topLeft;
	Location m_location;
	sf::Texture m_textur;
};

