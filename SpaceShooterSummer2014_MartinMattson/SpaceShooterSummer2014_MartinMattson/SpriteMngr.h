// SpriteMngr.h //

class Sprite;

class SpriteMngr {
public:
	SpriteMngr();
	~SpriteMngr();

	bool Init(std::string p_sFname);

	Sprite* Load();

	Sprite* Load(std::string p_sFname);

private:
	std::string m_sDir;
	
	std::map<std::string, Sprite*> m_xpaSprites;
};