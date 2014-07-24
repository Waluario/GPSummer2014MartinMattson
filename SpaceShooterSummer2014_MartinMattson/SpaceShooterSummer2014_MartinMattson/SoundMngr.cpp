// SoundMngr.cpp //

#include "SoundMngr.h"

#include "Sfx.h"

std::string SoundMngr::m_sDir;

std::vector<sf::Sound*> SoundMngr::m_xpaSounds;
std::vector<Sfx*> SoundMngr::m_xpaSoundBuffers;

float SoundMngr::m_fListenerZ,
SoundMngr::m_fAttenuation,
SoundMngr::m_fMinDistance2D,
SoundMngr::m_fMinDistance3D,
SoundMngr::m_fVolume;

SoundMngr::SoundMngr(std::string p_sDir){
	// Sets all of the preset values
	m_sDir = p_sDir;

	m_fListenerZ = 300.f;
	m_fAttenuation = 8.f;
	m_fMinDistance2D = 200.f;
	m_fMinDistance3D = std::sqrt(m_fMinDistance2D*m_fMinDistance2D + m_fListenerZ*m_fListenerZ);
	m_fVolume = 100.f;
}

SoundMngr::~SoundMngr(){
	// Deletes all content in both vectors an dnulls the pointers
	for (int i = m_xpaSounds.size() - 1; i >= 0; i--){
		delete m_xpaSounds[i];
		m_xpaSounds[i] = NULL;
		m_xpaSounds.erase(m_xpaSounds.begin() + i);
	}

	for (int i = m_xpaSoundBuffers.size() - 1; i >= 0; i--){
		delete m_xpaSoundBuffers[i];
		m_xpaSoundBuffers[i] = NULL;
		m_xpaSoundBuffers.erase(m_xpaSoundBuffers.begin() + i);
	}
}

void *SoundMngr::Load(std::string p_sFname, std::string p_sName){
	// Creates a new SOund Bugfer
	sf::SoundBuffer *_xpSoundBuffer = new sf::SoundBuffer;

	// Loads the Buffer with data from a file
	if (!_xpSoundBuffer->loadFromFile(m_sDir + p_sFname)){
		return NULL;
	}

	// Puts the Buffer a tht e back of the SfxVector
	m_xpaSoundBuffers.push_back(new Sfx(p_sName, _xpSoundBuffer));
}

sf::Sound* SoundMngr::Play(std::string p_sName, float p_fVolume){
	RemoveStoppedSounds();
	return Play(p_sName, GetListenerPosition(), p_fVolume);
}

sf::Sound* SoundMngr::Play(std::string p_sName, sf::Vector2f p_vPos, float p_fVolume){
	// Looks through the entire vector and 
	for (int i = 0; i < m_xpaSoundBuffers.size(); i++){
		if (m_xpaSoundBuffers[i]->GetName().compare(p_sName) == 0){
			// Creates a new sound and puts in the back of the vector
			m_xpaSounds.push_back(new sf::Sound(*m_xpaSoundBuffers[i]->GetSoundBuffer()));
			// Sets all of the standard calues
			m_xpaSounds[m_xpaSounds.size() - 1]->setPosition(p_vPos.x, p_vPos.y, 0.f);
			m_xpaSounds[m_xpaSounds.size() - 1]->setAttenuation(m_fAttenuation);
			m_xpaSounds[m_xpaSounds.size() - 1]->setMinDistance(m_fMinDistance3D);
			
			//m_xpaSounds[m_xpaSounds.size() - 1]->setBuffer(*m_xpaSoundBuffers[i]->GetSoundBuffer());
			// Plays the sound and sets the volume
			m_xpaSounds[m_xpaSounds.size() - 1]->play();
			m_xpaSounds[m_xpaSounds.size() - 1]->setVolume((100.f / m_fVolume) * p_fVolume);

			// CHecks if the sound was created successfully
			if (m_xpaSounds[m_xpaSounds.size() - 1]->getBuffer() == NULL){
				throw std::runtime_error("Sound " + p_sName + " could not be loaded.");
			}

			// Returns the newly created sound
			return m_xpaSounds[m_xpaSounds.size() - 1];
		}
	}
	
	return NULL;
}

void SoundMngr::RemoveStoppedSounds(){
	// Checks trough all of the sounds in the vector
	for (int i = m_xpaSounds.size() - 1; i >= 0; i--){
		// checks if the sound is stopped, if so the sound is deleted and the pointer nulled
		if (m_xpaSounds[i]->getStatus() == sf::Sound::Status::Stopped){
			delete m_xpaSounds[i];
			m_xpaSounds[i] = NULL;
			m_xpaSounds.erase(m_xpaSounds.begin() + i);
		}
	}
}

void SoundMngr::SetListenerPosition(sf::Vector2f p_vPos){
	// sets the position of the listener
	sf::Listener::setPosition(p_vPos.x, -p_vPos.y, m_fListenerZ);
}

sf::Vector2f SoundMngr::GetListenerPosition(){
	// returns the position of the listener
	sf::Vector3f _vPos = sf::Listener::getPosition();
	return sf::Vector2f(_vPos.x, _vPos.y);
}

void SoundMngr::SetVolume(float p_fVolume){
	// Sets the volume
	m_fVolume = p_fVolume;
}

float SoundMngr::GetVolume(){
	// Returns the volume
	return m_fVolume;
}

std::vector<sf::Sound*> SoundMngr::GetSoundVector(){
	// Returns the Sound Vector
	return m_xpaSounds;
}

std::vector<Sfx*> SoundMngr::GetSfxVector(){
	// Returns the SOund Buffer vector
	return m_xpaSoundBuffers;
}