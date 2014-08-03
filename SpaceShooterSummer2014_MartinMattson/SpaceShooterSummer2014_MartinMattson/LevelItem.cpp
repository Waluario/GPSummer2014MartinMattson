// LevelItem.cpp //

#include "LevelItem.h"

LevelItem::LevelItem(float p_fTime, GameObject *p_xpGameObject){
	m_fTime = p_fTime;
	m_xpGameObject = p_xpGameObject;
}

LevelItem::~LevelItem(){
	m_xpGameObject = NULL;
}

float LevelItem::GetTime(){
	return m_fTime;
}

void LevelItem::SetTime(float p_fTime){
	m_fTime = p_fTime;
}

GameObject* LevelItem::GetGameObject(){
	return m_xpGameObject;
}

void LevelItem::SetGameObject(GameObject *p_xpGameObject){
	m_xpGameObject = p_xpGameObject;
}