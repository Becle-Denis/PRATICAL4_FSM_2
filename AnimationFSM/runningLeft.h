#ifndef RUNNINGLEFT_H
#define RUNNINGLEFT_H

#include <State.h>

class runningLeft : public State
{
	runningLeft() {};
	~runningLeft() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;

	void walkingLeft(PlayerFSM* a) override;

	virtual int getSpriteIndex();
};


#endif // !RUNNINGLEFT_H


