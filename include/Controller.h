
//================================ include =========================//

#pragma once
#include "Window.h"
#include "Resources.h"
#include "Board.h"
#include "Mouse.h"
#include "Cat.h"
#include "Gift.h"
#include "Door.h"
#include "Key.h"
#include "Cheese.h"
#include "Wall.h"
#include "MovingObject.h"
#include "StaticObjects.h"
#include "Menu.h"
#include <memory>

class Controller
{
public:
	Controller();
	
	void eraserObject(Location loc);
	void eraserCat();

	bool isCheese(sf::Sprite& sprite, Location& loc);
	bool isGift(sf::Sprite& sprite, Location& loc);
	bool isKey(sf::Sprite& sprite, Location& loc);
	bool isDoor(sf::Sprite& sprite, Location& loc);
	bool isWall(sf::Sprite& sprite, Location& loc);
	bool isCat(sf::Sprite& sprite);
	bool isMouse(sf::Sprite& sprite);
	
	void restart();

	void setTime(int time);
	unsigned int getSpecialKey();
	sf::Vector2f getMousePosition();
	std::vector< std::unique_ptr <StaticObjects>>& getStaticVector();
	std::vector <int> getObjectSize();
	int getKey()const;

	void addLife(int life);
	void addPoints(int add);
	void addKey(int add);
	void setFreeze(int freeze);

private:
	
	void runGame();
	void catsTurn();
	void draw();
	void clearAll();
	void endGame();
	void openingMenu();
	void endMenu();

	void initialization();
	void initBoard();
	void initMouse();
	void initCat();
	void initDoor();
	void initGift();
	void initKey();
	void initCheese();
	void initWall();

	unsigned int m_specialKey;

	int m_life;
	int m_keys;
	int m_points;
	int m_level;
	int m_freeze;

	int m_gameMinuts;
	int m_gameSecond;
	float m_catSeconds;
	float m_gameTime;

	sf::Clock m_catClock;
	sf::Clock m_gameClock;

	sf::Text m_text;
	Board m_board;
	Menu m_menu;
	Window m_window;

	std::vector <std::unique_ptr<StaticObjects>> m_ptrStaticObjects;
	std::vector <std::unique_ptr <MovingObject>> m_ptrMovingObject;

	Mouse m_mouse;
	Cat m_cat;
	Door m_door;
	Key m_key;
	Cheese m_cheese;
	Wall m_wall;

	std::vector <int> m_objectSize;
};