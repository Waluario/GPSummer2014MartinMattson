// Button.h //

#pragma once

class Button {
public:
	Button();
	Button(sf::Keyboard::Key p_xKey);
	~Button();

	void Update(float p_fDtime);

	bool IsPressed();
	bool IsPressedOnce();
	float GetTimer();

	void SetKey(sf::Keyboard::Key p_xKey);

	std::string GetKeySymbol();

private:
	float m_fTimer;
	bool m_bPressedOnce;

	sf::Keyboard::Key m_xKey;
};