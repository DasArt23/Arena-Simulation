#include "render.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Render::Render(sf::RenderTarget& target, sf::Color color)
	:m_target(target),m_color(color){}

void Render::set_default_color(sf::Color color){
	m_color = color;
}

