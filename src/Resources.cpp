
//================================ include =========================//

#include "Resources.h"
#include <iostream>
#include <string.h>

//============================== constractor =============================//

Resources::Resources()
{

	std::vector<std::string> fileNames{"Background.png" ,"Mouse.png", "Cat.png", "Door.png", "Gift.png" ,
										"Key.png","Cheese.png" ,"Wall.png"};

	sf::Texture texture;
	for (int i = 0; i < fileNames.size(); i++)
	{
		if (!texture.loadFromFile(fileNames[i])) {
			std::cerr << "textur file not loat!" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_textureVector.push_back(texture);
	}

	std::vector<std::string> soundNames{ "CatSound.wav", "CheeseSound.wav", "ObjectSound.wav" };

	sf::SoundBuffer soundBuffer;
	for (int i = 0; i < soundNames.size(); i++)
	{
		if (!soundBuffer.loadFromFile(soundNames[i])) {
			std::cerr << "sound buffer file not load!" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_SoundBufferVector.push_back(soundBuffer);
	}

	if (!m_font.loadFromFile("FontFile.otf")) {
		std::cerr << "font file not load!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::vector<std::string> menuFileNames{ "Start.png", "Help.png", "Exit.png", "NextLevel.png"};

	for (int i = 0; i < menuFileNames.size(); i++)
	{
		if (!texture.loadFromFile(menuFileNames[i])) {
			std::cerr << "textur menu file not load!" << std::endl;
			exit(EXIT_FAILURE);
		}
		m_textureVectorMenu.push_back(texture);
	}

	if (!m_music.openFromFile("Music.wav"))
	{
		std::cerr << "music file not load!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		m_music.setLoop(true);
		m_music.setVolume(3);
		m_music.play();
	}
}

//================================ get/set func ====================================//

sf::Music& Resources::getMusic() {

	return m_music;
}
//-----------------------------------------------------------------------//
sf::Font& Resources::getFont() {

	return m_font;
}
//-----------------------------------------------------------------------//
sf::Texture Resources::getTextureVector(int index) {

	return m_textureVector[index];
}
//-----------------------------------------------------------------------//
sf::Texture Resources::getTextureVectorMenu(int index) {

	return m_textureVectorMenu[index];
}
//-----------------------------------------------------------------------//
sf::SoundBuffer& Resources::getSoundBufferVector(int index) {

	return m_SoundBufferVector[index];
}


Resources::~Resources() {

	m_music.stop();

}