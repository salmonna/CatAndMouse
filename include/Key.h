

#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Key : public StaticObjects
{
public:
	Key();

	virtual void draw(sf::RenderWindow& window);
	virtual Location getPosition();
	virtual sf::Sprite getSprite();
	virtual bool isObject(sf::Sprite& sprite) override;

	void setTexture(sf::Texture textur);
	void setLocation(Location loc);
	void setTopLeft(sf::Vector2f topLeft);
	
	~Key();

private:

	sf::Vector2f m_topLeft;
	Location m_location;
	sf::Texture m_textur;
};

