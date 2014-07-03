// TimeMngr.cpp //

#include "TimeMngr.h"

#include <iostream>

float TimeMngr::m_fPace;

sf::Clock *TimeMngr::m_xpClock;

sf::Time TimeMngr::m_xDtime,
TimeMngr::m_xFps;

TimeMngr::TimeMngr(sf::Clock *p_xpClock, sf::Time p_xFps){
	m_xpClock = p_xpClock;
	m_xFps = p_xFps;

	m_xDtime = sf::Time::Zero;

	m_fPace = 1.0f;
}

TimeMngr::~TimeMngr(){

}

bool TimeMngr::UpdDtime(){
	if (m_xDtime >= m_xFps){
		m_xDtime = sf::Time::Zero;
	}

	m_xDtime += m_xpClock->restart();

	if (m_xDtime >= m_xFps){
		//std::cout << m_xDtime.asSeconds() << std::endl;
		
		return true;
	}

	return false;
}

float TimeMngr::GetDtime(bool p_bUsePace){
	if (p_bUsePace){
		return (TimeMngr::m_xDtime.asSeconds() * m_fPace);
	}

	return TimeMngr::m_xDtime.asSeconds();
}

void TimeMngr::SetFps(sf::Time p_xFps){
	m_xFps = p_xFps;
}

void TimeMngr::SetPace(float p_fPace){
	m_fPace = p_fPace;
}