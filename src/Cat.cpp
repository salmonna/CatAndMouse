
//================================ include =========================//

#include "Cat.h"
#include "Controller.h"
#include "Resources.h"

//============================== constractor =============================//

Cat::Cat():m_location(0,0), m_nextLocation(0,0), m_spcialKey(0,0,0,0)
{
	setTexture(Resources::getInstance().getTextureVector(2));
	setSoundBuffer(Resources::getInstance().getSoundBufferVector(0));
}

//========================================== func ====================================//

//------------------------------------------------------------------//
void Cat::draw(sf::RenderWindow& window) {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_position.x, m_position.y);
	window.draw(sprite);
}
//------------------------------------------------------------------//
//functions that get a sprite and check if there is a collision between the cat
bool Cat::isObject(sf::Sprite& sprite) {

	sf::Sprite catSprite;
	catSprite = sf::Sprite(m_textur);
	catSprite.setPosition(m_position.x, m_position.y);

	if (catSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}
//------------------------------------------------------------------//
//function that get the controller and move the cat 
void Cat::move(Controller& controller) {

	Location loc;
	loc = m_location;
	moveCat(controller.getMousePosition());
	updateLoction();
	objectExists(controller);
	
}
//------------------------------------------------------------------//
//function that get nouses position and move the cat to him
void Cat::moveCat(sf::Vector2f mouse) {

	m_nextPosition = m_position;
	if ((int)mouse.x > (int)m_position.x)
	{
		m_spcialKey.m_right ++;
		m_spcialKey.m_left ++;
		m_nextPosition.x ++;
	}
	else if ((int)mouse.x < (int)m_position.x)
	{
		m_spcialKey.m_left --;
		m_spcialKey.m_right --;
		m_nextPosition.x --;
	}
	else
	{
		if ((int)mouse.y < (int)m_position.y)
		{
			m_spcialKey.m_up --;
			m_spcialKey.m_down --;
			m_nextPosition.y --;
		}
		else if((int)mouse.y > (int)m_position.y)
		{
			m_spcialKey.m_down ++;
			m_spcialKey.m_up ++;
			m_nextPosition.y ++;
		}
	}
}
//------------------------------------------------------------------//
void Cat::updateLoction() {

	m_nextLocation = m_location;
	if (m_spcialKey.m_up == -40)
	{
		m_spcialKey.m_down = 35;
		m_spcialKey.m_up = 0;
		m_nextLocation.m_y--;
	}
	else if (m_spcialKey.m_down == 40) {
		
		m_spcialKey.m_up = -35;
		m_spcialKey.m_down = 0;
		m_nextLocation.m_y++;
	}
	else if (m_spcialKey.m_left == -40) {
		
		m_spcialKey.m_right = 35;
		m_spcialKey.m_left = 0;
		m_nextLocation.m_x--;
	}
	else if (m_spcialKey.m_right == 40) {

		m_spcialKey.m_left = -35;
		m_spcialKey.m_right = 0;
		m_nextLocation.m_x++;
	}
}
//------------------------------------------------------------------//
//func that get controller and check if there is a wall/door/mouse
void Cat::objectExists(Controller& controller) {
	
	Location loc = m_location;
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_nextPosition.x, m_nextPosition.y);

	if (controller.isWall(sprite, loc) || controller.isDoor(sprite, loc))
	{
		return;
	}
	
	else if (controller.isMouse(sprite))
	{	
		m_sound.setBuffer(m_soundBuffer);
		m_sound.setVolume(4);
		m_sound.play();
		controller.addLife(-1);
		controller.restart();
		return;
	}
	m_location = m_nextLocation;
	m_position = m_nextPosition;
}

//================================ get/set func ====================================//

void Cat::setLocation(Location loc) {

	Location init(-1, -1);
	SpcialKey spcialKey(-15,15,-15,15);
	m_location = loc;
	m_spcialKey = spcialKey;
}
//------------------------------------------------------------------//
void Cat::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
	sf::Vector2f temp;
	
	temp.x = m_topLeft.x + (m_location.m_x * 43);
	temp.y = m_topLeft.y + (m_location.m_y * 43);
	m_position = temp;
}
//------------------------------------------------------------------//
void Cat::setTexture(sf::Texture textur) {

	m_textur = textur;
}
//------------------------------------------------------------------//
sf::Vector2f Cat::getPosition() {

	return m_position;
}
//------------------------------------------------------------------//
void Cat::setPosition(sf::Vector2f newPosition) {

	m_position = newPosition;
}
//------------------------------------------------------------------//
void Cat::setSoundBuffer(sf::SoundBuffer& soundBuffer) {

	m_soundBuffer = soundBuffer;
}

//============================== distractor =============================//

Cat::~Cat()
{
}