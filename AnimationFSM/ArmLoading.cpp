#include "ArmLoading.h"
#include "Idle.h"

int ArmLoading::getSpriteIndex()
{
	return 0;
}

void ArmLoading::update(PlayerFSM* a)
{
	if ( ! (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
		idle(a);
	}
}

void ArmLoading::idle(PlayerFSM* a)
{
	std::cout << "Arm Loading -> Idle" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete previous;
}
