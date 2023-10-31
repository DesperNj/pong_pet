#include "EnemyPlayer.h"
#include "../Game/Ball.h"
#include "../Game/Platform.h"

EnemyPlayer::EnemyPlayer(Ball& target, Platform& platform) : _target(target), _platform(platform)
{
}

void EnemyPlayer::SystemUpdate(float dt)
{
	if (_target.GetHorizontalMovement() > 0 && _platform.IsActive()) {
		if (_platform.GetPosition().y < _target.GetPosition().y + GetRandomFloat(-50 + _difficultyFactor, 50 - _difficultyFactor)) {
			_platform.MoveDown(dt);
		}
		else if (_platform.GetPosition().y > _target.GetPosition().y + GetRandomFloat(-50 + _difficultyFactor, 50 - _difficultyFactor)) {
			_platform.MoveUp(dt);
		}
	}
}
