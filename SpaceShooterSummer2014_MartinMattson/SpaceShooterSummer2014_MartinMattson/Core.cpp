// Core.cpp //

#include "Core.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "FontMngr.h"
#include "GameObjectMngr.h"
#include "KeybMngr.h"
#include "LevelMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "StateMngr.h"

#include "CreditsState.h"
#include "GameOverState.h"
#include "GameState.h"
#include "HowToPlayState.h"
#include "MenuState.h"
#include "OptionsState.h"

#include "MenuItem.h"
#include "OptionsItem0.h"
#include "OptionsItem1.h"
#include "OptionsItem2.h"
#include "OptionsItem3.h"
#include "TextItem.h"

#include "OptionsObject.h"

#include <windows.h>

#include <iostream>

Core::Core(){

}

Core::~Core(){

}

bool Core::Init(){
	INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

	int q = MessageBox(NULL, L"Play game in Fullscreen?", L"Space Shooter Summer 2014", MB_YESNO);

	if (q == 6){
		// Initializes the window
		m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Fullscreen);
		if (m_xpScreen == NULL){
			return false;
		}

		m_xpScreen->setPosition(sf::Vector2i(0, 0));
		m_bFullScreen0 = new bool(true);
		m_bFullScreen1 = true;
	}
	else if (q == 7){
		// Initializes the window
		m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
		if (m_xpScreen == NULL){
			return false;
		}

		m_bFullScreen0 = new bool(false);
		m_bFullScreen1 = false;
	}
	else {
		return false;
	}
	
	// Initializes the Collision manager
	m_xpCollisionMngr = new CollisionMngr();
	if (m_xpCollisionMngr == NULL){
		return false;
	}

	CollisionMngr::NewList();

	// Initializes the Draw Managwer
	m_xpDrawMngr = new DrawMngr(m_xpScreen);
	if (m_xpDrawMngr == NULL){
		return false;
	}

	// Initializes the Font Manager
	m_xpFontMngr = new FontMngr("../rec/Fonts/");
	if (m_xpFontMngr == NULL){
		return false;
	}

	// Loads all of the games fonts
	m_xpFontMngr->NewFont("Arial", "arial/arial.ttf");

	// Initializes the Game Object Manager
	m_xpGameObjectMngr = new GameObjectMngr();
	if (m_xpGameObjectMngr == NULL){
		return false;
	}

	// Initializes the Keyboard Manager
	m_xpKeybMngr = new KeybMngr();
	if (m_xpKeybMngr == NULL){
		return false;
	}

	// Initializes the Level Manager
	m_xpLevelMngr = new LevelMngr("../rec/Levels/");
	if (m_xpLevelMngr == NULL){
		return false;
	}

	// Initializes the Music Manager
	m_xpMusicMngr = new MusicMngr("../rec/Audio/Bgm/");
	if (m_xpMusicMngr == NULL){
		return false;
	}

	// Loads all of the games music
	m_xpMusicMngr->Load("Bgm00.wav", "Bgm00");
	m_xpMusicMngr->Load("Bgm_Boss.wav", "Bgm_Boss");
	m_xpMusicMngr->Load("Bgm_Menu.wav", "Bgm_Menu");
	m_xpMusicMngr->Load("Bgm_Stage.wav", "Bgm_Stage");
	m_xpMusicMngr->SetVolume(100.f);

	// Initializes the Score Manager
	m_xpScoreMngr = new ScoreMngr(0, ScoreMngr::LoadHiScore("../rec/High_Score.txt"), 2000, 500, 2);
	if (m_xpScoreMngr == NULL){
		return false;
	}
	
	// Initializes the Sound Mngr
	m_xpSoundMngr = new SoundMngr("../rec/Audio/Sfx/");
	if (m_xpSoundMngr == NULL){
		return false;
	}

	// Loads all of the games sound effects
	m_xpSoundMngr->Load("Sfx00.wav", "Sfx00");
	m_xpSoundMngr->Load("Shot_Fired.wav", "Sfx_Shot");
	m_xpSoundMngr->Load("Point_Collected.wav", "Sfx_Point");
	m_xpSoundMngr->Load("Enemy_Death.wav", "Sfx_EnemyDeath");
	m_xpSoundMngr->Load("Player_Hit.wav", "Sfx_PlayerHit");
	//m_xpSoundMngr->SetVolume(100.f);

	// Initializes the Sprite Mngr
	m_xpSpriteMngr = new SpriteMngr("../rec/Graphics/");
	if (m_xpSpriteMngr == NULL){
		return false;
	}

	// Loads all of the games sprites
	m_xpSpriteMngr->LoadTexture("Ship", "ShipSprite.png");
	m_xpSpriteMngr->LoadTexture("Enemy0", "EnemySprite0.png");
	m_xpSpriteMngr->LoadTexture("Enemy1", "EnemySprite1.png");
	m_xpSpriteMngr->LoadTexture("Enemy2", "EnemySprite2.png");
	m_xpSpriteMngr->LoadTexture("Enemy3", "EnemySprite3.png");
	m_xpSpriteMngr->LoadTexture("Enemy4", "EnemySprite4.png");
	m_xpSpriteMngr->LoadTexture("PBullet", "PBulletSprite.png");
	m_xpSpriteMngr->LoadTexture("EBullet", "EBulletSprite.png");

	// Initializes the Time Mngr
	m_xpTimeMngr = new TimeMngr(new sf::Clock, sf::seconds(1.f / 60.f));
	if (m_xpTimeMngr == NULL){
		return false;
	}

	// Initializes the State Mngr
	m_xpStateMngr = new StateMngr();
	if (m_xpStateMngr == NULL){
		return false;
	}

	// Sets up the game options menu
	std::vector<MenuItem*> _xpaOptions;
	_xpaOptions.push_back(new OptionsItem1(sf::Vector2f(0, 0), "Lifes", m_xpScoreMngr->GetStartLifesPointer(), 0, 5));
	_xpaOptions.push_back(new OptionsItem2(sf::Vector2f(0, 0), "Sfx Volume", m_xpSoundMngr->GetVolumePointer(), 0.f, 100.f, 5.f));
	_xpaOptions.push_back(new OptionsItem2(sf::Vector2f(0, 0), "Bgm Volume", m_xpMusicMngr->GetVolumePointer(), 0.f, 100.f, 5.f));
	_xpaOptions.push_back(new OptionsItem0(sf::Vector2f(0, 0), "Fullscreen", m_bFullScreen0, 1));
	
	_xpaOptions.push_back(new TextItem("Controls:", sf::Vector2f(0, 0)));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Up", 0));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Down", 1));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Left", 2));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Right", 3));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Fire", 4));
	_xpaOptions.push_back(new OptionsItem3(sf::Vector2f(0, 0), "- Focus", 5));

	_xpaOptions.push_back(new MenuItem("MenuState", "Back", sf::Vector2f(0, 0)));

	OptionsObject *_xpOptionsObject = new OptionsObject(sf::Vector2f(0, 0), _xpaOptions);

	// Creates all of the games states
	m_xpStateMngr->Add(new CreditsState(0.5f, "../rec/Credits.txt"));
	m_xpStateMngr->Add(new GameOverState(0.5f));
	m_xpStateMngr->Add(new GameState(15.f));
	m_xpStateMngr->Add(new HowToPlayState(0.5f, "../rec/HowToPlay.txt"));
	m_xpStateMngr->Add(new MenuState());
	m_xpStateMngr->Add(new OptionsState(.5f, _xpaOptions));

	m_xpStateMngr->SetState("MenuState");

	return true;
}

void Core::Run(){
	while (m_xpStateMngr->IsRunning()){
		// Updates the window events and removes all fo the stopped sounds
		UpdEvents();
		m_xpSoundMngr->RemoveStoppedSounds();

		// Updates the Delta Time while chekcing if it is ata na acceptable amount
		if (m_xpTimeMngr->UpdDtime()){
			// Updates the Keyboard Manager
			m_xpKeybMngr->Update(m_xpTimeMngr->GetDtime());

			// Updates and Draws the current State
			m_xpStateMngr->Update(m_xpTimeMngr->GetDtime());
			m_xpStateMngr->Draw();

			// Presents and clears the current image drawn
			m_xpDrawMngr->Present();
			m_xpDrawMngr->Clear();
		}
	}
}

void Core::UpdEvents(){
	// Updates the window event, i.e. closes the window if one presses the red [X]
	sf::Event event;
	while (m_xpScreen->pollEvent(event)){
		switch (event.type){
			case sf::Event::Closed:
				m_xpScreen->close();
				m_xpStateMngr->Quit();
				break;
		}
	}

	if (*m_bFullScreen0 != m_bFullScreen1){
		if (*m_bFullScreen0){
			m_xpScreen->close();
			delete m_xpScreen;

			// Initializes the window
			m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Fullscreen);
			m_xpScreen->setMouseCursorVisible(false);
			m_xpDrawMngr->SetScreen(m_xpScreen);

			m_xpScreen->setPosition(sf::Vector2i(0, 0));
			*m_bFullScreen0 = true;
			m_bFullScreen1 = true;
		}
		else if (!*m_bFullScreen0){
			m_xpScreen->close();
			delete m_xpScreen;

			// Initializes the window
			m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
			m_xpScreen->setMouseCursorVisible(true);
			m_xpDrawMngr->SetScreen(m_xpScreen);

			*m_bFullScreen0 = false;
			m_bFullScreen1 = false;
		}
	}

	m_xpMusicMngr->SetVolume(m_xpMusicMngr->GetVolume());

	// std::cout << m_xpScoreMngr->GetStartLifes() << " " << m_xpSoundMngr->GetVolume() << " " << m_xpMusicMngr->GetVolume() << std::endl;
}

void Core::Cleanup(){
	// Cleans up all of the Managers
	delete m_bFullScreen0;
	m_bFullScreen0 = NULL;

	m_xpScreen = NULL;

	if (m_xpStateMngr != NULL){
		delete m_xpStateMngr;
		m_xpStateMngr = NULL;
	}

	if (m_xpCollisionMngr != NULL){
		delete m_xpCollisionMngr;
		m_xpCollisionMngr = NULL;
	}

	if (m_xpDrawMngr != NULL){
		delete m_xpDrawMngr;
		m_xpDrawMngr = NULL;
	}

	if (m_xpFontMngr != NULL){
		delete m_xpFontMngr;
		m_xpFontMngr = NULL;
	}

	if (m_xpGameObjectMngr != NULL){
		delete m_xpGameObjectMngr;
		m_xpGameObjectMngr = NULL;
	}

	if (m_xpKeybMngr != NULL){
		delete m_xpKeybMngr;
		m_xpKeybMngr = NULL;
	}

	if (m_xpLevelMngr != NULL){
		delete m_xpLevelMngr;
		m_xpLevelMngr = NULL;
	}

	if (m_xpMusicMngr != NULL){
		delete m_xpMusicMngr;
		m_xpMusicMngr = NULL;
	}

	if (m_xpScoreMngr != NULL){
		delete m_xpScoreMngr;
		m_xpScoreMngr = NULL;
	}

	if (m_xpSoundMngr != NULL){
		delete m_xpSoundMngr;
		m_xpSoundMngr = NULL;
	}

	if (m_xpSpriteMngr != NULL){
		delete m_xpSpriteMngr;
		m_xpSpriteMngr = NULL;
	}

	if (m_xpTimeMngr != NULL){
		delete m_xpTimeMngr;
		m_xpTimeMngr = NULL;
	}
}