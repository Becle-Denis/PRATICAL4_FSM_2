#ifndef LANDING_H
#define LANDING_H

#include <State.h>

class Landing : public State
{
public:
	Landing();
	~Landing() {};
	
	void update(PlayerFSM* a) override;

	void idle(PlayerFSM* a) override;

	int getSpriteIndex() override;

private:
	long int m_timeCreated;
};



#endif // !LANDING_H




