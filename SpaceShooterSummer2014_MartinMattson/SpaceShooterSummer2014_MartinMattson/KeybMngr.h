// KeybMngr.h //

#pragma once

#include <vector>

#include "Button.h"

class KeybMngr {
public:
	KeybMngr();
	~KeybMngr();

	void Update(float p_fDtime); // Updates the Keyboard Manager using the Delta TIme

	static float GetButtonPressedTime(int p_iKey); // Returns for how long a button has been pressed

	static bool GetButtonPressed(int p_iKey); // Returns wether or not a button is being pressed
	static bool GetButtonPressedOnce(int p_iKey); // Returns wther or not a buttin is being pressed once

	static std::string GetButtonSymbol(int p_iKey); // Returns a string of the button

	static std::vector<Button*> GetVector(); // Returns the entire vector

private:
	static std::vector<Button*> m_xpaKeybPress;
};