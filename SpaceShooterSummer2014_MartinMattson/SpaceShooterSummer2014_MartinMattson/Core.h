// Core.h //

class KeybMngr;
class StateMngr;

class Core {
public:
	Core();
	~Core();

	bool Init();
	void Run();

	void UpdEvents();
	void UpdDtime();
	void UpdFixedDtime();

	float GetDtime();
	float GetFixedDtime();

	void Cleanup();

private:
	sf::Window *m_xpScreen;

	KeybMngr *m_xpKeybMngr;
	StateMngr *m_xpStateMngr;

	float m_fDtime;
	float m_fFixedDtime;
};