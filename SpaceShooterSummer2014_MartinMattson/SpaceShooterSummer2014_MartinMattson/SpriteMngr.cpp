// SpriteMngr.cpp //

#include "SpriteMngr.h"

#include "Sprite.h"
#include "Texture.h"

std::string SpriteMngr::m_sDir;

std::vector<Sprite*> SpriteMngr::m_xpaSprites;
std::vector<Texture*> SpriteMngr::m_xpaTextures;

SpriteMngr::SpriteMngr(std::string p_sDir){
	// Sets the Directory variable
	m_sDir = p_sDir;
}

SpriteMngr::~SpriteMngr(){
	// Deletes all objects in both vector's and nulls the pointers
	for (int i = m_xpaSprites.size() - 1; i >= 0; i--){
		if (m_xpaSprites[i] != NULL){
			delete m_xpaSprites[i];
		}

	}

	for (int i = m_xpaTextures.size() - 1; i >= 0; i--){
		if (m_xpaTextures[i] != NULL){
			delete m_xpaTextures[i];
			m_xpaTextures[i] = NULL;
			m_xpaTextures.erase(m_xpaTextures.begin() + i);
		}
	}
}

Sprite* SpriteMngr::GetSprite(std::string p_sName){
	// Returns a sprite based on name given to one of the Textures
	for (int i = 0; i < m_xpaTextures.size(); i++){
		if (p_sName.compare(m_xpaTextures[i]->GetName()) == 0){
			// Creates a new Sprite and sets the Texture and then puts it at the back of the vector
			Sprite *_xpSprite = new Sprite;
			_xpSprite->GetSprite()->setTexture(*m_xpaTextures[i]->GetTexture());
			m_xpaSprites.push_back(_xpSprite);
			_xpSprite->SetName(p_sName);
			//Sets the origin point to the middle ofthe sprite as opposed to the upper left-hand corner
			_xpSprite->GetSprite()->setOrigin(_xpSprite->GetSprite()->getTextureRect().width / 2, _xpSprite->GetSprite()->getTextureRect().height / 2);

			// Returns the Sprite
			return _xpSprite;
		}
	}

	return NULL;
}

Texture* SpriteMngr::LoadTexture(std::string p_sName, std::string p_sFname, sf::IntRect p_xRect){
	// Creates a new Texture
	Texture *_xpTex = new Texture;

	// Checks if the Rectangle has any data, if it doesn't the entire image is turned into a Texture
	if (p_xRect.height == 0 && p_xRect.width == 0){
		if (!_xpTex->GetTexture()->loadFromFile(m_sDir + p_sFname)){
			return NULL;
		}
	}
	else {
		if (!_xpTex->GetTexture()->loadFromFile(m_sDir + p_sFname, p_xRect)){
			return NULL;
		}
	}

	// Sets the Texture to Smooth
	_xpTex->GetTexture()->setSmooth(true);

	// Sets the name of the texture and pushes it back in the vector
	_xpTex->SetName(p_sName);
	m_xpaTextures.push_back(_xpTex);

	return _xpTex;
}

void SpriteMngr::DeleteSprite(Sprite *p_xpSprite){
	// Nulls the sprites pointer
	for (int i = 0; i < m_xpaSprites.size(); i++){
		if (m_xpaSprites[i] == p_xpSprite){
			//delete m_xpaSprites[i];
			m_xpaSprites[i] = NULL;
			m_xpaSprites.erase(m_xpaSprites.begin() + i);
		}
	}
}

std::vector<Sprite*> SpriteMngr::GetVector(){
	// Returns the Sprite vector
	return m_xpaSprites;
}