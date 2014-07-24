// MusicMngr.h //

#include <vector>

#pragma once

class Bgm;

class MusicMngr {
public:
	MusicMngr(std::string p_sDir);
	~MusicMngr();

	static void Load(std::string p_sFname, std::string p_sName); // Loads a specific music file

	static void Play(float p_fVolume = 100.f); // Plays the active music
	static void Play(std::string p_sName, float p_fVolume = 100.f); // Sets and plays a piece of music

	static void Pause(); // Pauses the active piece of music
	static void Stop(); // 

	static void SetVolume(float p_fVolume = 100.f); // Sets the music voume, is set to 100 by default
	static float GetVolume(); // returns the volume

private:
	static std::string m_sDir; // the directory where music will be downloaded from

	static std::vector<Bgm*> m_xpaMusic; // the vector of background music
	static Bgm *m_xpCurrent; // Points at the current background music

	static float m_fVolume; // current volume
};