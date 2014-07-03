// Font.cpp //

#include "Font.h"

Font::Font(std::string p_sName, std::string p_sFname){
	m_sName = p_sName;
	loadFromFile(p_sFname);
}

Font::~Font(){

}

std::string Font::GetName(){
	return m_sName;
}

void Font::SetName(std::string p_sName){
	m_sName = p_sName;
}