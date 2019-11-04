#include "runningLeft.h"
#include "WalkingLeft.h"



void runningLeft::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		walkingLeft(a);
	}
}

void runningLeft::walkingLeft(PlayerFSM* a)
{
	std::cout << "Running Left -> Walking Left" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new WalkingLeft());
	delete previous;
}

int runningLeft::getSpriteIndex()
{
	return 5;
}
