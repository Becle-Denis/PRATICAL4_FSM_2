#include "Landing.h"
#include "Idle.h"


Landing::Landing() :
	m_timeCreated(static_cast<long int>(time(nullptr)))
{

}

void Landing::update(PlayerFSM* a)
{
	long int actualTime = static_cast<long int>(time(nullptr));
	if (actualTime > m_timeCreated)
	{
		idle(a);
	}
}

void Landing::idle(PlayerFSM* a)
{
	std::cout << "Landing -> Idle" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete previous;
}

int Landing::getSpriteIndex()
{
	return 3;
}
