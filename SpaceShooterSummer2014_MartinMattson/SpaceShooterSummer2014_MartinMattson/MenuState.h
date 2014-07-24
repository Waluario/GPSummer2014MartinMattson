// MenuState.h //

#pragma once

#include "State.h"

class SceneObject;

class MenuState : public State {
public:
	MenuState();
	~MenuState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);  // Parameter_FloatingDtime
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);// Parameter_StringType

private:
	SceneObject *m_xpScene;
};