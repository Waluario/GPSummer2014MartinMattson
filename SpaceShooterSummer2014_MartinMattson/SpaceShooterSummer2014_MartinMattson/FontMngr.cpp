// FontMngr.cpp //

#include "FontMngr.h"

#include "Font.h"

FontMngr::FontMngr(std::string p_sPath){
	m_sPath = p_sPath;
}

FontMngr::~FontMngr(){
	for (int i = m_xpaFonts.size() - 1; i >= 0; i--){
		delete m_xpaFonts[i];
		m_xpaFonts[i] = NULL;
		m_xpaFonts.erase(m_xpaFonts.begin + i);
	}
}

void FontMngr::NewFont(std::string p_sName, std::string p_sFname){
	m_xpaFonts.push_back(new Font(p_sName, p_sFname));
}

std::vector<Font*> FontMngr::GetFont(){

}