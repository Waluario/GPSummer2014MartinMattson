// SpriteMngr.cpp //

#include "SpriteMngr.h"

#include "Sprite.h"

std::string SpriteMngr::m_sDir;

std::map<std::string, Sprite*> SpriteMngr::m_xpaSprites;

SpriteMngr::SpriteMngr(std::string p_sDir){
	m_sDir = p_sDir;
}

SpriteMngr::~SpriteMngr(){

}

Sprite* SpriteMngr::LoadSprite(std::string p_sFname, sf::IntRect p_xRect){
	sf::Texture l_xTex;

	if (p_xRect.height == 0 && p_xRect.width == 0){
		if (!l_xTex.loadFromFile(m_sDir + p_sFname)){
			return NULL;
		}
	}
	else {
		if (!l_xTex.loadFromFile(m_sDir + p_sFname, p_xRect)){
			return NULL;
		}
	}

	Sprite l_xSprite;
	l_xSprite.setTexture(l_xTex);

	return new Sprite(l_xSprite);
}