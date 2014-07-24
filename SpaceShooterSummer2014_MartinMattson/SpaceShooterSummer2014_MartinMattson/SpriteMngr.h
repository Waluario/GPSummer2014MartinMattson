// SpriteMngr.h //

#pragma once

#include <vector>

class Sprite;
class Texture;

class SpriteMngr {
public:
	SpriteMngr(std::string p_sDir);
	~SpriteMngr();

	static Sprite* GetSprite(std::string p_sName); // Retruns a Sprite with the requested name

	static Texture* LoadTexture(std::string p_sName, std::string p_sFname, sf::IntRect p_xRect = sf::IntRect(0, 0, 0, 0)); // Loads a new texture

	static void DeleteSprite(Sprite *p_xpSprite); // Removes a Sprite
	
	static std::vector<Sprite*> GetVector(); // Returns the Sprite vector

private:
	static std::string m_sDir; // The directory from where the Textures are loaded
	
	static std::vector<Sprite*> m_xpaSprites; // Vector that stores all of the Sprites
	static std::vector<Texture*> m_xpaTextures; // Vector that scotores all of the Textures
};