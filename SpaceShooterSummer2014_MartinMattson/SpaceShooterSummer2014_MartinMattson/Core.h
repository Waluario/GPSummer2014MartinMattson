// Core.h //

#pragma once

class DrawMngr;
class KeybMngr;
class SpriteMngr;
class TimeMngr;

class StateMngr;

class Core {
public:
	Core();
	~Core();

	bool Init();
	void Run();

	void UpdEvents();

	void Cleanup();

private:
	sf::RenderWindow *m_xpScreen;

	DrawMngr *m_xpDrawMngr;
	KeybMngr *m_xpKeybMngr;
	SpriteMngr *m_xpSpriteMngr;
	TimeMngr *m_xpTimeMngr;

	StateMngr *m_xpStateMngr;
};