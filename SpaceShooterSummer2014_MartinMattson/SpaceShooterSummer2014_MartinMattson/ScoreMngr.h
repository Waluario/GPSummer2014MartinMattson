// ScoreMngr.h //

#pragma once

class ScoreMngr {
public:
	ScoreMngr(int p_iScore, int p_iHiScore, int p_iNextScore, int p_iNextScoreUp, int p_iLifes);
	~ScoreMngr();

	static int GetScore();
	static void SetScore(int p_iScore);
	static void PlusScore(int p_iScore);

	static int GetHiScore();
	static void SetHiScore(int p_iHiScore);

	static int GetNextScore();
	static void SetNextScore(int p_iNextScore);
	static void PlusNextScore();

	static int GetNextScoreUp();
	static void SetNextScoreUp(int p_iNextScore);

	static int GetLifes();
	static void SetLifes(int p_iLifes);
	static void MinusLife();
	static void PlusLife();

	static int GetStartLifes();
	static void SetStartLifes(int p_iStartLifes);
	static float GetScoreModifier();

private:
	static int m_iScore,
		m_iHiScore,
		m_iNextScore,
		m_iNextScoreUp,
		m_iLifes,
		m_iStartLifes;
};