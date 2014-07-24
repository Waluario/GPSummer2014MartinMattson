// Sfx.cpp //

#include "Sfx.h"

Sfx::Sfx(std::string p_sName, sf::SoundBuffer *p_xpSBuffer){
	m_sName = p_sName;
	m_xpSBuffer = p_xpSBuffer;
}

Sfx::~Sfx(){

}

std::string Sfx::GetName(){
	return m_sName;
}

void Sfx::SetName(std::string p_sName){
	m_sName = p_sName;
}

sf::SoundBuffer* Sfx::GetSoundBuffer(){
	return m_xpSBuffer;
}

void Sfx::SetSoundBuffer(sf::SoundBuffer *p_xpSBuffer){
	m_xpSBuffer = p_xpSBuffer;
}