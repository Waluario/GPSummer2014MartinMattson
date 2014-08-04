// EnemyObject4.cpp //

#include "EnemyObject4.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "GameObjectMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "EnemyBulletObject.h"
#include "EnemyObject0.h"
#include "EnemyObject1.h"

EnemyObject4::EnemyObject4(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd){
	m_vSpd = p_vSpd;

	setPosition(p_vPosition);

	m_iBulletAmmo = INT_MAX;
	m_iLife = 360;
	m_iScore = 120;

	m_fFireRateMax = 2.f;
	m_fFireRate = m_fFireRateMax;

	m_fMoveInTime = 12.f;

	m_fRingFireMax = .75f;
	m_fRingFire = m_fRingFireMax;
	m_fRapidFireMax = .5f;
	m_fRapidFire = m_fRapidFireMax;
	m_fSummonSmileyMax = 1.f;
	m_fSummonSmiley = m_fSummonSmileyMax;
	m_fSummonArrowMax = .75f;
	m_fSummonArrow = m_fSummonArrowMax;
}

EnemyObject4::~EnemyObject4(){

}

void EnemyObject4::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyObject4::OnCreate(){
	m_xpSprite = SpriteMngr::GetSprite("Enemy3");
	m_xpSprite->SetPosition(getPosition());

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 35.f, 0));

	m_xpPlayer = GameObjectMngr::GetGameObject("Player");

	ScoreMngr::SetSpawn(false);

	m_eStage = AIStage::e_Stage0;

	MusicMngr::Play("Bgm_Boss");
}

void EnemyObject4::OnUpdateThis(){
	switch (m_eStage){
	case EnemyObject4::e_Stage0:
		SetAllPositions(sf::Vector2f(getPosition().x, getPosition().y + m_vSpd.y * TimeMngr::GetDtime()));

		m_fMoveInTime -= TimeMngr::GetDtime();

		break;
	case EnemyObject4::e_Stage1:
		m_fRingFire -= TimeMngr::GetDtime();

		if (m_fRingFire <= 0){
			for (float i = 0; i <= 360; i += 22.5f){
				GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(cosf(i * 3.141592 / 180), sinf(i * 3.141592 / 180)), 95.f));
			}

			m_fRingFire = m_fRingFireMax;
		}

		break;
	case EnemyObject4::e_Stage2:
		m_fSummonSmiley -= TimeMngr::GetDtime();

		if (m_fSummonSmiley <= 0){
			m_fSummonSmiley = m_fSummonSmileyMax;

			EnemyObject0 *_xpSummon = new EnemyObject0(getPosition(), sf::Vector2f(0, 256), sf::Vector2f(0, 0));
			GetParent()->AddChild(_xpSummon);
			_xpSummon->OnCreate();

			_xpSummon = NULL;
		}

		break;
	case EnemyObject4::e_Stage3_1:
		m_fRapidFire -= TimeMngr::GetDtime();

		if (m_fRapidFire <= 0){
			m_fRapidFire = m_fRapidFireMax;

			float _iA = m_xpPlayer->getPosition().x - getPosition().x;
			float _iB = m_xpPlayer->getPosition().y - getPosition().y;
			float _iC = sqrt((_iA * _iA) + (_iB * _iB));

			sf::Vector2f _vBulletDir = sf::Vector2f((_iA / _iC), (_iB / _iC));

			GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 95.f));
		}

		m_fSummonArrow -= TimeMngr::GetDtime();

		break;
	case EnemyObject4::e_Stage3_2:
		m_fRapidFire -= TimeMngr::GetDtime();

		if (m_fRapidFire <= 0){
			m_fRapidFire = m_fRapidFireMax;

			float _iA = m_xpPlayer->getPosition().x - getPosition().x;
			float _iB = m_xpPlayer->getPosition().y - getPosition().y;
			float _iC = sqrt((_iA * _iA) + (_iB * _iB));

			sf::Vector2f _vBulletDir = sf::Vector2f((_iA / _iC), (_iB / _iC));

			GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 95.f));
		}

		m_fSummonArrow -= TimeMngr::GetDtime();

		if (m_fSummonArrow <= 0){
			m_fSummonArrow = m_fSummonArrowMax;

			EnemyObject1 *_xpSummon = new EnemyObject1(sf::Vector2f(0, 75), sf::Vector2f(180, 0), sf::Vector2f(0, 1));
			GetParent()->AddChild(_xpSummon);
			_xpSummon->OnCreate();

			_xpSummon = new EnemyObject1(sf::Vector2f(800, 75), sf::Vector2f(-180, 0), sf::Vector2f(0, 1));
			GetParent()->AddChild(_xpSummon);
			_xpSummon->OnCreate();

			_xpSummon = NULL;
		}

		break;
	case EnemyObject4::e_Stage3_3:
		m_fRapidFire -= TimeMngr::GetDtime();

		if (m_fRapidFire <= 0){
			m_fRapidFire = m_fRapidFireMax;

			float _iA = m_xpPlayer->getPosition().x - getPosition().x;
			float _iB = m_xpPlayer->getPosition().y - getPosition().y;
			float _iC = sqrt((_iA * _iA) + (_iB * _iB));

			sf::Vector2f _vBulletDir = sf::Vector2f((_iA / _iC), (_iB / _iC));

			GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 95.f));
		}

		m_fSummonArrow -= TimeMngr::GetDtime();

		if (m_fSummonArrow <= 0){
			m_fSummonArrow = m_fSummonArrowMax;

			EnemyObject1 *_xpSummon = new EnemyObject1(sf::Vector2f(0, 75), sf::Vector2f(180, 0), sf::Vector2f(0, 1));
			GetParent()->AddChild(_xpSummon);
			_xpSummon->OnCreate();

			_xpSummon = new EnemyObject1(sf::Vector2f(800, 75), sf::Vector2f(-180, 0), sf::Vector2f(0, 1));
			GetParent()->AddChild(_xpSummon);
			_xpSummon->OnCreate();

			_xpSummon = NULL;
		}

		m_fRingFire -= TimeMngr::GetDtime();

		if (m_fRingFire <= 0){
			for (float i = 0; i <= 360; i += 22.5f){
				GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(cosf(i * 3.141592 / 180) * 2000.f, sinf(i * 3.141592 / 180) * 2000.f), 95.f));
			}

			m_fRingFire = m_fRingFireMax * 2.5f;
		}

		break;
	case EnemyObject4::e_Stage4:
		break;
	default:
		break;
	}

	if (m_fMoveInTime <= 0.f){
		if (m_xpPlayer->getPosition().x > getPosition().x && getPosition().x > 50.f){
			SetAllPositions(sf::Vector2f(getPosition().x + -m_vSpd.x * TimeMngr::GetDtime(), getPosition().y));
		}
		else if (m_xpPlayer->getPosition().x < getPosition().x && getPosition().x < 750.f){
			SetAllPositions(sf::Vector2f(getPosition().x + m_vSpd.x * TimeMngr::GetDtime(), getPosition().y));
		}
	}

	if (m_iLife > 240 && m_fMoveInTime <= 0.f){
		m_eStage = e_Stage1;
	}
	else if (m_iLife > 120 && m_iLife <= 240){
		m_eStage = e_Stage2;
	}
	else if (m_iLife > 80 && m_iLife <= 120){
		m_eStage = e_Stage3_1;
	}
	else if (m_iLife > 60 && m_iLife <= 60){
		m_eStage = e_Stage3_2;
	}
	else if (m_iLife > 40 && m_iLife <= 30){
		m_eStage = e_Stage3_3;
	}
}

void EnemyObject4::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void EnemyObject4::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("PBullet") && m_fMoveInTime <= 0.f){
		m_iLife--;

		if (m_iLife <= 0){
			SoundMngr::Play("Sfx_EnemyDeath");
			ScoreMngr::SetSpawn(true);
			DropScore();
			DeleteMe();
		}
	}
}