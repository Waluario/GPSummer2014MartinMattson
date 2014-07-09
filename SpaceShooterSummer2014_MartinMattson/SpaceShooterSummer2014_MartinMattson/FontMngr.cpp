// FontMngr.cpp //

#include "FontMngr.h"

#include "Font.h"

std::string FontMngr::m_sPath;

std::vector<Font*> FontMngr::m_xpaFonts;

FontMngr::FontMngr(std::string p_sPath){
	m_sPath = p_sPath;
}

FontMngr::~FontMngr(){
	for (int i = m_xpaFonts.size() - 1; i >= 0; i--){
		delete m_xpaFonts[i];
		m_xpaFonts[i] = NULL;
		m_xpaFonts.erase(m_xpaFonts.begin() + i);
	}
}

void FontMngr::NewFont(std::string p_sName, std::string p_sFname){
	m_xpaFonts.push_back(new Font(p_sName, m_sPath + p_sFname));
}

sf::Font* FontMngr::GetFont(std::string p_sName){
	for (int i = 0; i < m_xpaFonts.size(); i++){
		if (p_sName.compare(m_xpaFonts[i]->GetName()) == 0){
			return m_xpaFonts[i];
		}
	}
}