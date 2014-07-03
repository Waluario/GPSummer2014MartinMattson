// Font.h //

#pragma once

class Font : public sf::Font {
public:
	Font(std::string p_sName, std::string p_sFname);
	~Font();

	std::string GetName();
	void SetName(std::string p_sName);

private:
	std::string m_sName;
};