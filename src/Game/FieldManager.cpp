#include "FieldManager.h"
#include <cassert>
#include <SoundController.h>

FieldManager* FieldManager::Instance()
{
	static FieldManager instance;
	return &instance;
}

bool FieldManager::Initialise()
{
	_keyboard.reset(new sf::Keyboard);
	assert(LoadFonts() && "Fonts loading error!");

	_playerText.setFont(_pongFont);
	_playerText.setCharacterSize(110);
	_playerText.setFillColor(sf::Color(255, 255, 255, 140));
	_playerText.setString("0");
	_playerText.setPosition(170, 30);

	_enemyText.setFont(_pongFont);
	_enemyText.setCharacterSize(110);
	_enemyText.setFillColor(sf::Color(255, 255, 255, 140));
	_enemyText.setString("0");
	_enemyText.setPosition(WIDTH - 230, 30);

	_finalText.setFont(_labelFont);
	_finalText.setFillColor(sf::Color::White);
	_finalText.setCharacterSize(200);
	_finalText.setPosition(WIDTH / 5, HEIGHT / 4);

	RenderController::Instance()->BindTextObject(&_finalText, false);
	RenderController::Instance()->BindTextObject(&_enemyText);
	RenderController::Instance()->BindTextObject(&_playerText);
	SetGameActive(false);
	return true;
}

void FieldManager::SystemUpdate(float dt)
{
	if (_finishedState) {
		if (_keyboard->isKeyPressed(sf::Keyboard::Space)) {
			_playerText.setString("0");
			_enemyText.setString("0");
			ResetGame();
		}
		return;
	}
	if (_keyboard->isKeyPressed(sf::Keyboard::Up) || _keyboard->isKeyPressed(sf::Keyboard::W)) {
		_platform->MoveUp(dt);
		SetGameActive(true);
	}
	if (_keyboard->isKeyPressed(sf::Keyboard::Down) || _keyboard->isKeyPressed(sf::Keyboard::S)) {
		_platform->MoveDown(dt);
		SetGameActive(true);
	}
}

Platform* FieldManager::GetPlatform(PlayerType type)
{
	switch (type)
	{
	case PLAYER:
		return _platform.get();
		break;
	case ENEMY:
		return _enemyPlatform.get();
		break;
	}
	return nullptr;
}

void FieldManager::Score(PlayerType type)
{
	SetGameActive(false);
	switch (type)
	{
	case PLAYER:
		++_playerScore;
		_playerText.setString(std::to_string(_playerScore));
		break;
	case ENEMY:
		++_enemyScore;
		_enemyText.setString(std::to_string(_enemyScore));
		break;
	}
	SoundController::Instance()->PlaySound(SoundType::SCORE);
	_enemy->_difficultyFactor = _playerScore - _enemyScore;
	if (_playerScore == 11) {
		WinLogic(true);
	}
	else if (_enemyScore == 11) {
		WinLogic(false);
	}
	else {
		ResetGame();
	}
}

void FieldManager::SetGameActive(bool state)
{
	_ball->SetActive(state);
	_platform->SetActive(state);
	_enemyPlatform->SetActive(state);
	_fieldDecoration->SetActive(state);
}

void FieldManager::ResetGame()
{
	_ball->Reset();
	_platform->Reset();
	_enemyPlatform->Reset();
	_fieldDecoration->Reset();
	RenderController::Instance()->SetTextObjectVisible(&_finalText, false);
	_finishedState = false;
}

void FieldManager::WinLogic(bool playerWon)
{
	if (playerWon) {
		_finalText.setString("You Won!");
	}
	else {
		_finalText.setString("You Lost!");
	}
	RenderController::Instance()->SetTextObjectVisible(&_finalText, true);
	_finishedState = true;
	_playerScore = 0;
	_enemyScore = 0;
}

bool FieldManager::LoadFonts()
{
	if (_pongFont.loadFromFile("pong-score.ttf") && _labelFont.loadFromFile("FinalTitle.ttf")) {
		return true;
	}
	return false;
}
