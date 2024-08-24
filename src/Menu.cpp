
//================================ include =========================//

#include "Menu.h"
#include "Window.h"

//============================== constractor =============================//

Menu::Menu():m_exit(false), m_start(false), m_help(false), m_openMenu(true), m_nextLevel(false), m_endMenu(false)
{
	
	m_startTextur = Resources::getInstance().getTextureVectorMenu(0);
	m_helpTextur = Resources::getInstance().getTextureVectorMenu(1);
	m_exitTextur = Resources::getInstance().getTextureVectorMenu(2);
	m_nextLevelTextur = Resources::getInstance().getTextureVectorMenu(3);
}

//======================================== func ====================================//

//Checks for mouse button release events in the opening menu.
void Menu::checkReleased(sf::RenderWindow& window, sf::Event event) {

	// Convert pixel coordinates to world coordinates
	sf::Vector2f vector(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));

	// Create sprites for opening menu options
	sf::Sprite sprite1(m_startTextur);
	sprite1.setPosition(m_topLeft.x *2 , m_topLeft.y);
	sf::Sprite sprite2(m_helpTextur);
	sprite2.setPosition(m_topLeft.x * 7, m_topLeft.y);
	sf::Sprite sprite3(m_exitTextur);
	sprite3.setPosition(m_topLeft.x * 13, m_topLeft.y);

	switch (event.mouseButton.button)
	{
	case sf::Mouse::Button::Left:

		if (sprite1.getGlobalBounds().contains(vector)) m_start = m_nextLevel = true;

		else if (sprite2.getGlobalBounds().contains(vector)) {
			if (m_help) m_help = false; 
			else m_help = true; 
		}
		else if (sprite3.getGlobalBounds().contains(vector)) m_exit = true;
		
	}
}
//------------------------------------------------------------------//
//Draws the opening menu options on the provided RenderWindow.
void Menu::draw(sf::RenderWindow& window) {

	// Draw "Start" option
	sf::Sprite sprite;
	sprite.setTexture(m_startTextur);
	sprite.setPosition(m_topLeft.x * 2, m_topLeft.y);
	window.draw(sprite);

	// Draw "Help" option
	sprite.setTexture(m_helpTextur);
	sprite.setPosition(m_topLeft.x * 7, m_topLeft.y);
	window.draw(sprite);

	// Draw "Exit" option
	sprite.setTexture(m_exitTextur);
	sprite.setPosition(m_topLeft.x * 13, m_topLeft.y);
	window.draw(sprite);

}
//------------------------------------------------------------------//
//Draws the help information on the provided RenderWindow.
void Menu::drawNextLevel(sf::RenderWindow& window, sf::Text* text, int points) {

	// Create a string with points information
	std::string result = "Total points = " + std::to_string(points);
	result += "\ngood game.\n\n";
	result += "press the next level button to start the next level\n";
	result += "or exit to end the game.\n";

	// Set text properties and draw
	text->setPosition(m_topLeft.x * 2, m_topLeft.y * 10);
	text->setString(result);
	text->setFillColor(sf::Color::Black);
	window.draw(*text);

	// Draw "Next Level" option
	sf::Sprite sprite;
	sprite.setTexture(m_nextLevelTextur);
	sprite.setPosition(m_topLeft.x * 2, m_topLeft.y);
	window.draw(sprite);

	// Draw "Exit" option
	sprite.setTexture(m_exitTextur);
	sprite.setPosition(m_topLeft.x * 13, m_topLeft.y);
	window.draw(sprite);
}
//------------------------------------------------------------------//
//Draws the help information on the provided RenderWindow.
void Menu::drawHelp(sf::RenderWindow& window, sf::Text* text) {
	
	// Create a string with help information
	std::string result = "The objective of this game involves a cat and a mouse.\n";
	result += "The mouse's aim is to consume all the cheeses, \n";
	result += "While evading capture by the cats \n";
	result += "and to collect as many points as possible.\n";

	// Set text properties and draw
	text->setPosition(m_topLeft.x * 2, m_topLeft.y * 10);
	text->setString(result);
	text->setFillColor(sf::Color::Black);
	window.draw(*text);
}


//====================================== bool func ====================================//


bool Menu::isHelp() const{
	return m_help;
}
//------------------------------------------------------------------//
bool Menu::isExit() const {
	return m_exit;
}
//------------------------------------------------------------------//
bool Menu::isStart() const {
	return m_start;
}
//------------------------------------------------------------------//
bool Menu::isNextLevel() const {
	return m_nextLevel;
}
//------------------------------------------------------------------//
bool Menu::openMenu() const {
	return m_openMenu;
}
//------------------------------------------------------------------//
bool Menu::endMenu() const {
	return m_endMenu;
}


//================================ get/set func ====================================//


void Menu::setOpenMenu(bool openMenu) {

	m_openMenu = openMenu;
}
//------------------------------------------------------------------//
void Menu::setEndMenu(bool endMenu) {

	m_endMenu = endMenu;
}
//------------------------------------------------------------------//
void Menu::setHelp(bool help) {

	m_help = help;
}
//------------------------------------------------------------------//
void Menu::setExit(bool exit) {

	m_exit = exit;
}
//------------------------------------------------------------------//
void Menu::setStart(bool restart) {

	m_start = restart;
}
//------------------------------------------------------------------//
void Menu::setNextLevel(bool nextLevel) {

	m_nextLevel = nextLevel;
}
//------------------------------------------------------------------//
sf::Sprite Menu::getNextLevelSprite() {

	sf::Sprite sprite;
	sprite.setTexture(m_nextLevelTextur);
	sprite.setPosition(m_topLeft.x * 2, m_topLeft.y);
	return sprite;
}
//------------------------------------------------------------------//
sf::Sprite Menu::getExitSprite() {

	sf::Sprite sprite;
	sprite.setTexture(m_exitTextur);
	sprite.setPosition(m_topLeft.x * 13, m_topLeft.y);
	return sprite;
}
//------------------------------------------------------------------//
sf::Sprite Menu::getHelpSprite() {

	sf::Sprite sprite;
	sprite.setTexture(m_helpTextur);
	sprite.setPosition(m_topLeft.x * 7, m_topLeft.y);
	return sprite;
}
//------------------------------------------------------------------//
sf::Sprite Menu::getStartSprite() {

	sf::Sprite sprite;
	sprite.setTexture(m_startTextur);
	sprite.setPosition(m_topLeft.x * 2, m_topLeft.y);
	return sprite;
}
//------------------------------------------------------------------//
void Menu::setTopLeft(sf::Vector2f topLeft) {

	m_topLeft = topLeft;
}