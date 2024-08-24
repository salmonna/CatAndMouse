

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Location.h"
#include <fstream>

class Board
{
public:
	Board();

	sf::Vector2f getTopLeft()const;
	std::vector <Location> getCatsVector()const;
	std::vector <Location> getGiftsVector()const;
	std::vector <Location> getCheesesVector()const;

	std::vector <Location> getKeysVector()const;
	std::vector <Location> getDoorVector()const;
	std::vector <Location> getWallVector()const;

	Location getMouse()const;

	void setTexture(sf::Texture textur);

	void clearVector();
	void clearBoard();

	void readFile(std::string fileName);
	void draw(sf::RenderWindow& window);

	float getRow()const;
	float getCol()const;

	virtual ~Board();

private:

	int m_row;
	int m_col;

	Location m_mouse;
	sf::Texture m_textur;
	sf::Vector2f m_topLeft;

	std::vector <Location> m_cats;
	std::vector <Location> m_cheeses;
	std::vector <Location> m_keys;
	std::vector <Location> m_doors;
	std::vector <Location> m_wall;
	std::vector <Location> m_gifts;
	std::vector<sf::Texture> m_texturVector;

	void searchObject(std::string line);
	void addObject(char object, Location loc);
	void setPosition(sf::Sprite& sprite, int index);

};