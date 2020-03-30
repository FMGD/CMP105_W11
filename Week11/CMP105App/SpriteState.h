// Sprite State Class
// Simple sprite State controller. enum lists possible sprite States (can be modified), tracks and change the State
// @author Paul Robertson

#pragma once

// Possible States. This enum can be modified to add additional States as required.
enum class SState { STILL, WALKING, JUMPING, DUCKING, DEAD };

class SpriteState
{
public:
	// Set the State
	void setState(SState s);
	// Returns the State
	SState getState();

protected:
	SState state;
};
