// TimeMngr.h //

#pragma once

class TimeMngr {
public:
	TimeMngr();
	~TimeMngr();

	static bool UpdDtime();

	static sf::Time GetDtime(bool p_bUsePace = true);

	void SetFps(sf::Time p_xFps);

	void SetPace(float p_fPace);

private:
	static float m_fPace;

	static sf::Clock *m_xpClock;

	static sf::Time m_xDtime,
		m_xFps;
};