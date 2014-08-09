// TextItem.h //

#pragma once

#include "MenuItem.h"

class TextItem : public MenuItem {
public:
	TextItem(std::string p_sText, sf::Vector2f p_vPosition);
	~TextItem();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	sf::Text* GetText();
	void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();

	virtual bool IgnoreOption();

private:
	sf::Text *m_xpText;
};