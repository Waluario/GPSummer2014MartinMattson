// StateMngr.h //

#include <vector>

class State;

class StateMngr {
public:
	StateMngr();
	~StateMngr();

	void Add(State *p_cpState); // Parameter_ClassPointerState
	void Update(float p_fDtime); // Parameter_FloatingDtime

	void SetState(const std::string &p_skrState); // Parameter_StringKonstantReferenceState
	void ChangeState();
	void Draw();

	void Quit();
	bool IsRunning();

private:
	std::vector<State*> m_cpaStates; // Member_ClassVectorStates
	State *m_cpCurrent; // Member_ClassPointerCurrent
};