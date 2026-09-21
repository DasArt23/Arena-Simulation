#pragma once
#include <vector>

namespace sf {
    class RenderWindow;
}
struct Shape{
	int id;
	virtual ~Shape() = default;
	Shape(int m_id):id(m_id){}
};

class Render{
private:
	sf::RenderWindow* m_window;
public:
	Render(sf::RenderWindow* wind);
	void render(const std::vector<Shape*> shapes);
};
