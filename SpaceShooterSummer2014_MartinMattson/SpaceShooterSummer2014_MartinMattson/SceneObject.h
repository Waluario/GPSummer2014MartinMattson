// SceneObject.h //

#pragma once

#include "GameObject.h"

class SceneObject : public GameObject {
public:
	SceneObject();
	~SceneObject();

private:
	virtual void OnUpdateThis();

	virtual void OnDrawThis();

	virtual void OnCollision(GameObject *p_xpCollider);
};