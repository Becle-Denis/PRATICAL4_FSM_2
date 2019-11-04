#include <PlayerFSM.h>
#include <Idle.h>

PlayerFSM::PlayerFSM()
{
	m_current = new Idle();
}

PlayerFSM::~PlayerFSM() {}

void PlayerFSM::setCurrent(State* s)
{
	m_current = s;
}

State* PlayerFSM::getCurrent()
{
	return m_current;
}

void PlayerFSM::setPrevious(State* s)
{
	m_previous = s;
}

State* PlayerFSM::getPrevious()
{
	return m_previous;
}

void PlayerFSM::update()
{
	m_current->update(this);
}

void PlayerFSM::handleInput(sf::Event& event)
{
	m_current->handleInput(this, event);
}

int PlayerFSM::getSpriteIndex()
{
	return m_current->getSpriteIndex();
}

