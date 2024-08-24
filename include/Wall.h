

#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Wall : public StaticObjects
{
public:
	Wall();

	virtual void draw(sf::RenderWindow& window);
	virtual Location getPosition();
	virtual sf::Sprite getSprite();
	void setTexture(sf::Texture textur);
	virtual bool isObject(sf::Sprite& sprite) override;

	void setLocation(Location loc);
	void setTopLeft(sf::Vector2f topLeft);

	~Wall();

private:

	sf::Vector2f m_topLeft;
	Location m_location;
	sf::Texture m_textur;
};

