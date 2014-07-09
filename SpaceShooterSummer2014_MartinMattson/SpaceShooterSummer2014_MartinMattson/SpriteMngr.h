// SpriteMngr.h //

#pragma once

#include <vector>

class Sprite;
class Texture;

class SpriteMngr {
public:
	SpriteMngr(std::string p_sDir);
	~SpriteMngr();

	static Sprite* GetSprite(std::string p_sName);

	static Texture* LoadTexture(std::string p_sName, std::string p_sFname, sf::IntRect p_xRect = sf::IntRect(0, 0, 0, 0));

	static void DeleteSprite(Sprite *p_xpSprite);
	
	static std::vector<Sprite*> GetVector();

private:
	static std::string m_sDir;
	
	static std::vector<Sprite*> m_xpaSprites;
	static std::vector<Texture*> m_xpaTextures;
};