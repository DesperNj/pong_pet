#pragma once
#include <Application.h>
#include <UpdatableObject.h>

class EnemyPlayer : public UpdatableObject {
public:
	EnemyPlayer(Ball& target, Platform& platform);
	int _difficultyFactor = 0;
private:
	Ball& _target;
	Platform& _platform;
	void SystemUpdate(float dt) override;
};