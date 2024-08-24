
//================================ include =========================//

#include "Wall.h"
#include "Resources.h"

//============================== constractor =============================//

Wall::Wall() :m_location(0,0)
{
	setTexture(Resources::getInstance().getTextureVector(7));
}

//================================ func ====================================//

//Draws the Wall on the provided RenderWindow.
void Wall::draw(sf::RenderWindow& window) {

	// Create a sprite for the Wall with the specified texture and draw.
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	window.draw(sprite);
}
//------------------------------------------------------------------//
//Checks if a given sprite intersects with the Wall.
bool Wall::isObject(sf::Sprite& sprite) {

	// Create a sprite for the Wall with the specified texture
	sf::Sprite WallSprite;
	WallSprite = sf::Sprite(m_textur);
	WallSprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));

	// Check for intersection between the Wall sprite and the provided sprite
	if (WallSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

//================================ get/set func ====================================//

void Wall::setLocation(Location loc) {

	m_location = loc;
}
//------------------------------------------------------------------//
void Wall::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}
//------------------------------------------------------------------//
Location Wall::getPosition() {

	return m_location;
}
//------------------------------------------------------------------//
sf::Sprite Wall::getSprite() {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43),
		m_topLeft.y + (m_location.m_y * 43));
	return sprite;
}
//------------------------------------------------------------------//
void Wall::setTexture(sf::Texture textur) {

	m_textur = textur;
}

//============================== distractor =============================//

Wall::~Wall()
{
}