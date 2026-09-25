#pragma once
#include "shape.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sf {
    class RenderTarget;
}

template <typename Container>
concept ShapePointerContainer = requires(Container c){
	{*c.begin()} -> std::convertible_to<const Shape*>;
};

class Render{
private:
	sf::RenderTarget& m_target;
	sf::Color m_color;
public:
	explicit Render(sf::RenderTarget& target, sf::Color color = sf::Color::Black);
	
	void set_default_color(sf::Color color);

	template <ShapePointerContainer Container>
	void render(const Container& shapes) const {
	    m_target.clear(sf::Color::Black);
	    for (const auto& shape : shapes) if(shape) shape->draw(m_target);
	}
};
