#ifndef RUNNINGRIGHT_H
#define RUNNINGRIGHT_H

#include <State.h>

class RunningRight :public State
{
public:

	RunningRight() {};
	~RunningRight() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;

	void walkingRight(PlayerFSM* a) override;

	int getSpriteIndex() override;
};


#endif // !RUNNINGRIGHT_H



