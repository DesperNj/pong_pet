#pragma once
#include <GameObject.h>

class Platform : public GameObject {
public:
	Platform(int xLocation = PLATFORM_PADDING);
	void MoveUp(float dt);
	void MoveDown(float dt);
	const sf::FloatRect GetPlatformBounds();
	sf::Vector2<float> GetPosition();
	void Reset();
private:
	void Update(float dt) override {};
	float _velocity = 350;
	float _xLocation;
};