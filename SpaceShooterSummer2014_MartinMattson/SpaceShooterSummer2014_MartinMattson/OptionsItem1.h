// OptionsItem1.h //

#pragma once

#include "MenuItem.h"

class OptionsItem1 : public MenuItem {
public:
	OptionsItem1(sf::Vector2f p_vPos, std::string p_sText, int &p_irOption, int p_iMin, int p_iMax);
	~OptionsItem1();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	virtual sf::Text* GetText();
	virtual void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();

private:
	int *m_ipOption,
		m_iMin,
		m_iMax;

	sf::Text *m_xpText;

	std::string m_sChoice;
};