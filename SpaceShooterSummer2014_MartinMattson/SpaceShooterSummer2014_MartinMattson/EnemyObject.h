// EnemyObject.h //

#include "GameObject.h"

#pragma once

class EnemyObject : public GameObject {
public:
	EnemyObject();
	~EnemyObject();

	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);
};