
//================================ include =========================//

#include "Door.h"
#include "Resources.h"

//============================== constractor =============================//

Door::Door():m_location(0,0)
{
	setTexture(Resources::getInstance().getTextureVector(3));
}

//============================== func =============================//

//Draws the door on the provided RenderWindow.
void Door::draw(sf::RenderWindow& window) {

	// Create a sprite for the door with the specified texture and draw.
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	window.draw(sprite);
}
//------------------------------------------------------------------//
//Checks if a given sprite intersects with the door.
bool Door::isObject(sf::Sprite& sprite) {

	// Create a sprite for the door with the specified texture
	sf::Sprite doorSprite;
	doorSprite = sf::Sprite(m_textur);
	doorSprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));

	// Check for intersection between the door sprite and the provided sprite
	if (doorSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

//================================ get/set func ====================================//

void Door::setLocation(Location loc) {

	m_location = loc;
}
//------------------------------------------------------------------//
void Door::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}
//------------------------------------------------------------------//
Location Door::getPosition() {

	return m_location;
}
//------------------------------------------------------------------//
sf::Sprite Door::getSprite() {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43),
		m_topLeft.y + (m_location.m_y * 43));
	return sprite;
}
//------------------------------------------------------------------//
void Door::setTexture(sf::Texture textur) {

	m_textur = textur;
}

//============================== distractor =============================//

Door::~Door()
{
}