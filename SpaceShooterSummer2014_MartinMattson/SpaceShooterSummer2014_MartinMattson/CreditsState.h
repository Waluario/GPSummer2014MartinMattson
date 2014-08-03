// CreditsState.h //

#pragma once

#include "State.h"

class InfoObject;

class CreditsState : public State {
public:
	CreditsState(float p_fWaitTimeStart, std::string p_sFile);
	~CreditsState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);

private:
	float m_fWaitTimeStart,
		m_fWaitTime;

	InfoObject *m_xpCredits;
};