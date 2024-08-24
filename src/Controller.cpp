
//================================ include =========================//

#include "Controller.h"
#include <iostream>
#include <vector>

//============================== constractor =============================//

Controller::Controller():m_life(3), m_freeze(0), m_catSeconds(0.05f), m_keys(0), m_points(0),
			m_gameTime(0), m_gameSecond(0), m_gameMinuts(0), m_level(0), m_specialKey(0),
			m_menu(), m_window(m_menu)
{
	std::vector <sf::String> level{"Level1.txt", "Level2.txt", "Level3.txt"};
	m_text.setFont(Resources::getInstance().getFont());

	for (int i = 0; i < level.size(); i++)
	{
		m_level = i+1;
		m_gameTime = (float)60 * (i+1);//add 60 second for every level
		m_board.readFile(level[i]);
		m_menu.setTopLeft(m_board.getTopLeft());
		m_window.creatWindow(m_board.getCol(), m_board.getRow());
		initialization();
		runGame();
	}
}


//================================ func ====================================//


//function that run the level 
void Controller::runGame() {

	sf::Vector2f vector;
	float catSecond;

	while (m_window.windowIsOpen())
	{
		m_window.clear();
		
		//if window get key event so "m_window.eventResponse()" = true. 
		if (m_window.eventResponse()) 
			m_ptrMovingObject[0]->move(*this);

		if (m_menu.openMenu())
		{
			m_board.draw(m_window.getWindow());
			openingMenu();
			m_window.display();
			continue;
		}
		else if (m_menu.endMenu()) {
			m_board.draw(m_window.getWindow());
			endMenu();
			m_window.display();
			continue;
		}
		
		//move the cat every 0.10 second
		sf::Time catTime = m_catClock.getElapsedTime();
		catSecond = catTime.asSeconds();
		if (m_catSeconds < catSecond)
		{
			catsTurn();
			m_catClock.restart();
		}
		
		draw();
		m_window.display();
		endGame();
	}
}
//-----------------------------------------------------//
//func that showing the openning menu
void Controller::openingMenu() {

	//if mouse released on buttom then it's change to true
	m_menu.checkReleased(m_window.getWindow(), m_window.getEvent());

	m_menu.draw(m_window.getWindow());
	if (m_menu.isHelp())
	{
		m_menu.drawHelp(m_window.getWindow(), &m_text);
	}

	if (m_menu.isStart())
	{
		m_menu.setOpenMenu(false);
		m_menu.setNextLevel(false);
	}

	if (m_menu.isExit())
	{
		m_window.close();
		exit(EXIT_SUCCESS);
	}
}
//-----------------------------------------------------//
//func that showing the end menu
void Controller::endMenu() {
	
	//if mouse released on buttom then it's change to true
	m_menu.checkReleased(m_window.getWindow(), m_window.getEvent());
	
	m_menu.drawNextLevel(m_window.getWindow(), &m_text, m_points);
	if (m_menu.isNextLevel())
	{
		m_menu.setEndMenu(false);
		clearAll();
		m_board.clearBoard();
		m_window.close();
		return;
	}

	if (m_menu.isExit())
	{
		m_window.close();
		exit(EXIT_SUCCESS);
	}
}
//-----------------------------------------------------//
// function that check if the level is end
void Controller::endGame() {

	sf::Time gameTime = m_gameClock.getElapsedTime();
	float gameSecond = gameTime.asSeconds();

	//count the seconds
	if (1 <= gameSecond)
	{
		m_gameSecond++;
		m_gameClock.restart();
	}
	//count the minuts
	if (m_gameSecond > 59)
	{
		m_gameSecond = 0;
		m_gameMinuts++;
	}
	//end the if or ended of the timer
	if (m_life == 0 || m_gameTime <= (m_gameMinuts*60) + m_gameSecond)
	{
		clearAll();
		initialization();
	}
	//cheese ended. move to the next level
	else if(m_objectSize[3] == 0)
	{
		m_points += 25;
		m_points += (int)((m_ptrMovingObject.size() - 1) *5);
		m_menu.setEndMenu(true);
	}
}
//-----------------------------------------------------//
void Controller::clearAll() {

	m_gameSecond = 0;
	m_gameMinuts = 0;
	m_menu.setOpenMenu(true);
	m_menu.setEndMenu(false);
	m_menu.setNextLevel(false);
	m_menu.setStart(false);
	m_life = 3;
	m_ptrMovingObject.clear();
	m_ptrStaticObjects.clear();
	m_objectSize.clear();
	m_window.getEvent().mouseButton.x = 0;
	m_window.getEvent().mouseButton.y = 0;
	m_board.clearVector();
}
//-----------------------------------------------------//
void Controller::catsTurn() {
	//move the cats every 0.10 seconds
	m_catSeconds = 0.05f;
	for (int i = 1; i < m_ptrMovingObject.size(); i++)
	{
		m_ptrMovingObject[i]->move(*this);
	}
}
//-----------------------------------------------------//
//function that get object place through location and erase him  
void Controller::eraserObject(Location loc) {

	int size = 0;
	m_ptrStaticObjects.erase(m_ptrStaticObjects.begin() + loc.m_y);
	
	for (int i = 0; i < m_objectSize.size(); i++)
	{
		size += m_objectSize[i];
		if (size - m_objectSize[i] <= loc.m_y && size > loc.m_y && m_objectSize[i] != 0)
		{
			m_objectSize[i]--;
			return;
		}
	}
}
//-----------------------------------------------------//
// erase the first cat
void Controller::eraserCat() {

	if (m_ptrMovingObject.size()-1 > 0)
		m_ptrMovingObject.erase(m_ptrMovingObject.begin()+1);
}
//-----------------------------------------------------//
// function that return the cats and mouse to their first places
void Controller::restart() {

	m_ptrMovingObject[0]->setLocation(m_board.getMouse());
	m_ptrMovingObject[0]->setPosition(m_mouse.getPosition());

	sf::Vector2f vector;
	for (int i = 1; i < m_ptrMovingObject.size(); i++)
	{
		m_ptrMovingObject[i]->setLocation(m_board.getCatsVector()[i-1]);
		vector.x = m_board.getTopLeft().x + (m_board.getCatsVector()[i - 1].m_x * 43);
		vector.y = m_board.getTopLeft().y + (m_board.getCatsVector()[i - 1].m_y * 43);
		m_ptrMovingObject[i]->setPosition(vector);
	}
}
//-----------------------------------------------------//
void Controller::draw() {

	m_board.draw(m_window.getWindow());
	for (int i = 0; i < m_ptrStaticObjects.size(); i++)
	{
		m_ptrStaticObjects[i]->draw(m_window.getWindow());
	}
	for (int i = 0; i < m_ptrMovingObject.size(); i++)
	{
		m_ptrMovingObject[i]->draw(m_window.getWindow());
	}
	std::string result = "Points = " + std::to_string(m_points);
	result += "     Key = " + std::to_string(m_keys);
	result += "     Life = " + std::to_string(m_life);
	result += "     Level = " + std::to_string(m_level);
	result += "     Time = 0" + std::to_string((int)(m_gameTime / 60) - m_gameMinuts - 1);
	result += ":" + std::to_string(60 - m_gameSecond);
	
	m_text.setString(result);
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(m_board.getCol(), m_window.getWindow().getSize().y - m_text.getLocalBounds().height - (m_board.getCol()/2));
	m_window.getWindow().draw(m_text);
}

//================================== initialization ====================================//

//function that initialize all the objects
void Controller::initialization() {

	initBoard();
	initMouse();
	initCat();
	initDoor();
	initGift();
	initKey();
	initCheese();
	initWall();
	m_text.setCharacterSize(unsigned int(m_board.getCol() * 1.5));
}
//-----------------------------------------------------//
void Controller::initBoard() {

	m_board.setTexture(Resources::getInstance().getTextureVector(0));
}
//-----------------------------------------------------//
void Controller::initMouse() {

	m_mouse.setLocation(m_board.getMouse());
	m_mouse.setTopLeft(m_board.getTopLeft());
	auto mouse = std::make_unique<Mouse>(m_mouse);
	m_ptrMovingObject.push_back(std::move(mouse));
}
//-----------------------------------------------------//
void Controller::initCat() {

	for (int i = 0; i < m_board.getCatsVector().size(); i++)//cat
	{
		m_cat.setLocation(m_board.getCatsVector()[i]);
		m_cat.setTopLeft(m_board.getTopLeft());
		m_ptrMovingObject.push_back(std::make_unique<Cat>(m_cat));
	}
}
//-----------------------------------------------------//
void Controller::initDoor() {
	for (int i = 0; i < m_board.getDoorVector().size(); i++)//door
	{
		m_door.setLocation(m_board.getDoorVector()[i]);
		m_door.setTopLeft(m_board.getTopLeft());
		m_ptrStaticObjects.push_back(std::make_unique<Door>(m_door));
	}
	m_objectSize.push_back((int)m_board.getDoorVector().size());
}
//-----------------------------------------------------//
void Controller::initGift() {
	Gift m_gift;
	for (int i = 0; i < m_board.getGiftsVector().size(); i++)//gift
	{
		m_gift.setLocation(m_board.getGiftsVector()[i]);
		m_gift.setTopLeft(m_board.getTopLeft());
		m_ptrStaticObjects.push_back(std::make_unique<Gift>(m_gift));
	}
	m_objectSize.push_back((int)m_board.getGiftsVector().size());
}
//-----------------------------------------------------//
void Controller::initKey() {

	for (int i = 0; i < m_board.getKeysVector().size(); i++)//key
	{
		m_key.setLocation(m_board.getKeysVector()[i]);
		m_key.setTopLeft(m_board.getTopLeft());
		m_ptrStaticObjects.push_back(std::make_unique<Key>(m_key));
	}
	m_objectSize.push_back((int)m_board.getKeysVector().size());
}
//-----------------------------------------------------//
void Controller::initCheese() {
	for (int i = 0; i < m_board.getCheesesVector().size(); i++)//cheese
	{
		m_cheese.setLocation(m_board.getCheesesVector()[i]);
		m_cheese.setTopLeft(m_board.getTopLeft());
		m_ptrStaticObjects.push_back(std::make_unique<Cheese>(m_cheese));
	}
	m_objectSize.push_back((int)m_board.getCheesesVector().size());
}
//-----------------------------------------------------//
void Controller::initWall() {
	for (int i = 0; i < m_board.getWallVector().size(); i++)//wall
	{
		m_wall.setLocation(m_board.getWallVector()[i]);
		m_wall.setTopLeft(m_board.getTopLeft());
		m_ptrStaticObjects.push_back(std::make_unique<Wall>(m_wall));
	}
	m_objectSize.push_back((int)m_board.getWallVector().size());
}


//============================================= bool func ====================================//


//functions that get a sprite and check if there is a collision between the objects

bool Controller::isDoor(sf::Sprite& sprite, Location& loc) {

	for (int i = 0; i < m_objectSize[0]; i++)
	{
		if (m_ptrStaticObjects[i]->isObject(sprite))
		{
			loc.m_x = loc.m_y = i;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isGift(sf::Sprite& sprite, Location& loc) {

	int size = m_objectSize[0] + m_objectSize[1];
	for (int i = m_objectSize[0]; i < size; i++)
	{
		if (m_ptrStaticObjects[i]->isObject(sprite))
		{
			loc.m_y = i;
			loc.m_x = i - m_objectSize[0];
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isKey(sf::Sprite& sprite, Location& loc) {

	int index = m_objectSize[0] + m_objectSize[1];
	for (int i = 0; i < m_objectSize[2]; i++)
	{
		if (m_ptrStaticObjects[index++]->isObject(sprite))
		{
			loc.m_y = --index;
			loc.m_x = i;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isCheese(sf::Sprite& sprite, Location& loc) {

	int index = m_objectSize[0] + m_objectSize[1] + m_objectSize[2];
	for (int i = 0; i < m_objectSize[3]; i++)
	{
		if (m_ptrStaticObjects[index++]->isObject(sprite))
		{
			loc.m_y = --index;
			loc.m_x = i;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isWall(sf::Sprite& sprite, Location& loc) {

	int index = m_objectSize[0] + m_objectSize[1];
	index += m_objectSize[2] + m_objectSize[3];

	for (int i = 0; i < m_objectSize[4]; i++, index++)
	{
		if (m_ptrStaticObjects[index]->isObject(sprite))
		{
			loc.m_y = --index;
			loc.m_x = i;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isCat(sf::Sprite& sprite) {

	for (int i = 1; i < m_ptrMovingObject.size(); i++)
	{
		if (m_ptrMovingObject[i]->isObject(sprite))
		{
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------//
bool Controller::isMouse(sf::Sprite& sprite) {

	if (m_ptrMovingObject[0]->isObject(sprite))
	{
		return true;
	}
	return false;
}

//======================================= get/set func ====================================//

std::vector <int> Controller::getObjectSize() {

	return m_objectSize;
}
//-----------------------------------------------------//
unsigned int Controller::getSpecialKey() {

	return m_window.getSpecialKey();
}
//-----------------------------------------------------//
sf::Vector2f Controller::getMousePosition() {

	return m_ptrMovingObject[0]->getPosition();
}
//-----------------------------------------------------//
std::vector < std::unique_ptr <StaticObjects>>& Controller::getStaticVector() {

	return m_ptrStaticObjects;
}
//-----------------------------------------------------//
void Controller::addLife(int life) {

	m_life += life;
}
//-----------------------------------------------------//
void Controller::addPoints(int add) {

	m_points += add;
}
//-----------------------------------------------------//
void Controller::addKey(int add) {

	m_keys += add;
}
//-----------------------------------------------------//
int Controller::getKey()const {

	return m_keys;
}
//-----------------------------------------------------//
void Controller::setFreeze(int freeze) {

	m_catSeconds = (float)freeze;
}
//-----------------------------------------------------//
void Controller::setTime(int time) {

	m_gameTime += time;
}