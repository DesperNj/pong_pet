#include "UpdateProvider.h"
#include <UpdatableObject.h>

void UpdateProvider::Attach(UpdatableObject* observer)
{
	_observersList.push_back(observer);
}

void UpdateProvider::Detach(UpdatableObject* observer)
{
	_observersList.remove(observer);
}

void UpdateProvider::Notify(float dt)
{
	for (UpdatableObject* observer : _observersList) {
		observer->SystemUpdate(dt);
	}
}
