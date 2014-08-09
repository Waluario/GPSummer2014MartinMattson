// MenuItem.h //

#pragma once

class MenuItem {
public:
	MenuItem(std::string p_sState, std::string p_sChoice, sf::Vector2f p_vPosition);
	~MenuItem();

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f p_vPosition);

	std::string GetState();
	void SetState(std::string p_sState);

	sf::Text* GetText();
	void SetText(sf::Text *p_xpChoice);

	virtual void OnDraw();
	virtual void OnDrawWhenChosen();

	virtual void OnChosen();
	virtual bool CanMovePointer();
	virtual bool IgnoreOption();

private:
	std::string m_sState;

	sf::Text *m_xpChoice;
};