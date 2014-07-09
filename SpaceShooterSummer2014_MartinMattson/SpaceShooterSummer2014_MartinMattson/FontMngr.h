// FontMngr.h //

#pragma once

#include <vector>

class Font;

class FontMngr {
public:
	FontMngr(std::string p_sPath);
	~FontMngr();

	static void NewFont(std::string p_sName, std::string p_sFname);

	static sf::Font* GetFont(std::string p_sName);

private:
	static std::string m_sPath;

	static std::vector<Font*> m_xpaFonts;
};