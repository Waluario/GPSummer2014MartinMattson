// OptionsState.h //

#pragma once

#include "State.h"

class OptionsItem;

class SceneObject;

class OptionsState : public State {
public:
	OptionsState(float p_fWaitTimeStart, std::vector<OptionsItem*> p_xpaOptions);
	~OptionsState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);

private:
	float m_fWaitTimeStart,
		m_fWaitTime;

	SceneObject *m_xpScene;
};