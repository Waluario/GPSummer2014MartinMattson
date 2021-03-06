// SceneObject.h //

#pragma once

#include "GameObject.h"

class SceneObject : public GameObject {
public:
	SceneObject(int p_iScene);
	~SceneObject();

private:
	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);
};