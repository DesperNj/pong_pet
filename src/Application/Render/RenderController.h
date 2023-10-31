#pragma once
#include <UpdateProvider.h>
#include <GameObject.h>
#include <unordered_map>
#include <Application.h>

class RenderController : public UpdateProvider {
	friend class App;
public:
	static RenderController* Instance();
	void BindDrawableObject(GameObject* object);
	void BindTextObject(sf::Text* object, bool state = true);
	void SetTextObjectVisible(sf::Text* object, bool state);
private:
	void Update(float dt);
	void CloseWindow();
	App* _application;
	std::vector<GameObject*> _drawQueue;
	std::unordered_map<sf::Text*, bool> _textQueue;
	std::unique_ptr<sf::RenderWindow> _window;
	char* _title = "Pong";

	RenderController();
	~RenderController() {};
	RenderController(const RenderController&) = delete;
	RenderController* operator=(const RenderController&) = delete;

};