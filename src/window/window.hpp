#pragma once
#include <string>
#include <vector>

using size_t = std::size_t;
enum KeyActions {INPUT, OUTPUT, DELAY};
enum CommandType {MOUSE, KEY_ACTION, RESIZE_WIND};

namespace sf {
    class RenderWindow;
}

struct Command{
	CommandType type;
	virtual ~Command(void) = default;
};

struct MouseCommand: public Command{
	unsigned int x, y;
	MouseCommand(unsigned int m_x, unsigned int m_y):x(m_x),y(m_y){ type = MOUSE; }
};

struct KeyAction: public Command{
	unsigned int code;
	KeyActions action;
	KeyAction(unsigned int k_code, KeyActions k_action):code(k_code){ type = KEY_ACTION; action = k_action;}
};

struct WindowResize: public Command{
	int delta_x, delta_y;
	WindowResize(int dx, int dy):delta_x(dx),delta_y(dy){ type = RESIZE_WIND; }
};

struct Commands{
	std::vector<Command*> commands;
	
	~Commands(void){ clear(); }
	void clear(){
		for(Command* com : commands){ delete com; }
		commands.clear();
	}
	Commands() = default;
	Commands(const Commands&) = delete;
	Commands& operator=(const Commands&) = delete;
	
};

class Window{
	private:
		unsigned int width, height;
		std::string title;
		Commands current_commands{};
		sf::RenderWindow* wind;
	public:
		Window(std::string wind_title = "Application", unsigned int w_width = 100, unsigned int w_height = 100);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		//void change_window(struct Elements& elements_to_show);
		void create();
		void close();
		bool isOpen() const;
		
		sf::RenderWindow* get_native_window() const;
		const Commands& get_commands(void) const;
		void clear_commands(void);
};
