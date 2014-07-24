// ScoreMngr.h //

#pragma once

class ScoreMngr {
public:
	ScoreMngr(int p_iScore, int p_iHiScore, int p_iNextScore, int p_iNextScoreUp, int p_iLifes);
	~ScoreMngr();

	static int GetScore(); // Returns Score
	static void SetScore(int p_iScore); // Sets Score
	static void PlusScore(int p_iScore, bool p_bModifier = true); // increases the score by a certain amount

	static int GetHiScore(); // Returns HiScore
	static void SetHiScore(int p_iHiScore); // Sets HiScore

	static int GetNextScore(); // Returns NextScore
	static void SetNextScore(int p_iNextScore); // SetsNextScore
	static void PlusNextScore(); // Increases NextScore by a certain amount

	static int GetNextScoreUp(); // Returns NextScoreUp
	static void SetNextScoreUp(int p_iNextScore);// SetsNextScoreup

	static int GetLifes(); // Returns Lifes
	static void SetLifes(int p_iLifes); // Sets Lifes
	static void MinusLife(); // Reduces Lifes by 1
	static void PlusLife(); // Increases lifes by 1

	static int GetStartLifes(); // Returns StartLifes
	static void SetStartLifes(int p_iStartLifes); // Sets StartLifes

	static float GetScoreModifier(); // Returns the Score Modifier that is calculated from the amount of lifes the player started out with

private:
	static int m_iScore, // The basic score in the game
		m_iHiScore, // The highest score achieved.To be loaded from a text file in the near future
		m_iNextScore, // How much score is needed for an extra life
		m_iNextScoreUp, // How much NextScore is to be increased by every time an extra life is gained
		m_iLifes, // How many lifes the player has left
		m_iStartLifes; // How many lifes the player starts with
};