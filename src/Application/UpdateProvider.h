#pragma once
#include <utils/Utils.h>
#include <list>

class UpdatableObject;


class UpdateProvider {
public:
	virtual ~UpdateProvider() = default;

	void Attach(UpdatableObject* observer);
	void Detach(UpdatableObject* observer);
	void Notify(float dt);

private:
	std::list<UpdatableObject*> _observersList;
};