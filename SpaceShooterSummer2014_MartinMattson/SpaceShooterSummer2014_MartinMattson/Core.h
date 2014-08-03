// Core.h //

#pragma once

class CollisionMngr;
class DrawMngr;
class FontMngr;
class GameObjectMngr;
class KeybMngr;
class LevelMngr;
class MusicMngr;
class ScoreMngr;
class SoundMngr;
class SpriteMngr;
class TimeMngr;

class StateMngr;

class Core {
public:
	Core();
	~Core();

	bool Init(); // Intitialisation method for startup
	void Run(); // Run method, runs the program until the State Manager commands it to stop

	void UpdEvents(); // Updates events regarding the window

	void Cleanup(); // Cleans up all of the managers

private:
	sf::RenderWindow *m_xpScreen; //  The main screen for easy access

	CollisionMngr *m_xpCollisionMngr; // Handles collision
	DrawMngr *m_xpDrawMngr; // Handles drawing
	FontMngr *m_xpFontMngr; // Handles fonts and texts
	GameObjectMngr *m_xpGameObjectMngr; // Handles Game Objects
	KeybMngr *m_xpKeybMngr; // Handles keyboard presses
	LevelMngr *m_xpLevelMngr;
	MusicMngr *m_xpMusicMngr; // Handles music
	ScoreMngr *m_xpScoreMngr; // Handles in-game stats such as Score and Lives
	SoundMngr *m_xpSoundMngr; // Handles sound effects and sound sources
	SpriteMngr *m_xpSpriteMngr; // Handles Sprites and Textures
	TimeMngr *m_xpTimeMngr; // Handles Delta-Time

	StateMngr *m_xpStateMngr; // Handles States
};