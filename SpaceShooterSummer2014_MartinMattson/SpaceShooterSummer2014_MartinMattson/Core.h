// Core.h //

#pragma once

class DrawMngr;
class KeybMngr;
class SpriteMngr;
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

	DrawMngr *m_xpDrawMngr;
	KeybMngr *m_xpKeybMngr;
	SpriteMngr *m_xpSpriteMngr;
	StateMngr *m_xpStateMngr;
};