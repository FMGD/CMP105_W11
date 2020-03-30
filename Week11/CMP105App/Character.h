#pragma once
#include "FrameWork/GameObject.h"
#include "Framework/AudioManager.h"
#include "SpriteState.h"
class Character :	public GameObject
{
public:
	Character();
	~Character();

	SpriteState getSpriteState();
	void setSpriteState(SState sprite_state);
	void setAudioManager(AudioManager* audio_manager);

protected:
	SpriteState sprite_state_;
	AudioManager* audio_mgr_;
};

