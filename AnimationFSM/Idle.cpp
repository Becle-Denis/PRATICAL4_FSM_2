#include <Idle.h>
#include <Jumping.h>
#include <WalkingLeft.h>
#include <WalkingRight.h>
#include <Falling.h>
#include <ArmLoading.h>

#include <string>


void Idle::handleInput(PlayerFSM* a, sf::Event event)
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
		walkingLeft(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		walkingRight(a);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		armLoading(a);
	}
}


void Idle::walkingLeft(PlayerFSM* a)
{
	std::cout << "Idle -> Walking Left" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new WalkingLeft());
	delete previous;
}

void Idle::walkingRight(PlayerFSM* a)
{
	std::cout << "Idle -> Walking Right" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new WalkingRight());
	delete previous;
}

void Idle::armLoading(PlayerFSM* a)
{
	std::cout << "Idle -> Arm Loading" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new ArmLoading());
	delete previous;
}

int Idle::getSpriteIndex()
{
	return 1;
}

void Idle::jumping(PlayerFSM* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Jumping());
	delete previous;
}

void Idle::falling(PlayerFSM* a)
{
	std::cout << "Idle -> Falling" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Falling());
	delete previous;
}







/*
void Idle::jumping(PlayerFSM* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

*/