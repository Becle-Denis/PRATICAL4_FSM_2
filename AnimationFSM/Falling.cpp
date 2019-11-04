#include "Falling.h"
#include "Landing.h"
#include "Jumping.h"
#include <ctime>
#include <string>

Falling::Falling(int remaingJump)
	: m_remainingJump(remaingJump),
	m_timeCreated(static_cast<long int>(time(nullptr)))
{

}

void Falling::update(PlayerFSM* a)
{
	long int actualTime = static_cast<long int>(time(nullptr));
	if (actualTime > m_timeCreated + 1)
	{
		landing(a);
	}
}

void Falling::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jumping(a);
	}
}


void Falling::landing(PlayerFSM* a)
{
	std::cout << "Falling -> Landing" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Landing());
	delete previous;
}

int Falling::getSpriteIndex()
{
	return 0;
}



void Falling::jumping(PlayerFSM* a)
{
	if (m_remainingJump > 0)
	{
		m_remainingJump--;
		State* previous = a->getPrevious();
		std::cout << "Falling -> Jumping" << std::endl;
		a->setPrevious(a->getCurrent());
		a->setCurrent(new Jumping(m_remainingJump));
		delete previous;
	}
}