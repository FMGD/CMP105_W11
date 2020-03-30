#include "Character.h"

Character::Character()
{

}

Character::~Character()
{

}

SpriteState Character::getSpriteState()
{
	return sprite_state_;
}

void Character::setSpriteState(SState sprite_state)
{
	sprite_state_.setState(sprite_state);
}

void Character::setAudioManager(AudioManager* audio_manager)
{
	audio_mgr_ = audio_manager;
}