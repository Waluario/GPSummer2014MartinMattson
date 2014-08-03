// PlayerObject.cpp //

#include "PlayerObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "ScoreMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "StateMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "PlayerBulletObject.h"

#include <iostream>

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_fAcceleration = p_fAcceleration;

	setPosition(p_vPos);

	m_fMaxCdwn = 2.f;
	m_fCdwn = 0.f;

	m_fBlinkTimeMax = 1.f / 64.f;
	m_fBlinkTime = 0.f;

	m_fFirerateMax = .0625f;
	m_fFirerate = m_fFirerateMax;

	m_fFireRange = 0.0f;
	m_fFireRangeMax = .5f;
	m_bFireRangeUp = true;

	AddTag("Player");

	m_xpSprite = SpriteMngr::GetSprite("Ship");
	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 4.0f, 0));
}

PlayerObject::~PlayerObject(){
	delete m_xpSprite;
	m_xpSprite = NULL;
}

void PlayerObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void PlayerObject::OnCreate(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	sf::Vector2f _vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	if (KeybMngr::GetButtonPressed(6)){
		TimeMngr::SetPace(4);
	}
	else {
		TimeMngr::SetPace(1);
	}

	if (_Keys[4]->IsPressed() && CanFire()){
		SoundMngr::Play("Sfx_Shot", 25.f);
		GetParent()->AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x - ((m_fFireRangeMax / m_fFireRangeMax) * (m_xpSprite->GetSprite()->getTextureRect().width / 3)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		GetParent()->AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x + ((m_fFireRangeMax / m_fFireRangeMax) * (m_xpSprite->GetSprite()->getTextureRect().width / 3)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
	}

	if (m_fCdwn > 0.f){
		m_fCdwn -= (TimeMngr::GetDtime());

		if (m_fBlinkTime > 0.f){
			m_fBlinkTime -= TimeMngr::GetDtime();
		}
		else {
			m_fBlinkTime = m_fBlinkTimeMax;
			if (m_bDrawSprite){
				m_bDrawSprite = false;
			}
			else {
				m_bDrawSprite = true;
			}
		}
	}
	else {
		m_bDrawSprite = true;
	}

	SetAllPositions(getPosition() + ((_vSpeed * m_fAcceleration * TimeMngr::GetDtime(false)) / (1.f + KeybMngr::GetButtonPressed(4))) / (1.f + KeybMngr::GetButtonPressed(5)));
}

void PlayerObject::OnDrawThis(){
	if (m_bDrawSprite){
		DrawMngr::Draw(m_xpSprite->GetSprite());
	}

	if (KeybMngr::GetButtonPressed(5)){
		DrawMngr::Draw(GetHitbox()->GetShape());
	}
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy") || p_xpCollider->HasTag("EBullet")){
		if (m_fCdwn <= 0.0f){
			m_fCdwn = m_fMaxCdwn;

			SoundMngr::Play("Sfx_PlayerHit");
			ScoreMngr::MinusLife();

			if (ScoreMngr::GetLifes() < 0){
				StateMngr::SetNextState("GameOverState");
				StateMngr::ChangeState();
			}
		}
	}
}

bool PlayerObject::CanFire(){
	if (m_fFirerate <= 0){
		m_fFirerate = m_fFirerateMax;

		return true;
	}

	m_fFirerate -= TimeMngr::GetDtime(false);

	// Fire Range

	if (m_fFireRange <= -m_fFireRangeMax && !m_bFireRangeUp){
		m_bFireRangeUp = true;
	}
	else if (m_fFireRange >= m_fFireRangeMax && m_bFireRangeUp){
		m_bFireRangeUp = false;
	}

	m_fFireRange += (-1 + (2 * m_bFireRangeUp)) * TimeMngr::GetDtime();

	return false;
}