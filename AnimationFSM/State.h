#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <SFML/Graphics.hpp>
#include <PlayerFSM.h>
#include <Debug.h>

class State
{
public:
	virtual void handleInput(PlayerFSM* a, sf::Event event) {};

	virtual void update(PlayerFSM* a) {};

	virtual int getSpriteIndex() { return 0; };

	virtual void falling(PlayerFSM* a) {};

	virtual void idle(PlayerFSM* a) {};

	virtual void jumping(PlayerFSM* a) {};

	virtual void landing(PlayerFSM* a) {};

	virtual void walkingLeft(PlayerFSM* a) {};

	virtual void walkingRight(PlayerFSM* a) {};
};

#endif // ! ANIMATION_H

