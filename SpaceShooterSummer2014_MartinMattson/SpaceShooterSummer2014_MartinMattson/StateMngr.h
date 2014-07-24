// StateMngr.h //

#pragma once

#include <vector>

class State;

class StateMngr {
public:
	StateMngr();
	~StateMngr();

	void Update(float p_fDtime); // Updates the current state
	void Draw(); // Draws the current State

	static void Add(State *p_cpState); // Adds a new State to the State Manager

	static void SetState(const std::string &p_skrState); // Parameter_StringKonstantReferenceState
	static void SetNextState(const std::string p_sState); // Sets the next state to come when the ChangeState() method is called
	static void ChangeState(); // Changes the current state to the next one

	static void Quit(); // Quits the game
	static bool IsRunning(); // Checks if the State Manager is running correctly or not

private:
	static std::vector<State*> m_cpaStates; // The vector of States
	static State *m_cpCurrent; // The State currently used
};