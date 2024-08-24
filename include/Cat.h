
//================================ include =========================// 

#pragma once

#include "Location.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

struct SpcialKey
{
	int m_up;
	int m_down;
	int m_left;
	int m_right;

	SpcialKey(int up = 0, int down = 0, int left = 0, int right = 0) :
		m_up(up), m_down(down), m_left(left), m_right(right) {};
};


class Cat : public MovingObject
{
public:
	Cat();

	virtual void move(Controller& controller) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual sf::Vector2f getPosition() override;
	virtual bool isObject(sf::Sprite& sprite) override;
	virtual void setLocation(Location loc)override;
	virtual void setPosition(sf::Vector2f newPosition)override;

	void setTopLeft(sf::Vector2f topLeft);
	void setTexture(sf::Texture textur);
	void setSoundBuffer(sf::SoundBuffer& soundBuffer);

	~Cat();

private:

	SpcialKey m_spcialKey;

	sf::Vector2f m_nextPosition;
	sf::Vector2f m_position;
	sf::Vector2f m_topLeft;
	Location m_location;
	Location m_nextLocation;

	sf::SoundBuffer m_soundBuffer;
	sf::Texture m_textur;
	sf::Sound m_sound;

	void moveCat(sf::Vector2f mouse);
	void updateLoction();
	void objectExists(Controller& controller);
	void returnObject(Controller& controller);
};

