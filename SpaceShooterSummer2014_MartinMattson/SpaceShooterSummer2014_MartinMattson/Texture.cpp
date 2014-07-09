// Texture.cpp //

#include "Texture.h"

Texture::Texture(){
	m_xpTexture = new sf::Texture;
}

Texture::~Texture(){
	delete m_xpTexture;
	m_xpTexture = NULL;
}

std::string Texture::GetName(){
	return m_sName;
}

void Texture::SetName(std::string p_sName){
	m_sName = p_sName;
}

sf::Texture* Texture::GetTexture(){
	return m_xpTexture;
}

void Texture::SetTexture(sf::Texture *p_xpTexture){

}