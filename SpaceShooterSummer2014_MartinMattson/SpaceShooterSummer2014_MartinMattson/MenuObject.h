// MenuObject.h //

#pragma once

#include "GameObject.h"

class MenuItem;

class MenuObject : public GameObject {
public:
	MenuObject();
	~MenuObject();

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

public:
	void AddNewItem(MenuItem* p_xpItem);

private:
	int m_iCurrentChoice;

	std::vector<MenuItem*> m_xpaItems;
};