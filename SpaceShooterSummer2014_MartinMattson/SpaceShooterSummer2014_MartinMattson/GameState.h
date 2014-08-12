// GameState.h //

#pragma once

#include "State.h"

class SceneObject;

class GameState : public State {
public:
	GameState(float p_fStageTimeStart);
	~GameState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);  // Parameter_FloatingDtime
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);// Parameter_StringType

private:
	SceneObject *m_xpScene,
		*m_xpPause;

	float m_fStageTime,
		m_fStageTimeStart;

	bool *m_bpPlaying;
};