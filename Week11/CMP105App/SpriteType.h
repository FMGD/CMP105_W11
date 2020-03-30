// Sprite Type Class
// Simple sprite type controller. enum lists possible sprite types (can be modified), tracks and change the type
// @author Francisco Diaz

#pragma once

// Possible types. This enum can be modified to add additional types as required.
enum class SType { WORLD, BULLET, PLAYER, ENEMY };

class SpriteType
{
public:
	// Set the type
	void setType(SType t);
	// Returns the type
	SType getType();

protected:
	SType type;
};
