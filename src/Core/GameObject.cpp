#include "GameObject.h"
#include <Render/RenderController.h>

GameObject::GameObject() {
	RenderController::Instance()->BindDrawableObject(this);
}

bool GameObject::IsVisible()
{
	return _isVisible;
}

bool GameObject::IsActive()
{
	return _isActive;
}

void GameObject::SetVisible(bool state)
{
	_isVisible = state;
}

void GameObject::SetActive(bool state)
{
	_isActive = state;
}

sf::Drawable* GameObject::GetDrawable()
{
	return _shape.get();
}

void GameObject::SystemUpdate(float dt)
{
	if (_isActive) {
		Update(dt);
	}
}

