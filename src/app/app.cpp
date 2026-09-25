#include "app.hpp"
#include "window/window.hpp"
#include "window/shape.hpp"
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <variant>
#include <vector>

Application::Application(std::string name):app_name(name),app_window(app_name){
	app_window.set_default_size();
	app_window.create();
	app_render = std::make_unique<Render>(app_window.get_target());
}

void Application::run(){
	Shape* rect = new RectShape(Vec2(1000.0f, 200.0f), Vec2(100.0f, 100.0f), sf::Color::Magenta);
	std::vector<Shape*> shapes = {rect};
	while(app_window.isOpen()){
		update();
		if(!app_window.isOpen()) break;
		app_render->render(shapes);
		app_window.display();
	}
	for(Shape* shape : shapes) delete shape;
}

void Application::update(){
	app_window.poll_events();
	for(const auto& cmd : app_window.get_commands()){
		std::visit([this](const auto& c){ handle(c); }, cmd);
	}
}

void Application::handle(const MouseMove& m) {
    std::cout << "mouse: " << m.x << ", " << m.y << "\n";
}

void Application::handle(const KeyPressed& k) {
    std::cout << "key: " << k.code << "\n";
    if (k.code == ESCAPE) {
        app_window.close();
    }
}

void Application::handle(const WindowResize& r) {
    std::cout << "resize: " << r.width << "x" << r.height << "\n";
}

void Application::handle(const WindowClosed&){
	app_window.close();
	std::cout << "window closed" << "\n"; 
}
