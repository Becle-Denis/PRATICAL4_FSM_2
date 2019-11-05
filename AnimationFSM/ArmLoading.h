#ifndef ARMLOADING_H
#define ARMLOADING_H

#include <State.h>	

class ArmLoading : public State
{
public:
	ArmLoading() {};
	~ArmLoading() {};

	int getSpriteIndex() override;

	void update(PlayerFSM* a) override;

	void idle(PlayerFSM* a) override;
};

#endif // !ARMLOADING_H



