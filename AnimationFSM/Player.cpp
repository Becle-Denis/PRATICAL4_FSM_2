#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const std::vector<AnimatedSprite>& s) : m_animated_sprites(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int spriteIndex = m_state.getSpriteIndex();
	int frame = m_animated_sprites.at(spriteIndex).getCurrentFrame();
	m_animated_sprites.at(spriteIndex).setTextureRect(m_animated_sprites.at(spriteIndex).getFrame(frame));
	return m_animated_sprites.at(spriteIndex);
}

void Player::handleInput(sf::Event& event)
{
	DEBUG_MSG("Handle Input");
	m_state.handleInput(event);
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_state.update();
	m_animated_sprites.at(m_state.getSpriteIndex()).update();
}