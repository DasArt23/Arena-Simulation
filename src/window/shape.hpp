#pragma once
#include <numbers>
#include <math/vec2.hpp>
#include <math/transform.hpp>
#include <SFML/Graphics/Color.hpp>

namespace sf {
	class RenderTarget;
}

class Shape{
protected:
	Transform transform;
	virtual Vec2 local_center() const = 0;
public:
	virtual ~Shape() = default;
	virtual void draw(sf::RenderTarget& target) const = 0;
	
	void set_origin_center()		{ transform.origin = local_center(); } 
	void set_position(const Vec2& p){ transform.position = p; }
	void set_scale(const Vec2& s)	{ transform.scale = s; }
	void set_rotation(float r)		{ transform.rotation = r; }
	void set_origin(const Vec2& o)	{ transform.origin = o; }
	
	void move(const Vec2& delta)	{ transform.position += delta; }
	void rotate(float delta)		{ transform.rotation += delta; }

	Transform& get_transform() 	{ return transform; }
	const Transform& get_transform() const { return transform; }
};

class ColoredShape : public Shape{
protected:
	sf::Color color;
public:
	explicit ColoredShape(sf::Color color = sf::Color::White):color(color){}
	void set_color(sf::Color clr) 	{ color = clr; }
	sf::Color get_color() const { return color; }
};

class RectShape : public ColoredShape{
	Vec2 size;
protected:
	Vec2 local_center() const override { return Vec2{size.x / 2, size.y / 2}; }
public:
	RectShape(const Vec2& size, const Vec2& pos, sf::Color color = sf::Color::White);
	RectShape(const Vec2& size, sf::Color color = sf::Color::White);
	void draw(sf::RenderTarget& target) const override;

	void set_width(float w) 	{ size.x = w; }
	void set_height(float h)	{ size.y = h; }
	
	Vec2 get_size() const		{ return size; }
	float get_width() const 	{ return size.x; }
	float get_height() const	{ return size.y; }
	float get_area() const		{ return size.x * size.y; }
};

class CircleShape : public ColoredShape{
	float radius;
protected:
	Vec2 local_center() const override { return Vec2{radius, radius}; }
public:
	CircleShape(float radius, const Vec2& pos, sf::Color clr = sf::Color::White);
	CircleShape(float radius, sf::Color clr = sf::Color::White);
	void draw(sf::RenderTarget& target) const override;

	void set_radius(float rads)		{ radius = rads; }
	
	float get_radius() const 	{ return radius;}
	float get_area() const		{ return radius*radius*std::numbers::pi_v<float>; }
};
