#pragma once
#include <UpdatableObject.h>

class GameObject : public UpdatableObject {
public:
	GameObject();
	bool IsVisible();
	bool IsActive();
	void SetVisible(bool state);
	void SetActive(bool state);
	virtual sf::Drawable* GetDrawable();
	virtual void Update(float dt) {};
protected:
	std::unique_ptr<sf::Shape> _shape;
private:
	void SystemUpdate(float dt) override;
	bool _isVisible = true;
	bool _isActive = true;
};