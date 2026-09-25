#include "shape.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

RectShape::RectShape(const Vec2& size, const Vec2& pos, sf::Color color):
	size(size),color(color)
{
	set_position(pos);
}
RectShape::RectShape(const Vec2& size, sf::Color color):
	size(size),color(color){}
RectShape::RectShape(const Vec2& size):size(size){}

void RectShape::draw(sf::RenderTarget& target) const{
	sf::RectangleShape rect({size.x, size.y});
	rect.setPosition(transform.position.x, transform.position.y);
	rect.setRotation(transform.rotation);
	rect.setScale(transform.scale.x, transform.scale.y);
	rect.setOrigin(transform.origin.x, transform.origin.y);
	rect.setFillColor(color);
	target.draw(rect);
}
