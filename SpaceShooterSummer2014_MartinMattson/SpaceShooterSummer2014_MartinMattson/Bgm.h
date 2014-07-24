// Bgm.h //

#pragma once

class Bgm {
public:
	Bgm(std::string p_sName, sf::Music *p_xpMusic);
	~Bgm();

	std::string GetName();
	void SetName(std::string p_sName);

	sf::Music* GetMusic();
	void SetMusic(sf::Music *p_xpMusic);

private:
	std::string m_sName;

	sf::Music *m_xpMusic;
};