#include "Platform.h"
#include "Application.h"

Platform::Platform(int xLocation) : _xLocation(xLocation)
{
	_shape.reset(new sf::RectangleShape({ PLATFORM_WIDTH, PLATFORM_HEIGHT }));
	_shape->setOrigin(PLATFORM_WIDTH / 2, PLATFORM_HEIGHT / 2);
	_shape->setFillColor(sf::Color(255, 255, 255));
	Reset();
}

void Platform::MoveUp(float dt)
{
	if (IsActive() && _shape->getPosition().y - (PLATFORM_HEIGHT / 2) >= 0) {
		_shape->move(0, -_velocity * dt);
	}
}

void Platform::MoveDown(float dt)
{
	if (IsActive() && _shape->getPosition().y + (PLATFORM_HEIGHT / 2) <= HEIGHT) {
		_shape->move(0, _velocity * dt);
	}
}

const sf::FloatRect Platform::GetPlatformBounds()
{
	return _shape->getGlobalBounds();
}

sf::Vector2<float> Platform::GetPosition()
{
	return _shape->getPosition();
}

void Platform::Reset()
{
	_shape->setPosition(_xLocation, HEIGHT / 2);
}
