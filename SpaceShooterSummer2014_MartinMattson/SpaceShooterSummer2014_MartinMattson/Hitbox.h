// Hitbox.h //

#pragma once

class Hitbox {
public:
	Hitbox();
	Hitbox(float p_f);
	~Hitbox();

	float GetSize();
	void SetSize(float p_f);

	bool Overlap(sf::Vector2f p_vPos0, sf::Vector2f p_vPos1, float p_fSize);

private:
	float m_fSize;
};