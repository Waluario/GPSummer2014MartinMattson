// DrawMngr.cpp //

#include "DrawMngr.h"

#include "Sprite.h"

sf::RenderWindow *DrawMngr::m_xpScreen;

DrawMngr::DrawMngr(sf::RenderWindow *p_xpScreen){
	m_xpScreen = p_xpScreen;
}

DrawMngr::~DrawMngr(){
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
	// Uses the screen to draw items in-game
	m_xpScreen->draw(*p_xpDrawable);
}

void DrawMngr::Present(){
	// Uses the screen to display all items in-game
	m_xpScreen->display();
}

void DrawMngr::Clear(){
	// Clears the screen
	m_xpScreen->clear();
}

void DrawMngr::SetScreen(sf::RenderWindow *p_xpScreen){
	// Sets the screen
	m_xpScreen = p_xpScreen;
}

sf::RenderWindow* DrawMngr::GetScreen(){
	// Returns the screen
	return m_xpScreen;
}