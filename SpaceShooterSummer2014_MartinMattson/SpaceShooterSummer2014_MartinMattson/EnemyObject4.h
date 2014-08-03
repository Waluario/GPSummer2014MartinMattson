// EnemyObject4.h //

#pragma once

#include "EnemyObject.h"

class Sprite;

class EnemyObject4 : public EnemyObject {
public:
	EnemyObject4(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd);
	~EnemyObject4();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	

	enum AIStage {
		e_Stage0,
		e_Stage1,
		e_Stage2,
		e_Stage3_1,
		e_Stage3_2,
		e_Stage3_3,
		e_Stage4,
		e_StageNum,
	};

	EnemyObject4::AIStage m_eStage;

	Sprite *m_xpSprite;

	float m_fMoveInTime,
		m_fRingFire,
		m_fRingFireMax,
		m_fRapidFire,
		m_fRapidFireMax,
		m_fSummonSmiley,
		m_fSummonSmileyMax,
		m_fSummonArrow,
		m_fSummonArrowMax;
};