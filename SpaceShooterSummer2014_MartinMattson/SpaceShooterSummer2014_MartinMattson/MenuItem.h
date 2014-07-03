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

	std::string GetChoice();
	void SetChoice(std::string p_sChoice);

private:
	std::string m_sState,
		m_sChoice;

	sf::Vector2f m_vPosition;

	// ~Insert graphics here~
};