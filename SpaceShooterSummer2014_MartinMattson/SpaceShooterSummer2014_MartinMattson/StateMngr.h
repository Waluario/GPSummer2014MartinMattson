// StateMngr.h //

#include <vector>

class State;

class StateMngr {
public:
	StateMngr();
	~StateMngr();

	void Update(float p_fDtime); // Parameter_FloatingDtime
	void Draw();

	static void Add(State *p_cpState); // Parameter_ClassPointerState

	static void SetState(const std::string &p_skrState); // Parameter_StringKonstantReferenceState
	static void ChangeState();

	static void Quit();
	static bool IsRunning();

private:
	static std::vector<State*> m_cpaStates; // Member_ClassVectorStates
	static State *m_cpCurrent; // Member_ClassPointerCurrent
};