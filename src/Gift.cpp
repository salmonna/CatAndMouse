
//================================ include =========================//

#include "Gift.h"
#include "Resources.h"

//============================== constractor =============================//

Gift::Gift() :m_location(0,0)
{
	setTexture(Resources::getInstance().getTextureVector(4));
}

//============================== func =============================//
//Draws the gift on the provided RenderWindow.
void Gift::draw(sf::RenderWindow& window) {

	// Create a sprite for the gift with the specified texture and draw.
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	window.draw(sprite);
	
}
//------------------------------------------------------------------//
//Checks if a given sprite intersects with the gift.
bool Gift::isObject(sf::Sprite& sprite) {

	// Create a sprite for the gift with the specified texture
	sf::Sprite giftSprite;
	giftSprite = sf::Sprite(m_textur);
	giftSprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	
	// Check for intersection between the gift sprite and the provided sprite
	if (giftSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}


//================================ get/set func ====================================//

void Gift::setLocation(Location loc) {

	m_location = loc;
}
//------------------------------------------------------------------//
void Gift::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}
//------------------------------------------------------------------//
Location Gift::getPosition() {

	return m_location;
}
//------------------------------------------------------------------//
sf::Sprite Gift::getSprite() {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), 
		m_topLeft.y + (m_location.m_y * 43));
	return sprite;
}
//------------------------------------------------------------------//
void Gift::setTexture(sf::Texture textur) {

	m_textur = textur;
}

//============================== distractor =============================//

Gift::~Gift()
{
}