// GameOverState.h //

#pragma once

#include "State.h"

class GameOverState : public State {
public:
	GameOverState(float p_fWaitTimeStart);
	~GameOverState();

	bool Enter();
	void Exit();
	bool Update(float p_fDtime);
	void Draw();
	std::string Next();
	bool IsType(const std::string &p_sType);

	bool CheckHighScore(int p_fNewScore, int p_fOldScore);

private:
	float m_fWaitTime,
		m_fWaitTimeStart;

	sf::Text *m_xpText,
		*m_xpScoreText,
		*m_xpHiScoreText,
		*m_xpContinueText;
};