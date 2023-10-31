#pragma once
#include <utils/Utils.h>

class UpdateProvider;

class UpdatableObject {
public:
	UpdatableObject();
	virtual void SystemUpdate(float dt) {};
	virtual void Attach(UpdateProvider* provider);
	virtual ~UpdatableObject() = default;
};