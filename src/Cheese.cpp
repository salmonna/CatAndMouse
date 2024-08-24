
//================================ include =========================//

#include "Cheese.h"
#include "Resources.h"

//============================== constractor =============================//

Cheese::Cheese():m_location(0,0)
{
	setTexture(Resources::getInstance().getTextureVector(6));
}

//============================== func =============================//


//Draws the cheese on the provided RenderWindow.
void Cheese::draw(sf::RenderWindow& window) {
	
	// Create a sprite for the cheese with the specified texture and draw.
	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	window.draw(sprite);
}
//------------------------------------------------------------------//
//Checks if a given sprite intersects with the cheese.
bool Cheese::isObject(sf::Sprite& sprite){
	
	// Create a sprite for the door with the specified texture
	sf::Sprite cheeseSprite;
	cheeseSprite = sf::Sprite(m_textur);
	cheeseSprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));

	// Check for intersection between the door sprite and the provided sprite
	if (cheeseSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}


//================================ get/set func ====================================//


void Cheese::setLocation(Location loc) {

	m_location = loc;
}
//------------------------------------------------------------------//
void Cheese::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}
//------------------------------------------------------------------//
Location Cheese::getPosition() {

	return m_location;
}
//------------------------------------------------------------------//
sf::Sprite Cheese::getSprite() {

	sf::Sprite sprite;
	sprite = sf::Sprite(m_textur);
	sprite.setPosition(m_topLeft.x + (m_location.m_x * 43), m_topLeft.y + (m_location.m_y * 43));
	return sprite;
}
//------------------------------------------------------------------//
void Cheese::setTexture(sf::Texture textur) {

	m_textur = textur;
}

//============================== distractor =============================//

Cheese::~Cheese()
{
}