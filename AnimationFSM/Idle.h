#ifndef IDLE_H
#define IDLE_H

#include <State.h>

class Idle : public State
{
public:

	Idle() {};
	~Idle() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;

	void jumping(PlayerFSM* a) override;
	void falling(PlayerFSM* a) override;
	void walkingLeft(PlayerFSM* a) override;
	void walkingRight(PlayerFSM* a) override;

	int getSpriteIndex() override;
};

#endif // !IDLE_H