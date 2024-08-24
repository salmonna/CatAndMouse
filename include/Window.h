
#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Window
{
public:
	Window(Menu menu);

	bool eventResponse();
	bool windowIsOpen();
	void display();
	void clear();
	void close();

	unsigned int getSpecialKey();
	sf::RenderWindow& getWindow();

	void creatWindow(float col, float row);
	sf::Event& getEvent();
	~Window();

private:
	
	unsigned int m_specialKey;

	Menu *m_menu;
	sf::Event m_event;

	sf::Sprite m_spriteRun;
	sf::RenderWindow m_window;

	void checkKeyPressed(sf::Event event);
	void checkMouseReleased(sf::Event event);
};


