#include "shape.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

RectShape::RectShape(const Vec2& size, const Vec2& pos, sf::Color color):
	ColoredShape(color),size(size)
{
	set_position(pos);
}
RectShape::RectShape(const Vec2& size, sf::Color color):
	ColoredShape(color),size(size){}

void RectShape::draw(sf::RenderTarget& target) const{
	sf::RectangleShape rect({size.x, size.y});
	rect.setPosition(transform.position.x, transform.position.y);
	rect.setRotation(transform.rotation);
	rect.setScale(transform.scale.x, transform.scale.y);
	rect.setOrigin(transform.origin.x, transform.origin.y);
	rect.setFillColor(color);
	target.draw(rect);
}

CircleShape::CircleShape(float radius, const Vec2& pos, sf::Color color):
	ColoredShape(color),radius(radius)
{
	set_position(pos);
}
CircleShape::CircleShape(float radius, sf::Color color):
	ColoredShape(color),radius(radius){}

void CircleShape::draw(sf::RenderTarget& target) const{
	sf::CircleShape circle(radius);
	circle.setPosition(transform.position.x, transform.position.y);
	circle.setRotation(transform.rotation);
	circle.setScale(transform.scale.x, transform.scale.y);
	circle.setOrigin(transform.origin.x, transform.origin.y);
	target.draw(circle);
}
