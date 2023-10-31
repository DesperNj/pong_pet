#pragma once
#include "Ball.h"
#include "Platform.h"
#include "../Enemy/EnemyPlayer.h"
#include "Decoration.h"

enum PlayerType {
	PLAYER,
	ENEMY
};

class FieldManager : public UpdatableObject {
public:
	static FieldManager* Instance();
	bool Initialise();
	void SystemUpdate(float dt) override;
	Platform* GetPlatform(PlayerType type);
	void Score(PlayerType type);
	void SetGameActive(bool state);
	void ResetGame();
	void WinLogic(bool playerWon);
private:
	bool LoadFonts();
	std::unique_ptr<Platform> _platform = std::make_unique<Platform>();
	std::unique_ptr<Platform> _enemyPlatform = std::make_unique<Platform>(WIDTH - PLATFORM_PADDING);
	std::unique_ptr<Ball> _ball = std::make_unique<Ball>(*_platform.get(), *_enemyPlatform.get());
	std::unique_ptr<EnemyPlayer> _enemy = std::make_unique<EnemyPlayer>(*_ball.get(), *_enemyPlatform.get());
	std::unique_ptr<sf::Keyboard> _keyboard;
	sf::Font _pongFont, _labelFont;
	sf::Text _playerText, _enemyText, _finalText;
	std::unique_ptr<Decoration> _fieldDecoration = std::make_unique<Decoration>();
	bool _finishedState;
	int _playerScore, _enemyScore;

	FieldManager() {};
	~FieldManager() {};
	FieldManager(const FieldManager&) = delete;
	FieldManager* operator =(const FieldManager&) = delete;
};