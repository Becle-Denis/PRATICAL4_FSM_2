#include "RunningLeft.h"
#include "WalkingLeft.h"



void RunningLeft::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		walkingLeft(a);
	}
}

void RunningLeft::walkingLeft(PlayerFSM* a)
{
	std::cout << "Running Left -> Walking Left" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new WalkingLeft());
	delete previous;
}

int RunningLeft::getSpriteIndex()
{
	return 5;
}