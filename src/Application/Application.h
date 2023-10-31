#pragma once
#include "Render/RenderController.h"
#include <SFML/Audio.hpp>

class Ball;
class Platform;

class App {
public:
	void Start();
	void Finish();
	void Update();
private:
	std::unique_ptr<sf::Clock> _gameClock = std::make_unique<sf::Clock>();

	float _frameTimeStamp = 0;
	float _lastFrameStamp = 0;
	bool _isRunning = false;
};
