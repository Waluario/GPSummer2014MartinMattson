// GameObject.h //

#pragma once

#include <vector>

class Hitbox;

class GameObject : public sf::Transformable {
public:
	GameObject();
	~GameObject();

	void AddParent(GameObject *p_xpParent);
	void RemoveParent();

	bool HasParent();

	GameObject* GetParent();

	void AddChild(GameObject *p_xpChild);
	void RemoveChild(GameObject *p_xpChild);
	void ClearChild(GameObject *p_xpChild);

	GameObject* GetChild(GameObject *p_xpChild);
	std::vector<GameObject*> GetChildren();

	bool HasChild();
	int ChildrenNumber();

	void AddTag(std::string p_sTag);
	bool HasTag(std::string p_sTag);
	std::vector<std::string> GetTags();
	void WriteTags();

	Hitbox* GetHitbox();
	void SetHitbox(Hitbox *p_xpHitbox);
	bool HasHitbox();

	virtual void SetAllPositions(sf::Vector2f p_vPosition);
	virtual bool OnScreen();

	void DeleteMe();
	bool CanDelete();
	void DeleteChildren();

	void OnUpdate();
	void OnDraw();
	
	virtual void OnCreate() = 0;
	virtual void OnCollision(GameObject *p_xpCollider) = 0;

private:
	void OnUpdateChildren();
	virtual void OnUpdateThis() = 0;

	void OnDrawChildren();
	virtual void OnDrawThis() = 0;

	std::vector<std::string> m_saTags;

	std::vector<GameObject*> m_xpaChildren;
	GameObject* m_xpParent;

	Hitbox *m_xpHitbox;

	bool m_bDeleteMe;
	bool m_bJustBorn;
};