// Sprite.h //

#pragma once

class Sprite {
public:
	Sprite();
	~Sprite();

	std::string GetName();
	void SetName(std::string p_sName);

	sf::Sprite* GetSprite();
	void SetSprite(sf::Sprite *p_xpSprite);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f p_vPosition);

private:
	std::string m_sName;

	sf::Sprite *m_xpSprite;
};