// OptionsItem3.h //

#pragma once

#include "MenuItem.h"

class OptionsItem3 : public MenuItem {
public:
	OptionsItem3(sf::Vector2f p_vPos, std::string p_sText, int p_iKeyb);
	~OptionsItem3();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	virtual sf::Text* GetText();
	virtual void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();

private:
	int m_iKeyb;

	sf::Text *m_xpText;

	std::string m_sChoice;
};