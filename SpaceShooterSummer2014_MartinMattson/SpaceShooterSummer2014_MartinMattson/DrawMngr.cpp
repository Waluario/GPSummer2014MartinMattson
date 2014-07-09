// DrawMngr.cpp //

#include "DrawMngr.h"

#include "Sprite.h"

sf::RenderWindow *DrawMngr::m_xpScreen;

DrawMngr::DrawMngr(sf::RenderWindow *p_xpScreen){
	m_xpScreen = p_xpScreen;
}

DrawMngr::~DrawMngr(){
	delete m_xpScreen;
	m_xpScreen = NULL;
}

void DrawMngr::DrawSprite(Sprite *p_xpSprite){
	m_xpScreen->draw(*p_xpSprite->GetSprite());
}

void DrawMngr::DrawText(sf::Text *p_xpText){
	m_xpScreen->draw(*p_xpText);
}

void DrawMngr::DrawTexture(sf::Texture *p_xpTexture){
	//m_xpScreen->draw(*p_xpTexture);
}

void DrawMngr::Draw(sf::Drawable *p_xpDrawable){
	m_xpScreen->draw(*p_xpDrawable);
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