// KeybMngr.h //

#include <vector>

class Button;

class KeybMngr {
public:
	KeybMngr();
	~KeybMngr();

	void Update(float p_fDtime);

	std::vector<Button*> GetVector();

public:
	std::vector<Button*> m_xaKeybPress;
};