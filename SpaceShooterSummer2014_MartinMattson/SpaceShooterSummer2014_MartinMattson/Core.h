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
	bool UpdDtime();

	float GetDtime();

	void Cleanup();

private:
	sf::RenderWindow *m_xpScreen;
	sf::Clock *m_xpClock;
	sf::Time m_xDtime;
	sf::Time m_xFps;

	KeybMngr *m_xpKeybMngr;
	StateMngr *m_xpStateMngr;
};