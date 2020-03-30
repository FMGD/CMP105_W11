#pragma once
#include "Character.h"
#include "Framework/Animation.h"
#include <vector>
#include <string>
#include <iostream>

class Player : public Character
{
private:
	float scale_;
	sf::Vector2f gravity_;
	sf::Vector2f jump_vector_;

	Animation walk_;
	Animation* current_animation_;
	bool animate_;

public:

	// Constructor
	Player();

	// Destructor
	~Player();

	// Functions
	void update(float dt) override;
	void handleInput(float dt) override;
	void collisionResponse(GameObject* collider) override;
	void applyGravityForce(float dt);

};