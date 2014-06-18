// KeybMngr.h //

#include <vector>

#include "Button.h"

class KeybMngr {
public:
	KeybMngr();
	~KeybMngr();

	void Update(float p_fDtime);

	static std::vector<Button*> GetVector();

public:
	static std::vector<Button*> m_xaKeybPress;
};