// State.h //

class State {
public:
	virtual ~State() {};

	virtual bool Enter() = 0;
	virtual void Exit() = 0;
	virtual bool Update(float p_fDtime) = 0;  // Parameter_FloatingDtime
	virtual void Draw() = 0;
	virtual std::string Next() = 0;
	virtual bool IsType(const std::string &p_sType) = 0; // Parameter_StringType
};