// GameObject.cpp //

#include "GameObject.h"

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::AddParent(GameObject *p_xpChild){
	m_xpParent = p_xpChild;
}

void GameObject::RemoveParent(GameObject *p_xpChild){
	m_xpParent = NULL;
}

bool GameObject::HasParent(){
	return (m_xpParent != NULL);
}

GameObject* GameObject::GetParent(){
	return m_xpParent;
}

void GameObject::AddChild(GameObject *p_xpChild){

}

void GameObject::RemoveChild(GameObject *p_xpChild){
	for (int i = m_xpaChildren.size() - 1; i >= 0; i++){
		if (m_xpaChildren[i] == p_xpChild){
			m_xpaChildren[i] = NULL;
		}
	}
}

GameObject* GameObject::GetChild(int p_i){
	if (m_xpaChildren.size() > p_i){
		return m_xpaChildren[p_i];
	}

	return NULL;
}

std::vector<GameObject*> GameObject::GetChildren(){
	return m_xpaChildren;
}

bool GameObject::HasChild(){
	return (m_xpaChildren.size() > 0);
}

int GameObject::ChildrenNumber(){
	return m_xpaChildren.size();
}

std::vector<std::string> GameObject::GetTags(){
	return m_saTags;
}

Hitbox* GameObject::GetHitbox(){
	return m_xpHitbox;
}

bool GameObject::HasHitbox(){
	return (m_xpHitbox != NULL);
}

bool GameObject::IsColliding(sf::Vector2f p_vPos, Hitbox *p_xpHitbox){
	return false;
}

void GameObject::OnUpdate(){
	OnUpdateThis();
	OnUpdateChildren();
}

void GameObject::OnDraw(){
	OnDrawThis();
	OnDrawChildren();
}

void GameObject::OnUpdateChildren(){
	for (int i = 0; i < m_xpaChildren.size(); i++){
		m_xpaChildren[i]->OnUpdate();
	}
}

void GameObject::OnDrawChildren(){
	for (int i = 0; i < m_xpaChildren.size(); i++){
		m_xpaChildren[i]->OnDraw();
	}
}