
//================================ include =========================//

#include "Key.h"
#include "Resources.h"

//============================== constractor =============================//

Key::Key() :m_location(0,0)
{
	setTexture(Resources::getInstance().getTextureVector(5));
}

//============================== func =============================//


//Draws the Key on the provided RenderWindow.
void Key::draw(sf::RenderWindow& window) {

	// Create a sprite for the Key with the specified texture and draw.
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	window.draw(sprite);
}
//------------------------------------------------------------------//
//Checks if a given sprite intersects with the Key.
bool Key::isObject(sf::Sprite& sprite) {

	// Create a sprite for the Key with the specified texture
	sf::Sprite keySprite;
	keySprite = sf::Sprite(m_textur);
	keySprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));

	// Check for intersection between the Key sprite and the provided sprite
	if (keySprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}


//================================ get/set func ====================================//


void Key::setLocation(Location loc) {

	m_location = loc;
}
//------------------------------------------------------------------//
void Key::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}
//------------------------------------------------------------------//
Location Key::getPosition() {

	return m_location;
}
//------------------------------------------------------------------//
sf::Sprite Key::getSprite() {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43),
		m_topLeft.y + (m_location.m_y * 43));
	return sprite;
}
//------------------------------------------------------------------//
void Key::setTexture(sf::Texture textur) {

	m_textur = textur;
}

//============================== distractor =============================//

Key::~Key()
{
}