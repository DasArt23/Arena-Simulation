#pragma once
#include "window/window.hpp"
#include "window/render.hpp"
#include <memory>

class Application{
private:
	std::string app_name;
	Window app_window;
	std::unique_ptr<Render> app_render;
	
	void handle(const MouseMove&);
	void handle(const KeyPressed&);
	void handle(const WindowResize&);
	void handle(const WindowClosed&);
public:
	Application(std::string app_name = "App");
	void run();
	void update(float dt);
};

