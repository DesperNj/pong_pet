#pragma once
#include <GameObject.h>

class Decoration : public GameObject {
public:
	Decoration();
	void SetActive(bool state);
	void Reset();
	sf::Drawable* GetDrawable() override;
private:
	void Update(float dt) override;
	bool _isActive = false;
	sf::VertexArray _decorations;
	int _segmentsCount = 16;
	int _velocity = 60;
};