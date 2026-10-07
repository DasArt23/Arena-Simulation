#include "app.hpp"
#include "window/window.hpp"
#include "window/shape.hpp"
#include "math/clock.hpp"
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
	std::vector<Shape*> shapes{};
	RectShape* rect = new RectShape({100, 50}, {200, 200}, sf::Color::Red);
	shapes.push_back(rect);
	shapes.push_back(new CircleShape(50, {400, 300}, sf::Color::Green));
	for (auto* s : shapes) s->set_origin_center();
	rect->set_rotation(45.0f);
	shapes[1]->set_scale({2, 1});
	shapes[1]->set_rotation(90.0f);
	Clock clock = Clock();

	Vec2 velocity(100.0f, 0.0f);
	while(app_window.isOpen()){
		float dt = clock.restart();
		update(dt);
		if(!app_window.isOpen()) break;
		rect->move(velocity * dt);
		app_render->render(shapes);
		app_window.display();
	}
	for(Shape* shape : shapes) delete shape;
}

void Application::update(float dt){
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
