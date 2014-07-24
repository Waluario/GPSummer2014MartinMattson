// Core.cpp //

#include "Core.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "FontMngr.h"
#include "GameObjectMngr.h"
#include "KeybMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "StateMngr.h"

#include "GameState.h"
#include "MenuState.h"

Core::Core(){

}

Core::~Core(){

}

bool Core::Init(){
	// Initializes the window
	m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
	if (m_xpScreen == NULL){
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

	// Initializes the Music Manager
	m_xpMusicMngr = new MusicMngr("../rec/Audio/Bgm/");
	if (m_xpMusicMngr == NULL){
		return false;
	}

	// Loads all of the games music
	m_xpMusicMngr->Load("Bgm00.wav", "Bgm00");
	m_xpMusicMngr->SetVolume(0.f);

	// Initializes the Score Manager
	m_xpScoreMngr = new ScoreMngr(0, 0, 2000, 500, 0);
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

	// Initializes the Sprite Mngr
	m_xpSpriteMngr = new SpriteMngr("../rec/Graphics/");
	if (m_xpSpriteMngr == NULL){
		return false;
	}

	// Loads all of the games sprites
	m_xpSpriteMngr->LoadTexture("Ship", "ShipSprite.png");
	m_xpSpriteMngr->LoadTexture("Enemy0", "EnemySprite0.png");
	m_xpSpriteMngr->LoadTexture("Enemy1", "EnemySprite1.png");
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

	// Creates all of the games states
	m_xpStateMngr->Add(new GameState(15.f));
	m_xpStateMngr->Add(new MenuState());

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
}

void Core::Cleanup(){
	// Cleans up all of the Managers
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

	if (m_xpStateMngr != NULL){
		delete m_xpStateMngr;
		m_xpStateMngr = NULL;
	}
}