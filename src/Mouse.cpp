
//================================ include =========================//

#include "Mouse.h"
#include "Controller.h"
#include "Resources.h"
#include <cstdlib> 
#include <ctime> 

//============================== constractor =============================//

Mouse::Mouse():m_location(),m_down(0),m_left(0),m_right(0),m_up(0),m_nextLocation()
{
	setTexture(Resources::getInstance().getTextureVector(1));
	setSoundCat(Resources::getInstance().getSoundBufferVector(0));
	setSoundCheese(Resources::getInstance().getSoundBufferVector(1));
	setSoundObject(Resources::getInstance().getSoundBufferVector(2));
}

//================================ func ====================================//

void Mouse::draw(sf::RenderWindow& window) {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_position.x, m_position.y);
	window.draw(sprite);
}
//------------------------------------------------------------------//
//functions that get a sprite and check if there is a collision between the mouse
bool Mouse::isObject(sf::Sprite& sprite) {

	sf::Sprite mouseSprite;
	mouseSprite = sf::Sprite(m_textur);
	mouseSprite.setPosition(m_position.x, m_position.y);

	if (mouseSprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) 
		return true;

	return false;
}
//------------------------------------------------------------------//
//function that get the controller and move the mouse 
void Mouse::move(Controller& controller) {

	m_bound = m_position;
	m_nextPosition = m_position;

	//move mouse though special key
	switch (controller.getSpecialKey())
	{
	case 72:
		m_up -= 5;
		m_down -= 5;
		m_nextPosition.y -= 5;
		break;

	case 80:
		m_down += 5;
		m_up += 5;
		m_bound.y += 35;
		m_nextPosition.y += 5;
		break;

	case 75:
		m_left -= 5;
		m_right -= 5;
		m_nextPosition.x -= 5;
		break;

	case 77:
		m_right += 5;
		m_left += 5;
		m_bound.x += 35;
		m_nextPosition.x += 5;
		break;

	default:
		break;
	}
	updateLoction();
	objectExists(controller);
}
//------------------------------------------------------------------//
void Mouse::updateLoction() {

	m_nextLocation = m_location;
	if (m_up == -35)
	{
		m_down = 30;
		m_up = 0;
		m_nextLocation.m_y--;
	}
	else if (m_down == 35) {
		m_up = -30;
		m_down = 0;
		m_nextLocation.m_y++;
	}
	else if (m_left == -35) {
		m_right = 30;
		m_left = 0;
		m_nextLocation.m_x--;
	}
	else if (m_right == 35) {

		m_left = -30;
		m_right = 0;
		m_nextLocation.m_x++;
	}
}
//------------------------------------------------------------------//
//function that get controller and check there is a object
void Mouse::objectExists(Controller& controller) {

	Location loc = m_location;
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_nextPosition.x, m_nextPosition.y);

	//if collision with cat, lower life and restart
	if(controller.isCat(sprite))
	{
		controller.addLife(-1);
		playSound(1);
		//m_soundCat.setBuffer(m_soundCats);
		//m_soundCat.setVolume(4);
		//m_soundCat.play();
		controller.restart();
		return;
	}
	else if (controller.isWall(sprite, loc))
	{
		return;
	}
	//if collision with door, check if key exist and erase
	else if (controller.isDoor(sprite, loc))
	{
		if (controller.getKey() <= 0) {
			return;
		}
		controller.addPoints(2);
		controller.addKey(-1);	
		playSound(3);
		//m_soundObject.setBuffer(m_soundObjects);
		//m_soundObject.setVolume(4);
		//m_soundObject.play();
		controller.eraserObject(loc);
	}
	//if collision with key, add key and erase 
	else if(controller.isKey(sprite, loc))
	{
		controller.addKey(1);
		playSound(3);
		controller.eraserObject(loc);
	}
	//if collision with gift erase it and action gift
	else if(controller.isGift(sprite, loc))
	{
		srand((unsigned int)time(nullptr));
		int random = rand() % 4;
		actionGift(controller, random);
		playSound(3);
		controller.eraserObject(loc);
	}
	//if collision with cheese erase it
	else if(controller.isCheese(sprite, loc))
	{
		controller.addPoints(10);	
		playSound(2);
		controller.eraserObject(loc);
	}

	m_location = m_nextLocation;
	m_position = m_nextPosition;
}
//------------------------------------------------------------------//
// function that get a number and make the act 
void Mouse::actionGift(Controller& controller, int random) {

	controller.addPoints(5);
	switch (random)
	{
	case 0:
		controller.eraserCat();
		break;

	case 1:
		controller.addLife(1);
		break;

	case 2:
		controller.setFreeze(2);
		break;
	
	case 3:
		controller.setTime(60);
		break;

	}
}
//------------------------------------------------------------------//
void Mouse::playSound(int type) {

	switch (type)
	{

	case 1:
		m_sound.setBuffer(m_soundCats);
		break;
	case 2:
		m_sound.setBuffer(m_soundCheeses);
		break;
	case 3:
		m_sound.setBuffer(m_soundObjects);
		break;
	default:
		return;
	}
	m_sound.setVolume(4);
	m_sound.play();

}


//================================ get/set func ====================================//

void Mouse::setLocation(Location loc) {

	m_location.m_x = loc.m_x;
	m_location.m_y = loc.m_y;
}
//------------------------------------------------------------------//
void Mouse::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
	m_position.x = m_topLeft.x + (m_location.m_x * 43);
	m_position.y = m_topLeft.y + (m_location.m_y * 43);
}
//------------------------------------------------------------------//
void Mouse::setPosition(sf::Vector2f newPosition) {

	m_position = newPosition;
}
//------------------------------------------------------------------//
sf::Vector2f Mouse::getPosition() {

	return m_position;
}
//------------------------------------------------------------------//
void Mouse::setTexture(sf::Texture textur) {

	m_textur = textur;
}
//------------------------------------------------------------------//
void Mouse::setSoundCheese(sf::SoundBuffer& soundBuffer) {

	m_soundCheeses = soundBuffer;
}
//------------------------------------------------------------------//
void Mouse::setSoundObject(sf::SoundBuffer& soundBuffer) {

	m_soundObjects = soundBuffer;
}
//------------------------------------------------------------------//
void Mouse::setSoundCat(sf::SoundBuffer& soundBuffer) {

	m_soundCats = soundBuffer;
}

//============================== distractor =============================//

Mouse::~Mouse()
{
}