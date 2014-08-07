// MenuItem.h //

#pragma once

class MenuItem {
public:
	MenuItem(std::string p_sState, std::string p_sChoice, sf::Vector2f p_vPosition);
	~MenuItem();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f p_vPosition);

	std::string GetState();
	void SetState(std::string p_sState);

	sf::Text* GetText();
	void SetText(sf::Text *p_xpChoice);

	void OnDraw();
	void OnDrawWhenChosen();

	virtual void OnChosen();
	virtual bool CanMovePointer();

private:
	std::string m_sState;

	sf::Text *m_xpChoice;
};