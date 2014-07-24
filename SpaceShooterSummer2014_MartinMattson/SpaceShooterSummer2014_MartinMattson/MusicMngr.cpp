// MusicMngr.cpp //

#include "MusicMngr.h"

#include "Bgm.h"

std::string MusicMngr::m_sDir;

std::vector<Bgm*> MusicMngr::m_xpaMusic;
Bgm *MusicMngr::m_xpCurrent;

float MusicMngr::m_fVolume;

MusicMngr::MusicMngr(std::string p_sDir){
	m_sDir = p_sDir;
}

MusicMngr::~MusicMngr(){
	// Deletes all music and nulls the vector
	for (int i = m_xpaMusic.size() - 1; i >= 0; i--){
		delete m_xpaMusic[i];
		m_xpaMusic[i] = NULL;
		m_xpaMusic.erase(m_xpaMusic.begin() + i);
	}

	m_xpCurrent = NULL;
}

void MusicMngr::Load(std::string p_sFname, std::string p_sName){
	// Creastes a new music object
	sf::Music *_xpMusic = new sf::Music;

	// Loads the music object with data from a file
	if (!_xpMusic->openFromFile(m_sDir + p_sFname)){
		throw std::runtime_error("Music " + p_sFname + " could not be loaded.");
		return;
	}

	// Puts the new music object at the back of the music vector
	m_xpaMusic.push_back(new Bgm(p_sName, _xpMusic));
}


void MusicMngr::Play(float p_fVolume){
	// Plays the current piece of music
	m_xpCurrent->GetMusic()->play();
}

void MusicMngr::Play(std::string p_sName, float p_fVolume){
	// calls a piece of music by name and plays it
	for (int i = 0; i < m_xpaMusic.size(); i++){
		if (m_xpaMusic[i]->GetName().compare(p_sName) == 0){
			m_xpCurrent = m_xpaMusic[i];
			m_xpCurrent->GetMusic()->setVolume((100.f / m_fVolume) * p_fVolume);
			Play();
		}
	}
}


void MusicMngr::Pause(){
	// pauses the current piece of music
	m_xpCurrent->GetMusic()->pause();
}

void MusicMngr::Stop(){
	// Stops the current piece of music
	m_xpCurrent->GetMusic()->stop();
}

void MusicMngr::SetVolume(float p_fVolume){
	// Sets the volume
	m_fVolume = p_fVolume;
}

float MusicMngr::GetVolume(){
	// Returns the current volume
	return m_fVolume;
}