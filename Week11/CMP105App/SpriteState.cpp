#include "SpriteState.h"

// Set the current State
void SpriteState::setState(SState s)
{
	state = s;
}

// Returns the current state.
SState SpriteState::getState()
{
	return state;
}