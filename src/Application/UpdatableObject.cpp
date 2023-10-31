#include "UpdatableObject.h"
#include <UpdateProvider.h>
#include <Application.h>

UpdatableObject::UpdatableObject()
{
	RenderController::Instance()->Attach(this);
}

void UpdatableObject::Attach(UpdateProvider* provider)
{
	provider->Attach(this);
}
