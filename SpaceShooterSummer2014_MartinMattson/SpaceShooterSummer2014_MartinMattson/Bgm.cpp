// Bgm.cpp //

#include "Bgm.h"

Bgm::Bgm(std::string p_sName, sf::Music *p_xpMusic){
	m_sName = p_sName;
	m_xpMusic = p_xpMusic;
}

Bgm::~Bgm(){

}

std::string Bgm::GetName(){
	return m_sName;
}

void Bgm::SetName(std::string p_sName){
	m_sName = p_sName;
}

sf::Music* Bgm::GetMusic(){
	return m_xpMusic;
}

void Bgm::SetMusic(sf::Music *p_xpMusic){
	m_xpMusic = p_xpMusic;
}