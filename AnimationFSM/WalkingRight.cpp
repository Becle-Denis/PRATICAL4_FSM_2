#include "WalkingRight.h"

#include "Idle.h"
#include "Jumping.h"
#include "Falling.h"

void WalkingRight::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jumping(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		falling(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		idle(a);
	}
}

void WalkingRight::idle(PlayerFSM* a)
{
	std::cout << "Walking Right -> Idle" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Idle());
	delete previous;
}

int WalkingRight::getSpriteIndex()
{
	return 5;
}



void WalkingRight::jumping(PlayerFSM* a)
{
	std::cout << "Walking Right -> Jumping" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Jumping());
	delete previous;
}

void WalkingRight::falling(PlayerFSM* a)
{
	std::cout << "Walking Right -> Falling" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Falling());
	delete previous;
}