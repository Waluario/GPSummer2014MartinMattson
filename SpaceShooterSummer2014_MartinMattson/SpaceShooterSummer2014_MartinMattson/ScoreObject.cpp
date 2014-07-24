// ScoreObject.cpp //

#include "ScoreObject.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "ScoreMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include <cstdlib>
#include <iostream>

ScoreObject::ScoreObject(sf::Vector2f p_vPosition){
	m_xpSprite = SpriteMngr::GetSprite("EBullet");

	int _i[3] = { 0, 0, 0 };

	do {
		for (int i = 0; i < 3; i++){
			int _iR = (rand() % 2);
			_i[i] = 255 * _iR;
		}

	} while (_i[0] == 0 && _i[1] == 0 && _i[2] == 0);

	m_xpSprite->GetSprite()->setColor(sf::Color(_i[0], _i[1], _i[2]));

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 25.f, 0));

	m_vSpd = sf::Vector2f(rand() % 32 - 16, -32);
	m_vMaxSpd = sf::Vector2f(16, 256);
	m_vAcceleration = sf::Vector2f(0, 64 + rand() % 32);
	m_fRotationSpeed = rand() % 12 - 6;

	SetAllPositions(p_vPosition);
}

ScoreObject::~ScoreObject(){
	delete m_xpSprite;
	m_xpSprite = NULL;
}

void ScoreObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void ScoreObject::OnCreate(){

}

void ScoreObject::OnUpdateThis(){
	m_vSpd.x += (m_vAcceleration.x * TimeMngr::GetDtime());
	m_vSpd.y += (m_vAcceleration.y * TimeMngr::GetDtime());

	if (m_vSpd.x > m_vMaxSpd.x){
		m_vSpd.x = m_vMaxSpd.x;
	}
	else if (m_vSpd.x < -m_vMaxSpd.x){
		m_vSpd.x = -m_vMaxSpd.x;
	}

	if (m_vSpd.y > m_vMaxSpd.y){
		m_vSpd.y = m_vMaxSpd.y;
	}
	else if (m_vSpd.y < -m_vMaxSpd.y){
		m_vSpd.y = -m_vMaxSpd.y;
	}

	SetAllPositions(sf::Vector2f(getPosition() + m_vSpd * TimeMngr::GetDtime()));
	m_xpSprite->GetSprite()->setRotation(m_xpSprite->GetSprite()->getRotation() + m_fRotationSpeed);

	if (!OnScreen()){
		DeleteMe();
	}
}

void ScoreObject::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void ScoreObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Player")){
		std::cout << "Bling!";
		ScoreMngr::PlusScore(ScoreMngr::GetScoreModifier() * 20);
		DeleteMe();
	}
}