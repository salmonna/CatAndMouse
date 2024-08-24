
//================================ include =========================//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Resources
{
public:

	static Resources& getInstance() {
		static Resources instance;
		return instance;
	}

	sf::Texture getTextureVector(int index);
	sf::SoundBuffer& getSoundBufferVector(int index);
	sf::Texture getTextureVectorMenu(int index);
	sf::Font& getFont();
	sf::Music& getMusic();

private:

	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	Resources();
	~Resources();

	sf::Music m_music;
	sf::Font m_font;
	std::vector<sf::Texture> m_textureVector;
	std::vector<sf::SoundBuffer> m_SoundBufferVector;
	std::vector<sf::Texture> m_textureVectorMenu;
};

