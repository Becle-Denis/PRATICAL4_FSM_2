#include <Jumping.h>
#include <Idle.h>
#include <Falling.h>
#include <string>
#include <ctime>


Jumping::Jumping(int remainingJump) : 
	m_remainingJump(remainingJump),
	m_timeCreated(static_cast<long int>(time(nullptr)))
{

}

void Jumping::handleInput(PlayerFSM* a, sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jumping(a);
	}
}

void Jumping::update(PlayerFSM* a)
{
	long int actualTime = static_cast<long int>(time(nullptr));
	if (actualTime > m_timeCreated + 1)
	{
		falling(a);
	}
}

void Jumping::jumping(PlayerFSM* a)
{
	if (m_remainingJump > 0)
	{
		m_remainingJump--;
		std::cout << "Jumping -> Jumping" << std::endl;
		State* previous = a->getPrevious();
		a->setPrevious(a->getCurrent());
		a->setCurrent(new Jumping(m_remainingJump));
		delete previous;
	}
}

void Jumping::falling(PlayerFSM* a)
{
	std::cout << "Jumping -> Falling" << std::endl;
	State* previous = a->getPrevious();
	a->setPrevious(a->getCurrent());
	a->setCurrent(new Falling(m_remainingJump));
	delete previous;
}

int Jumping::getSpriteIndex()
{
	return 2;
}


/*
void Jumping::idle(PlayerFSM* a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

*/