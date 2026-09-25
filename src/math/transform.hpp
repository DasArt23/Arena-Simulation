#pragma once
#include "vec2.hpp"

struct Transform{
	Vec2 position{};
	float rotation{};
	Vec2 scale{1.0f, 1.0f};
	Vec2 origin{};
};
