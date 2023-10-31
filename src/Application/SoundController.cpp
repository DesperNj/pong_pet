#include "SoundController.h"
#include <cassert>

SoundController::SoundController()
{
	assert(LoadSounds() && "Sound loading error!");
}

SoundController* SoundController::Instance()
{
	static SoundController instance;
	return &instance;
}

void SoundController::PlaySound(SoundType type)
{
	switch (type)
	{
	case PADDLE:
		_soundStream.setBuffer(_paddleBuffer);
		_soundStream.play();
		break;
	case WALL:
		_soundStream.setBuffer(_wallBuffer);
		_soundStream.play();
		break;
	case SCORE:
		_soundStream.setBuffer(_scoreBuffer);
		_soundStream.play();
		break;
	default:
		break;
	}
}

bool SoundController::LoadSounds()
{
	if (_paddleBuffer.loadFromFile("paddle.wav") && _wallBuffer.loadFromFile("wall.wav") && _scoreBuffer.loadFromFile("score.wav")) {
		return true;
	}
	return false;
}
