// DrawMngr.cpp //

#include "DrawMngr.h"

#include "Sprite.h"

sf::RenderWindow *DrawMngr::m_xpScreen;

DrawMngr::DrawMngr(sf::RenderWindow *p_xpScreen){
	m_xpScreen = p_xpScreen;
}

DrawMngr::~DrawMngr(){

}

void DrawMngr::DrawSprite(Sprite *p_xpSprite){
	m_xpScreen->draw(*p_xpSprite);
}

void DrawMngr::DrawTexture(sf::Texture *p_xpTexture){
	//m_xpScreen->draw(*p_xpTexture);
}

void DrawMngr::Present(){
	m_xpScreen->display();
}

void DrawMngr::Clear(){
	m_xpScreen->clear();
}

void DrawMngr::SetScreen(sf::RenderWindow *p_xpScreen){
	m_xpScreen = p_xpScreen;
}

sf::RenderWindow* DrawMngr::GetScreen(){
	return m_xpScreen;
}