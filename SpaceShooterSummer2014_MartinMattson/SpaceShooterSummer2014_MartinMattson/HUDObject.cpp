// HUDObject.cpp //

#include "HUDObject.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "ScoreMngr.h"

#include <sstream>

HUDObject::HUDObject(){
	m_xRect = sf::RectangleShape(sf::Vector2f(800.f, 50.f));
	m_xRect.setFillColor(sf::Color(0x0, 0x0, 0xFF));
	m_xRect.setPosition(0, 550);

	m_xpScore = new sf::Text(sf::String(std::string("Score: ")), *FontMngr::GetFont("Arial"), 20);
	m_xpScore->setPosition(0, 550);

	m_xpHiScore = new sf::Text(sf::String(std::string("High-Score: ")), *FontMngr::GetFont("Arial"), 20);
	m_xpHiScore->setPosition(0, 575);

	m_xpLife = new sf::Text(sf::String(std::string("Life: ")), *FontMngr::GetFont("Arial"), 20);
	m_xpLife->setPosition(400, 575);
}

HUDObject::~HUDObject(){

}

void HUDObject::SetAllPositions(sf::Vector2f p_vPosition){

}

void HUDObject::OnCreate(){

}

void HUDObject::OnUpdateThis(){
	int _i;

	_i = ScoreMngr::GetScore();

	m_xpScore->setString("Score: " + static_cast<std::ostringstream*>( &(std::ostringstream() << ScoreMngr::GetScore()) )->str());
	m_xpHiScore->setString("HiScore: " + static_cast<std::ostringstream*>(&(std::ostringstream() << ScoreMngr::GetHiScore()))->str());
	m_xpLife->setString("Life: " + static_cast<std::ostringstream*>(&(std::ostringstream() << ScoreMngr::GetLifes()))->str());
}

void HUDObject::OnDrawThis(){
	DrawMngr::GetScreen()->draw(m_xRect);

	DrawMngr::Draw(m_xpScore);
	DrawMngr::Draw(m_xpHiScore);
	DrawMngr::Draw(m_xpLife);
}

void HUDObject::OnCollision(GameObject *p_xpCollider){

}