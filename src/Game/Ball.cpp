#include "Ball.h"
#include <SoundController.h>
#include "FieldManager.h"

Ball::Ball(Platform& player, Platform& enemy) : _player(player), _enemy(enemy)
{
	_shape.reset(new sf::CircleShape(BALL_RADIUS, 40));
	_shape->setOrigin(BALL_RADIUS, BALL_RADIUS);
	Reset();
}

sf::Vector2<float> Ball::GetPosition()
{
	return _shape->getPosition();
}

float Ball::GetHorizontalMovement()
{
	return _movementVector.x;
}

void Ball::Reset()
{
	_shape->setPosition(WIDTH / 2, HEIGHT / 2);
	GenerateNewVector();
}

void Ball::Update(float dt)
{
	if (CheckHorizontalCollision()) {
		CalculateRicochet(RicochetType::HORIZONTAL);
	}
	if (CheckVerticalCollision()) {
		CalculateRicochet(RicochetType::VERTICAL);
	}
	if (_shape->getPosition().x <= -BALL_RADIUS) {
		FieldManager::Instance()->Score(PlayerType::ENEMY);
	}
	if (_shape->getPosition().x >= WIDTH - BALL_RADIUS) {
		FieldManager::Instance()->Score(PlayerType::PLAYER);
	}
	_shape->move(_movementVector * velocity * dt);
}

void Ball::CalculateRicochet(RicochetType type)
{
	switch (type) {
	case VERTICAL:
		_movementVector.y = _movementVector.y * -1;
		SoundController::Instance()->PlaySound(SoundType::WALL);
		break;
	case HORIZONTAL:
		_movementVector.x = _movementVector.x * -1;
		SoundController::Instance()->PlaySound(SoundType::PADDLE);
		break;
	default:
		break;
	}
}

void Ball::GenerateNewVector()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dis(0, _quantifiers.size() - 1);

	float q1 = _quantifiers[dis(gen)];
	float q2 = _quantifiers[dis(gen)];
	_movementVector = { q1 + GetRandomFloat(-0.5,0.4), q2 + GetRandomFloat(-0.5,0.5) };
}

bool Ball::CheckVerticalCollision()
{
	if (_shape->getPosition().y <= BALL_RADIUS && _movementVector.y <= 0) {
		return true;
	}
	if (_shape->getPosition().y >= HEIGHT - BALL_RADIUS && _movementVector.y >= 0) {
		return true;
	}
	return false;
}

bool Ball::CheckHorizontalCollision()
{
	if (CheckPlatformCollision(_player) && _movementVector.x <= 0) {
		return true;
	}
	if (CheckPlatformCollision(_enemy) && _movementVector.x >= 0) {
		return true;
	}
	return false;
}


bool Ball::CheckPlatformCollision(Platform& target)
{
	return _shape->getGlobalBounds().intersects(target.GetPlatformBounds());
}