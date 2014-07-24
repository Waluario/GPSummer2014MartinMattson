// FontMngr.h //

#pragma once

#include <vector>

class Font;

class FontMngr {
public:
	FontMngr(std::string p_sPath);
	~FontMngr();

	static void NewFont(std::string p_sName, std::string p_sFname); // Creates a new font

	static sf::Font* GetFont(std::string p_sName); // Returns a desired font

private:
	static std::string m_sPath; // The filepath that from where the fonts will be loaded

	static std::vector<Font*> m_xpaFonts;
};