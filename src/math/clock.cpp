#include "clock.hpp"
#include <SFML/System/Clock.hpp>

Clock::Clock():impl(new sf::Clock()){}
Clock::~Clock(){ delete impl; }

float Clock::restart(){
	return impl->restart().asSeconds();
}

float Clock::elapsed() const{
	return impl->getElapsedTime().asSeconds();
}
