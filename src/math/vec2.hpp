#pragma once
#include <cmath>
#include <iostream>

struct Vec2{
	float x{}, y{};

	Vec2() = default;
	Vec2(float x, float y):x(x),y(y){}
	// Arithmetic
	Vec2 operator+(const Vec2& o) const{return {x + o.x, y + o.y};}
	Vec2 operator-(const Vec2& o) const{return {x - o.x, y - o.y};}
	Vec2 operator*(float s) const{return {x * s, y * s};}
	Vec2 operator/(float s) const{return {x / s, y / s};}

	Vec2& operator*=(float s){x *= s; y *= s; return *this;}
	Vec2& operator/=(float s){x /= s; y /= s; return *this;}
	Vec2& operator+=(const Vec2& o){x += o.x; y += o.y; return *this;}
	Vec2& operator-=(const Vec2& o){x -= o.x; y -= o.y; return *this;}

	Vec2 operator-() const{return {-x, -y};}
	
	// Bool operations
	bool operator==(const Vec2& o) const{return (x == o.x) && (y == o.y);}
	bool operator!=(const Vec2& o) const{return (x != o.x) || (y != o.y);}

};

inline Vec2 operator*(float s, const Vec2& v){return v * s;}
inline float length(const Vec2& v){return std::sqrt(v.x*v.x + v.y*v.y);}
inline Vec2 normalized(const Vec2& v){
	float len = length(v);
	if(len == 0.0f) return {0.0f, 0.0f};
	return v / len;
}
inline std::ostream& operator<<(std::ostream& out, const Vec2& v){
	return out << "(" << v.x << ", " << v.y << ")";
}

