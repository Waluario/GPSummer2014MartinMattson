// TimeMngr.h //

#pragma once

class TimeMngr {
public:
	TimeMngr(sf::Clock *p_xpClock, sf::Time p_xFps);
	~TimeMngr();

	static bool UpdDtime();

	static float GetDtime(bool p_bUsePace = true);

	void SetFps(sf::Time p_xFps);

	void SetPace(float p_fPace);

private:
	static float m_fPace;

	static sf::Clock *m_xpClock;

	static sf::Time m_xDtime,
		m_xFps;
};