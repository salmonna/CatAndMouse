

#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Door : public StaticObjects
{
public:
	Door();

	virtual void draw(sf::RenderWindow& window)override;
	virtual Location getPosition()override;
	virtual sf::Sprite getSprite()override;
	virtual bool isObject(sf::Sprite& sprite) override;

	void setTexture(sf::Texture textur);
	void setLocation(Location loc);
	void setTopLeft(sf::Vector2f topLeft);

	bool is_door(sf::Sprite& sprite);
	

	~Door();

private:

	sf::Vector2f m_topLeft;
	Location m_location;
	sf::Texture m_textur;
};

