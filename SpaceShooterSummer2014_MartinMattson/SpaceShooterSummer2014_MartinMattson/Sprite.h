// Sprite.h //

#pragma once

class Sprite : public sf::Sprite {
public:
	Sprite();
	~Sprite();
private:
	std::string m_sName;
};