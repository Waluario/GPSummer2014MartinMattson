// OptionsItem2.h //

#pragma once

#include "MenuItem.h"

class OptionsItem2 : public MenuItem {
public:
	OptionsItem2(sf::Vector2f p_vPos, std::string p_sText, float &p_frOption, float p_fMin, float p_fMax, float p_fChange);
	~OptionsItem2();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	virtual sf::Text* GetText();
	virtual void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();

private:
	float *m_fpOption,
		m_fMin,
		m_fMax,
		m_fChange;

	sf::Text *m_xpText;

	std::string m_sChoice;
};