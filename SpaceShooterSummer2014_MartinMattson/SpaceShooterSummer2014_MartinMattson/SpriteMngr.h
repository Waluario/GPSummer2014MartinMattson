// SpriteMngr.h //

#pragma once

class Sprite;

class SpriteMngr {
public:
	SpriteMngr(std::string p_sDir);
	~SpriteMngr();

	static Sprite* LoadSprite(std::string p_sFname, sf::IntRect p_xRect = sf::IntRect(0, 0, 0, 0));

private:
	static std::string m_sDir;
	
	static std::map<std::string, Sprite*> m_xpaSprites;
};