// GameObject.h //

#pragma once

#include <vector>

class Hitbox;

class GameObject : public sf::Transformable {
public:
	GameObject();
	~GameObject();

	void AddParent(GameObject *p_xpParent);
	void RemoveParent(GameObject *p_xpChild);

	bool HasParent();

	GameObject* GetParent();

	void AddChild(GameObject *p_xpChild);
	void RemoveChild(GameObject *p_xpChild);

	GameObject* GetChild(int p_i);
	std::vector<GameObject*> GetChildren();

	bool HasChild();
	int ChildrenNumber();

	bool HasTag(std::string p_sTag);
	std::vector<std::string> GetTags();

	Hitbox* GetHitbox();
	bool HasHitbox();

	bool IsColliding(sf::Vector2f p_vPos, Hitbox *p_xpHitbox);

	void OnUpdate();
	void OnDraw();

private:
	void OnUpdateChildren();
	virtual void OnUpdateThis() = 0;

	void OnDrawChildren();
	virtual void OnDrawThis() = 0;

	virtual void OnCollision(GameObject *p_xpCollider) = 0;

	std::vector<std::string> m_saTags;

	std::vector<GameObject*> m_xpaChildren;
	GameObject *m_xpParent;

	Hitbox *m_xpHitbox;
};