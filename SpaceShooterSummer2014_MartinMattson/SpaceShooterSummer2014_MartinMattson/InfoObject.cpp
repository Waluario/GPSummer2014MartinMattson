// InfoObject.cpp //

#include "InfoObject.h"

#include "DrawMngr.h"
#include "FontMngr.h"

#include <fstream>
#include <sstream>

InfoObject::InfoObject(sf::Vector2f p_vPosition, std::string p_sFile){
	std::ifstream stream;
	stream.open(p_sFile.c_str());

	if (!stream.is_open()){
		return;
	}

	std::string row;
	stream >> row;

	if (!stream.is_open()){
		return;
	}

	while (!stream.eof()){
		std::getline(stream, row);

		if (row.length() == 0){
			m_xpaText.push_back(new sf::Text(sf::String(" "), *FontMngr::GetFont("Arial")));
		}
		else if (row.length() != 0){
			m_xpaText.push_back(new sf::Text(sf::String(std::string(row)), *FontMngr::GetFont("Arial")));
		}
	}

	stream.close();

	SetAllPositions(p_vPosition);
}

InfoObject::~InfoObject(){
	for (int i = m_xpaText.size() - 1; i >= 0; i--){
		delete m_xpaText[i];
		m_xpaText[i] = NULL;
		m_xpaText.erase(m_xpaText.begin() + i);
	}
}

void InfoObject::SetAllPositions(sf::Vector2f p_vPosition){
	// Sets the position of all text in the credits
	setPosition(p_vPosition);

	for (int i = 0; i < m_xpaText.size(); i++){
		m_xpaText[i]->setPosition(getPosition().x, getPosition().y + 30.f * i);
	}
}

void InfoObject::OnCreate(){

}

void InfoObject::OnUpdateThis(){

}

void InfoObject::OnDrawThis(){
	for (int i = 0; i < m_xpaText.size(); i++){
		DrawMngr::Draw(m_xpaText[i]);
	}
}

void InfoObject::OnCollision(GameObject *p_xpCollider){

}