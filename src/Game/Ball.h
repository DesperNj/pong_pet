#pragma once
#include <GameObject.h>

class Platform;

enum RicochetType {
	VERTICAL,
	HORIZONTAL
};

class Ball : public GameObject {
public:
	Ball(Platform& player, Platform& enemy);
	sf::Vector2<float> GetPosition();
	float GetHorizontalMovement();
	void Reset();
private:
	void Update(float dt) override;
	void CalculateRicochet(RicochetType type);
	void GenerateNewVector();
	bool CheckVerticalCollision();
	bool CheckHorizontalCollision();
	bool CheckPlatformCollision(Platform& target);
	sf::Vector2<float> _movementVector;
	Platform& _player, & _enemy;
	std::vector<float> _quantifiers{ -1, 1 };
	float velocity = 300;
};