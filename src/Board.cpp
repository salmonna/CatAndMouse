
//================================ include =========================//

#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


//============================== constractor =============================//

Board::Board():m_col(0), m_row(0), m_mouse()
{
}

//================================ func ====================================//


//function that get a file name and open, read and update the data. 
void Board::readFile(std::string fileName) {

	auto file = std::ifstream(fileName);
	int maxCol = 0;
	file.clear();
	file.seekg(0);
	
	auto line = std::string();
	clearBoard();
	while (std::getline(file, line))
	{
		maxCol = (int)line.size();
		if (maxCol > m_col)
		{
			m_col = maxCol;
		}
		searchObject(line);
		m_row++;
	}
	m_topLeft.x = 3.0f * m_col;
	m_topLeft.y = 2.0f * m_row;
}
//------------------------------------------------------------------//
//function that clear the data board
void Board::clearBoard() {

	m_col = 0;
	m_row = 0;
	m_mouse.m_x = m_mouse.m_y = 0;
	m_cats.clear();
	m_cheeses.clear();
	m_doors.clear();
	m_gifts.clear();
	m_keys.clear();
	m_wall.clear();
}
//------------------------------------------------------------------//
void Board::clearVector() {
	m_texturVector.clear();
}
//------------------------------------------------------------------//
//func that search object at line
void Board::searchObject(std::string line) {

	Location loc;
	loc.m_y = m_row;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ') {
			loc.m_x = i;
			addObject(line[i], loc);
		}
	}
}
//------------------------------------------------------------------//
//func that add onject to the vctor
void Board::addObject(char object, Location loc) {

	switch (object)
	{
	case '%':
		m_mouse = loc;
		break;
	case '^':
		m_cats.push_back(loc);
		break;
	case '#':
		m_wall.push_back(loc);
		break;
	case '$':
		m_gifts.push_back(loc);
		break;
	case 'D':
		m_doors.push_back(loc);
		break;
	case 'F':
		m_keys.push_back(loc);
		break;
	case '*': 
		m_cheeses.push_back(loc);
		break;

	default:
		break;
	}
}
//------------------------------------------------------------------//
void Board::draw(sf::RenderWindow& window) {

	sf::Sprite sprite;

	for (int i = 0; i < m_texturVector.size(); i++)
	{
		sprite = sf::Sprite(m_texturVector[i]);
		setPosition(sprite, i);
		window.draw(sprite);
	}
}


//================================ get/set func ====================================//

//get vector of the objects locations  

std::vector <Location> Board::getCatsVector()const {

	return m_cats;
}
//------------------------------------------------------------------//
std::vector <Location> Board::getCheesesVector()const {

	return m_cheeses;
}
//------------------------------------------------------------------//
std::vector <Location> Board::getGiftsVector()const {

	return m_gifts;
}
//------------------------------------------------------------------//
std::vector <Location> Board::getKeysVector()const {

	return m_keys;
}
//------------------------------------------------------------------//
std::vector <Location> Board::getDoorVector()const {

	return m_doors;
}
//------------------------------------------------------------------//
std::vector <Location> Board::getWallVector()const {

	return m_wall;
}
//------------------------------------------------------------------//
Location Board::getMouse()const {

	return m_mouse;
}
//------------------------------------------------------------------//


sf::Vector2f Board::getTopLeft()const {

	return m_topLeft;
}
//------------------------------------------------------------------//
float Board::getRow()const {

	return (float)m_row;
}
//------------------------------------------------------------------//
float Board::getCol()const {

	return (float)m_col;
}
//------------------------------------------------------------------//
void Board::setTexture(sf::Texture textur) {

	m_texturVector.push_back(textur);
}
//------------------------------------------------------------------//
void Board::setPosition(sf::Sprite& sprite, int index) {

	if (index == 0)//Background
	{
		sprite.scale(m_col / 8.0f, m_row / 8.0f);
	}
}


//============================== distractor =============================//

Board::~Board()
{

}