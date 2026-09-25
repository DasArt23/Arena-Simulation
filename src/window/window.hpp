#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <vector>
#include <variant>

using uint = unsigned int;
enum KeyCode{
	ESCAPE = sf::Keyboard::Escape
};

namespace sf {
    class RenderWindow;
    class RenderTarget;
}

struct MouseMove { int x, y; };
struct KeyPressed { KeyCode code; };
struct WindowResize { int width, height; };
struct WindowClosed {};

using Command = std::variant<MouseMove, KeyPressed, WindowResize, WindowClosed>;
using Commands = std::vector<Command>;

class Window {
private:
    uint width, height;
    std::string title;
    Commands current_commands;
    sf::RenderWindow* wind;
public:
    Window(std::string title = "Application", uint w = 100, uint h = 100);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void create();
    void close();
    bool isOpen() const;
    void set_default_size();

    void poll_events();
    void display();          

    sf::RenderTarget& get_target() const;
    const Commands& get_commands() const;
    void clear_commands();
};
