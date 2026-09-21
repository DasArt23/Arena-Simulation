#include "window.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

Window::Window(std::string wind_title, unsigned int w_width, unsigned int w_height):
	title(wind_title),width(w_width),
	height(w_height),wind(nullptr){}

Window::~Window(void){
	clear_commands();
	close();
}

void Window::clear_commands(void){
	current_commands.clear();
}

void Window::create(void){
	if(wind) close();
	wind = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Window::close(void){
	current_commands.clear();
	if(wind){
		if(wind && wind->isOpen()) wind->close();
		delete wind;
		wind = nullptr;
	}
}

const Commands& Window::get_commands(void) const{
	const Commands& commands = current_commands;
	return commands;
}

bool Window::isOpen(void) const{
	return wind && wind->isOpen();
}

sf::RenderWindow* Window::get_native_window() const {
    return wind;
}
