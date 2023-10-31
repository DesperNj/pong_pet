#pragma once
#include <utils/Utils.h>
#include <SFML/Audio.hpp>

enum SoundType {
	PADDLE,
	WALL,
	SCORE
};

class SoundController  {
public:
	static SoundController* Instance();
	void PlaySound(SoundType type);
private:
	bool LoadSounds();
	SoundController();
	~SoundController() {};
	SoundController(const SoundController&) = delete;
	SoundController* operator=(const SoundController&) = delete;

	sf::SoundBuffer _paddleBuffer, _wallBuffer, _scoreBuffer;
	sf::Sound _soundStream;
};