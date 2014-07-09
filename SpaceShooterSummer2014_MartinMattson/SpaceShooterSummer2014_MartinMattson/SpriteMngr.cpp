// SpriteMngr.cpp //

#include "SpriteMngr.h"

#include "Sprite.h"
#include "Texture.h"

std::string SpriteMngr::m_sDir;

std::vector<Sprite*> SpriteMngr::m_xpaSprites;
std::vector<Texture*> SpriteMngr::m_xpaTextures;

SpriteMngr::SpriteMngr(std::string p_sDir){
	m_sDir = p_sDir;
}

SpriteMngr::~SpriteMngr(){
	for (int i = m_xpaSprites.size() - 1; i >= 0; i--){
		if (m_xpaSprites[i] != NULL){
			delete m_xpaSprites[i];
		}

		/*m_xpaSprites[i] = NULL;
		m_xpaSprites.erase(m_xpaSprites.begin() + i);*/
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
	for (int i = 0; i < m_xpaTextures.size(); i++){
		if (p_sName.compare(m_xpaTextures[i]->GetName()) == 0){
			Sprite *_xpSprite = new Sprite;
			_xpSprite->GetSprite()->setTexture(*m_xpaTextures[i]->GetTexture());
			m_xpaSprites.push_back(_xpSprite);
			_xpSprite->SetName(p_sName);
			_xpSprite->GetSprite()->setOrigin(_xpSprite->GetSprite()->getTextureRect().width / 2, _xpSprite->GetSprite()->getTextureRect().height / 2);

			return _xpSprite;
		}
	}

	return NULL;
}

Texture* SpriteMngr::LoadTexture(std::string p_sName, std::string p_sFname, sf::IntRect p_xRect){
	Texture *_xpTex = new Texture;

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

	_xpTex->GetTexture()->setSmooth(true);

	/*Sprite *_xpSprite = new Sprite;
	_xpSprite->setTexture(_xTex);
	_xpSprite->SetName(p_sName);

	_xpSprite->setOrigin(_xpSprite->getTextureRect().width / 2, _xpSprite->getTextureRect().height / 2);

	m_xpaSprites.push_back(_xpSprite);*/

	_xpTex->SetName(p_sName);
	m_xpaTextures.push_back(_xpTex);

	return _xpTex;
}

void SpriteMngr::DeleteSprite(Sprite *p_xpSprite){
	for (int i = 0; i < m_xpaSprites.size(); i++){
		if (m_xpaSprites[i] == p_xpSprite){
			//delete m_xpaSprites[i];
			m_xpaSprites[i] = NULL;
			m_xpaSprites.erase(m_xpaSprites.begin() + i);
		}
	}
}

std::vector<Sprite*> SpriteMngr::GetVector(){
	return m_xpaSprites;
}