// KeybMngr.h //

#pragma once

#include <vector>

#include "Button.h"

class KeybMngr {
public:
	KeybMngr();
	~KeybMngr();

	void Update(float p_fDtime);

	static std::vector<Button*> GetVector();

private:
	static std::vector<Button*> m_xpaKeybPress;
};