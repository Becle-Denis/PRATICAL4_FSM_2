#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class Player
{
private:
	PlayerFSM m_state;
	std::vector<AnimatedSprite> m_animated_sprites;
	Player();

public:
	Player(const std::vector<AnimatedSprite>&);
	~Player();
	AnimatedSprite& getAnimatedSprite();
	void handleInput(sf::Event& event);
	void update();
};

#endif // !PLAYER_H
