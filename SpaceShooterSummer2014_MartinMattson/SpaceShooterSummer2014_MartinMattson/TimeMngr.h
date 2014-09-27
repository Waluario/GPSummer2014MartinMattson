// TimeMngr.h //

#pragma once

class TimeMngr {
public:
	TimeMngr(sf::Clock *p_xpClock, sf::Time p_xFps);
	~TimeMngr();

	static bool UpdDtime(); // Updates the Delta TIme

	static float GetDtime(bool p_bUsePace = true); // Returns the Delta time, Can be called without using the Pace variable if needed

	static void SetFps(sf::Time p_xFps); // Sets the Fps

	static void SetPace(float p_fPace); // Sets the Pace

private:
	static float m_fPace; // The speed at which everything in-game moves

	static sf::Clock *m_xpClock; // THe Time Manager's Clock

	static sf::Time m_xDtime, // THe Delta TIme itself
		m_xFps, // THe Fps - How often the game should be updated
		m_xMaxFps; // The maximum allowed value of the delta time. Primarely set to 110 % of the normal FPS.
};