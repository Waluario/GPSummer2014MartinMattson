// Core.h //

#pragma once

class CollisionMngr;
class DrawMngr;
class FontMngr;
class GameObjectMngr;
class KeybMngr;
class ScoreMngr;
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

	CollisionMngr *m_xpCollisionMngr;
	DrawMngr *m_xpDrawMngr;
	FontMngr *m_xpFontMngr;
	GameObjectMngr *m_xpGameObjectMngr;
	KeybMngr *m_xpKeybMngr;
	ScoreMngr *m_xpScoreMngr;
	SpriteMngr *m_xpSpriteMngr;
	TimeMngr *m_xpTimeMngr;

	StateMngr *m_xpStateMngr;
};