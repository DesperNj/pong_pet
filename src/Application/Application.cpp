#include "Application.h"
#include "../Game/FieldManager.h"

void App::Start() {
	FieldManager::Instance()->Initialise();
	RenderController::Instance()->_application = this;
	_isRunning = true;
	Update();
}

void App::Finish() {
	_isRunning = false;
}

void App::Update() {
	while (_isRunning) {
		_frameTimeStamp = _gameClock->getElapsedTime().asSeconds();
		RenderController::Instance()->Notify(_frameTimeStamp - _lastFrameStamp);
		RenderController::Instance()->Update(_frameTimeStamp - _lastFrameStamp);
		_lastFrameStamp = _frameTimeStamp;
	}
}
