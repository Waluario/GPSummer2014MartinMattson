// Main.cpp //

#include "stdafx.h"

#include "Core.h"

#include <stdlib.h>
#include <time.h>

//#include <vld.h>

int _tmain(int argc, _TCHAR* argv[]){
	// Sets the randomizer
	srand(time(NULL));

	// Creates the core engine
	Core m_xCore;

	//Initializes the core engine
	if (!m_xCore.Init()){
		return 0;
	}

	// Runs the core engine until it's time to stop and then cleans it up
	m_xCore.Run();
	m_xCore.Cleanup();

	return 0;
}