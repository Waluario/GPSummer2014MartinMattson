// Texture.h //

#pragma once

class Texture {
public:
	Texture();
	~Texture();

	std::string GetName();
	void SetName(std::string p_sName);

	sf::Texture* GetTexture();
	void SetTexture(sf::Texture *p_xpTexture);

private:
	std::string m_sName;

	sf::Texture *m_xpTexture;
};