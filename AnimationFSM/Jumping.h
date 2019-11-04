#ifndef JUMPING_H
#define JUMPING_H

#include <State.h>

class Jumping : public State
{
public:
	Jumping(int remainingJump = 1);
	~Jumping() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;
	void update(PlayerFSM* a) override;

	void jumping(PlayerFSM* a) override;
	void falling(PlayerFSM* a) override;

	int getSpriteIndex() override;
	
private:
	int m_remainingJump;
	long int m_timeCreated;
};

#endif // !IDLE_H