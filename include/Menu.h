
#pragma once
#include "Resources.h"

class Window;

class Menu
{
public:
	Menu();

	void checkReleased(sf::RenderWindow& window, sf::Event event);

	void draw(sf::RenderWindow& window);
	void drawHelp(sf::RenderWindow& window, sf::Text* text);
	void drawNextLevel(sf::RenderWindow& window, sf::Text* text, int points);

	sf::Sprite getNextLevelSprite();
	sf::Sprite getExitSprite();
	sf::Sprite getHelpSprite();
	sf::Sprite getStartSprite();
	void setTopLeft(sf::Vector2f topLeft);

	void setOpenMenu(bool openMenu);
	void setEndMenu(bool endMenu);
	bool openMenu() const;
	bool endMenu() const;

	bool isHelp() const;
	bool isExit() const;
	bool isStart() const;
	bool isNextLevel() const;

	void setHelp(bool help);
	void setExit(bool exit);
	void setStart(bool restart);
	void setNextLevel(bool nextLevel);

private:

	sf::Vector2f m_topLeft;

	bool m_help;
	bool m_start;
	bool m_exit;
	bool m_nextLevel;

	bool m_openMenu;
	bool m_endMenu;

	sf::Text m_text;

	sf::Texture m_exitTextur;
	sf::Texture m_helpTextur;
	sf::Texture m_startTextur;
	sf::Texture m_nextLevelTextur;

	sf::Sprite m_exitSprite;
	sf::Sprite m_helpSprite;
	sf::Sprite m_startSprite;
	sf::Sprite m_nextLevelSprite;
};


