// HowToPlayState.h //

#pragma once

#include "State.h"

class InfoObject;

class HowToPlayState : public State {
public:
	HowToPlayState(float p_fWaitTimeStart, std::string p_sFile);
	~HowToPlayState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);

private:
	float m_fWaitTimeStart,
		m_fWaitTime;

	InfoObject *m_xpHowToPlay;
};