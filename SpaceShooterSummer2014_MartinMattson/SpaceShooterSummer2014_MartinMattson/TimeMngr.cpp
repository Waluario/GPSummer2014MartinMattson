// TimeMngr.cpp //

#include "TimeMngr.h"

#include <iostream>

float TimeMngr::m_fPace;

sf::Clock *TimeMngr::m_xpClock;

sf::Time TimeMngr::m_xDtime,
TimeMngr::m_xFps,
TimeMngr::m_xMaxFps;

TimeMngr::TimeMngr(sf::Clock *p_xpClock, sf::Time p_xFps){
	// Sets all of the standard variables
	m_xpClock = p_xpClock;
	m_xFps = p_xFps;
	m_xMaxFps = 1.1f * m_xFps;

	m_xDtime = sf::Time::Zero;

	m_fPace = 1.0f;
}

TimeMngr::~TimeMngr(){
	//Deletes the clock
	delete m_xpClock;
	m_xpClock = NULL;
}

bool TimeMngr::UpdDtime(){
	// Checks if the Delta time is greater or equal to the Fps and resets it if it is
	if (m_xDtime >= m_xFps){
		m_xDtime = sf::Time::Zero;
	}

	// Restarts the clock and adds time passed to the Delta TIme
	m_xDtime += m_xpClock->restart();

	if (m_xDtime >= m_xFps){
		// If the Delta TIme is equal or greater tahn the Fps this method returns true
		// This means that the game will update at a steady speed

		if (m_xDtime > m_xMaxFps){
			m_xDtime = m_xMaxFps;
		}

		return true;
	}

	// Returns false if the Delta TIme isn't equal or greater than the Fps yet
	return false;
}

float TimeMngr::GetDtime(bool p_bUsePace){
	// Returns the Delta TIme
	// If the pace is used (deafault)
	if (p_bUsePace){
		return (TimeMngr::m_xDtime.asSeconds() * m_fPace);
	}

	// Without using the pace
	return m_xDtime.asSeconds();
}

void TimeMngr::SetFps(sf::Time p_xFps){
	// Sets the Fps
	m_xFps = p_xFps;
	m_xMaxFps = 1.1f * m_xFps;
}

void TimeMngr::SetPace(float p_fPace){
	// Sets the pace to be used hwen obtaining the Delta TIme
	m_fPace = p_fPace;
}