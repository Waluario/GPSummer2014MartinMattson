// SoundMngr.h //

#include <vector>

#pragma once

class Sfx;

class SoundMngr {
public:
	SoundMngr(std::string p_sDir);
	~SoundMngr();

	static void *Load(std::string p_sFname, std::string p_sName); // Loads a new piece of sound into a SoundBuffer

	static sf::Sound* Play(std::string p_sName, float p_fVolume = 100.f); // Plays a piece of sound at requested volume
	static sf::Sound* Play(std::string p_sName, sf::Vector2f p_vPos, float p_fVolume = 100.f); // Plays a piece of sound at requested volume in a specific position

	static void RemoveStoppedSounds(); // Removes all stopped sounds

	static void SetListenerPosition(sf::Vector2f p_vPos); // Sets the listener position
	static sf::Vector2f GetListenerPosition(); // Returns the listeneer position

	static void SetVolume(float p_fVolume); // Sets the volume
	static float &GetVolume(); // Returns the volume

	static std::vector<sf::Sound*> GetSoundVector(); // Teturns the Sound Vector
	static std::vector<Sfx*> GetSfxVector(); // Returns the vector with SOund Buffers

private:
	static std::string m_sDir; // The Directory from where all sound effects will be loaded

	static std::vector<sf::Sound*> m_xpaSounds; // A vector of sounds
	static std::vector<Sfx*> m_xpaSoundBuffers; // A vector of Sound Buffers with names attached to them for identification

	static float m_fListenerZ, // Various variables that affects the sound
		m_fAttenuation,
		m_fMinDistance2D,
		m_fMinDistance3D,
		m_fVolume; // Current Master Volume
};