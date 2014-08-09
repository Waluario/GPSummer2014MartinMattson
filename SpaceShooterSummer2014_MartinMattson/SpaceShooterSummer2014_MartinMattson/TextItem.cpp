// TextItem.cpp //

#include "TextItem.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"
#include "StateMngr.h"

TextItem::TextItem(std::string p_sText, sf::Vector2f p_vPosition)
: MenuItem(" ", " ", sf::Vector2f(0, 0)){
	m_xpText = new sf::Text(sf::String(p_sText), *FontMngr::GetFont("Arial"));
	m_xpText->setPosition(p_vPosition);
}

TextItem::~TextItem(){
	delete m_xpText;
	m_xpText = NULL;
}

sf::Vector2f TextItem::GetPosition(){
	return m_xpText->getPosition();
}

void TextItem::SetPosition(sf::Vector2f p_vPosition){
	m_xpText->setPosition(p_vPosition);
}

sf::Text* TextItem::GetText(){
	return m_xpText;
}

void TextItem::SetText(sf::Text *p_xpChoice){
	m_xpText = p_xpChoice;
}

void TextItem::OnDraw(){
	DrawMngr::DrawText(m_xpText);
}

void TextItem::OnDrawWhenChosen(){
	OnDraw();
}

void TextItem::OnChosen(){
	
}

bool TextItem::IgnoreOption(){
	return true;
}