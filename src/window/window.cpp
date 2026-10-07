#include "window.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <cassert>

Window::Window(std::string wind_title, uint w_width, uint w_height):
	title(wind_title),width(w_width),
	height(w_height),wind(nullptr){}

Window::~Window(void){
	close();
}

void Window::clear_commands(){
	current_commands.clear();
}

void Window::set_default_size() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    width  = static_cast<uint>(desktop.width * 0.75f);
    height = static_cast<uint>(desktop.height * 0.6f);
}

void Window::create(){
	if(wind) close();
	wind = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Window::close(){
	current_commands.clear();
	if(wind){
		if(wind->isOpen()) wind->close();
		delete wind;
		wind = nullptr;
	}
}

const Commands& Window::get_commands() const{
	return current_commands;
}

bool Window::isOpen() const{
	return wind && wind->isOpen();
}

sf::RenderTarget& Window::get_target() const {
	assert(wind);
    return *wind;
}

void Window::display(){
	if(wind) wind->display();
}

void Window::poll_events(){
	if(!wind) return;
	current_commands.clear();

	sf::Event event;
	while(wind->pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				current_commands.push_back(WindowClosed{});
				return;
			case sf::Event::MouseMoved:
				current_commands.push_back(MouseMove{
					event.mouseMove.x,
					event.mouseMove.y
				});
				break;
			case sf::Event::KeyPressed:
				current_commands.push_back(KeyPressed{
					static_cast<KeyCode>(event.key.code)
				});
				break;
			case sf::Event::Resized:
				width = event.size.width;
				height = event.size.height;
				current_commands.push_back(WindowResize{
					static_cast<int>(width), 
					static_cast<int>(height)
				});
				break;
			default:
				break;
		}
	}
}
