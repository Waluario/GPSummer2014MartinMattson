// Sfx.h //

#pragma once

class Sfx {
public:
	Sfx(std::string p_sName, sf::SoundBuffer *p_xpSBuffer);
	~Sfx();

	std::string GetName();
	void SetName(std::string p_sName);

	sf::SoundBuffer* GetSoundBuffer();
	void SetSoundBuffer(sf::SoundBuffer *p_xpSBuffer);

private:
	std::string m_sName;

	sf::SoundBuffer *m_xpSBuffer;
};