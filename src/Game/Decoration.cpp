#include "Decoration.h"
#include <Application.h>

Decoration::Decoration()
{
	_decorations = sf::VertexArray(sf::Lines, _segmentsCount * 2);
	for (int i = 0; i < _segmentsCount * 2; ++i) {
		_decorations[i].position = sf::Vector2f(WIDTH / 2, (i * 20) - 30);
		_decorations[i].color = sf::Color(255, 255, 255, 140);
	}
}

void Decoration::SetActive(bool state)
{
	_isActive = state;
}

void Decoration::Reset()
{
	for (int i = 0; i < _segmentsCount * 2; ++i) {
		_decorations[i].position = sf::Vector2f(WIDTH / 2, (i * 20) - 30);
	}
}

sf::Drawable* Decoration::GetDrawable()
{
	return &_decorations;
}

void Decoration::Update(float dt)
{
	if (_isActive) {
		for (int i = 0; i < _segmentsCount * 2; i += 2) {
			_decorations[i].position.y += _velocity * dt;
			_decorations[i + 1].position.y += _velocity * dt;
			if (_decorations[i].position.y > HEIGHT && _decorations[i + 1].position.y > HEIGHT) {
				_decorations[i].position.y = -40;
				_decorations[i + 1].position.y = -20;
			}
		}
	}
}
