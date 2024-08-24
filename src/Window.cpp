//================================ include =========================//

#pragma once
#include <iostream>
#include <Window.h>
#include <fstream>

//============================== constractor =============================//


Window::Window(Menu menu):m_specialKey(0),m_menu(&menu)
{	
}

//================================ func ====================================//

void Window::creatWindow(float col, float row) {

	m_window.create(sf::VideoMode(unsigned int(col) * 50, unsigned int(row) * 50), "Mouse and Cat");
}
//---------------------------------------------------------//
void Window::close() {
	m_window.close();
}
//---------------------------------------------------------//
bool Window::windowIsOpen() {

	return m_window.isOpen();
}
//------------------------------------------------------------------//
void Window::display() {

	m_window.display();
}
//------------------------------------------------------------------//
void Window::clear() {

	m_window.clear();
}


//================================ event func ====================================//


bool Window::eventResponse() {

	if (auto event = sf::Event{}; m_window.pollEvent(event)) {

		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);

		case sf::Event::MouseButtonReleased:

			checkMouseReleased(event);
			return false;

		case sf::Event::KeyPressed:
			checkKeyPressed(event);
			return true;
			break;

		case sf::Event::KeyReleased:
			return false;
			break;
		}
	}
	m_event.mouseButton.x = 0;
	m_event.mouseButton.y = 0;
	return false;
}
//------------------------------------------------------------------//
void Window::checkKeyPressed(sf::Event event) {

	if (sf::Keyboard::Right == event.size.width)
	{
		m_specialKey = 77;
	}
	else if (sf::Keyboard::Left == event.size.width)
	{
		m_specialKey = 75;
	}
	else if (sf::Keyboard::Up == event.size.width)
	{
		m_specialKey = 72;
	}
	else if (sf::Keyboard::Down == event.size.width)
	{
		m_specialKey = 80;
	}
	else
	{
		m_specialKey = 0;
	}
}
//------------------------------------------------------------------//
void Window::checkMouseReleased(sf::Event event) {
	
	sf::Vector2f vector(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
	switch (event.mouseButton.button)
	{
	case sf::Mouse::Button::Left:

		m_event = event;
		return;
	}
	m_event.mouseButton.x = 0;
	m_event.mouseButton.y = 0;
}


//================================ get/set func ====================================//

sf::RenderWindow& Window::getWindow() {

	return m_window;
}
//------------------------------------------------------------------//
unsigned int Window::getSpecialKey() {

	return m_specialKey;
}
//-----------------------------------------------------------------//
sf::Event& Window::getEvent() {

	return m_event;
}

//============================== distractor =============================//

Window::~Window(){


}