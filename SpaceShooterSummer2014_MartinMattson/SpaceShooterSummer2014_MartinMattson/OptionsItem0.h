// OptionsItem0.h //

#pragma once

#include "MenuItem.h"

class OptionsItem0 : public MenuItem {
public:
	OptionsItem0(sf::Vector2f p_vPos, std::string p_sText, bool &p_bpOption, bool p_bShowOption);
	~OptionsItem0();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	virtual sf::Text* GetText();
	virtual void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();

private:
	bool *m_bpOption,
		m_bShowOption;

	sf::Text *m_xpText;

	std::string m_sChoice;
};