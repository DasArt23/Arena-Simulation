#pragma once
#include <math/vec2.hpp>
#include <math/transform.hpp>
#include <SFML/Graphics/Color.hpp>

namespace sf {
	class RenderTarget;
}

class Shape{
protected:
	Transform transform;
public:
	virtual ~Shape() = default;
	virtual void draw(sf::RenderTarget& target) const = 0;

	void set_position(const Vec2& p){ transform.position = p; }
	void set_scale(const Vec2& s)	{ transform.scale = s; }
	void set_rotation(float r)		{ transform.rotation = r; }
	void set_origin(const Vec2& o)	{ transform.origin = o; }
	
	void move(const Vec2& delta)	{ transform.position += delta; }
	void rotate(float delta)		{ transform.rotation += delta; }

	Transform& get_transform() 	{ return transform; }
	const Transform& get_transform() const { return transform; }
};

class RectShape : public Shape{
private:
	Vec2 size;
	sf::Color color = sf::Color::White;
public:
	RectShape(const Vec2& size, const Vec2& pos, sf::Color clr = sf::Color::White);
	RectShape(const Vec2& size, sf::Color clr);
	RectShape(const Vec2& size);
	void draw(sf::RenderTarget& target) const override;

	void set_color(sf::Color clr) 	{ color = clr; }
	void set_width(float w) 	{ size.x = w; }
	void set_height(float h)	{ size.y = h; }
	
	Vec2 get_size() const		{ return size; }
	float get_width() const 	{ return size.x; }
	float get_height() const	{ return size.y; }
	float get_area() const		{ return size.x * size.y; }
	sf::Color get_color() const { return color; }
};


