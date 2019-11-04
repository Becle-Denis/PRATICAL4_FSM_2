#include "WalkingLeft.h"
#include "Idle.h"
#include "Jumping.h"
#include "Falling.h"

void WalkingLeft::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jumping(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		falling(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		idle(a);
	}
}

void WalkingLeft::idle(PlayerFSM* a)
{
	std::cout << "Walking Left -> Idle" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete previous;
}

int WalkingLeft::getSpriteIndex()
{
	return 4;
}



void WalkingLeft::jumping(PlayerFSM* a)
{
	std::cout << "Walking Left -> Jumping" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Jumping());
	delete previous;
}

void WalkingLeft::falling(PlayerFSM* a)
{
	std::cout << "Walking Left -> Falling" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Falling());
	delete previous;
}