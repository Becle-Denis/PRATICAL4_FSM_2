#ifndef WALKINGRIGHT_H
#define WALKINGRIGHT_H

#include <State.h>

class WalkingRight : public State
{
public:
	WalkingRight() {};
	~WalkingRight() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;

	void jumping(PlayerFSM* a) override;
	void falling(PlayerFSM* a) override;
	void idle(PlayerFSM* a) override;

	int getSpriteIndex() override;

};

#endif // !WALKINGRIGHT_H



