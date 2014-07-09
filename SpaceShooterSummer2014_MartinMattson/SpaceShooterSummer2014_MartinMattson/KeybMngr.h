// KeybMngr.h //

#pragma once

#include <vector>

#include "Button.h"

class KeybMngr {
public:
	KeybMngr();
	~KeybMngr();

	void Update(float p_fDtime);

	static float GetButtonPressedTime(int p_iKey);

	static bool GetButtonPressed(int p_iKey);
	static bool GetButtonPressedOnce(int p_iKey);

	static std::vector<Button*> GetVector();

private:
	static std::vector<Button*> m_xpaKeybPress;
};