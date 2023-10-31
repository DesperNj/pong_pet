#include "RenderController.h"

RenderController::RenderController()
{
	_window.reset(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), _title));
}

void RenderController::Update(float dt)
{
	_window->clear();

	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			CloseWindow();
			_application->Finish();
		}
	}

	for (GameObject* drawObject : _drawQueue) {
		if (drawObject->IsVisible() && drawObject->GetDrawable()) {
			_window->draw(*drawObject->GetDrawable());
		}
	}
	
	for (auto text : _textQueue) {
		if (text.second) {
			_window->draw(*text.first);
		}
	}
	_window->display();
}

void RenderController::CloseWindow()
{
	_window->close();
}

RenderController* RenderController::Instance()
{
	static RenderController instance;
	return &instance;
}

void RenderController::BindDrawableObject(GameObject* object)
{
	_drawQueue.push_back(object);
}

void RenderController::BindTextObject(sf::Text* object, bool state)
{
	_textQueue.insert(std::make_pair(object, state));
}

void RenderController::SetTextObjectVisible(sf::Text* object, bool state)
{
	_textQueue[object] = state;
}
