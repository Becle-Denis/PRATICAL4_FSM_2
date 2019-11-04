#ifndef WALKINGLEFT_H
#define WALKINGLEFT_H

#include <State.h>

class WalkingLeft :public State
{
public:

	WalkingLeft() {};
	~WalkingLeft() {};

	void handleInput(PlayerFSM* a, sf::Event event) override;

	void jumping(PlayerFSM* a) override;
	void falling(PlayerFSM* a) override;
	void idle(PlayerFSM* a) override;

	int getSpriteIndex() override;
};


#endif // !WALKINGLEFT_H



