#include "RunningRight.h"
#include "WalkingRight.h"

void RunningRight::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		walkingRight(a);
	}
}

void RunningRight::walkingRight(PlayerFSM* a)
{
	std::cout << "Running Right -> Walking Right" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new WalkingRight());
	delete previous;
}

int RunningRight::getSpriteIndex()
{
	return 7;
}
