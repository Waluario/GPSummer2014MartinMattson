// Main.cpp //

#include "stdafx.h"

#include "Core.h"

#include <stdlib.h>
#include <time.h>

int _tmain(int argc, _TCHAR* argv[]){
	srand(time(NULL));

	Core m_xCore;

	if (!m_xCore.Init()){
		return 0;
	}

	m_xCore.Run();
	m_xCore.Cleanup();

	return 0;
}