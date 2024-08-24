
//================================ include =========================//

#pragma once

#include "Location.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Mouse: public MovingObject
{
public:
	Mouse();

	virtual void draw(sf::RenderWindow& window) override;
	virtual sf::Vector2f getPosition() override;
	virtual bool isObject(sf::Sprite& sprite) override;
	virtual void move(Controller& controller) override;
	virtual void setLocation(Location loc)override;
	virtual void setPosition(sf::Vector2f newPosition)override;
	
	void setTexture(sf::Texture textur);
	void setTopLeft(sf::Vector2f topLeft);
	void setSoundCheese(sf::SoundBuffer& soundBuffer);
	void setSoundObject(sf::SoundBuffer& soundBuffer);
	void setSoundCat(sf::SoundBuffer& soundBuffer);

	~Mouse();

private:

	int m_up;
	int m_down;
	int m_left;
	int m_right;

	sf::Vector2f m_bound;
	sf::Vector2f m_nextPosition;
	sf::Vector2f m_position;
	sf::Vector2f m_topLeft;
	Location m_location;
	Location m_nextLocation;

	sf::SoundBuffer m_soundCheeses;
	sf::SoundBuffer m_soundObjects;
	sf::SoundBuffer m_soundCats;
	sf::Texture m_textur;

	sf::Sound m_sound;

	void updateLoction();
	void objectExists(Controller& controller);
	void actionGift(Controller& controller, int random);
	void playSound(int type);
};

