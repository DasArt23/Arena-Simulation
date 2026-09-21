#include "app/app.hpp" 
#include "window/window.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main(){
    // 1. Инициализируем и создаем окно
    Window app{};
    app.create();
    
    // Получаем доступ к нативному окну SFML для обработки событий в main
    // (Позже мы перенесем это внутрь метода app.update())
    sf::RenderWindow* native_wind = app.get_native_window();

    // 2. Правильный цикл вместо while(true);
    while (app.isOpen()) {
        
        sf::Event event;
        // Опрашиваем очередь событий ОС
        while (native_wind->pollEvent(event)) {
            // Если нажали "Крестик" — вызываем ваш безопасный метод close()
            if (event.type == sf::Event::Closed) {
                app.close(); 
            }
        }
        
        // Внутренности SFML требуют небольшой паузы, чтобы не перегружать CPU
        // В будущем здесь будет очистка экрана и отрисовка кадра
    }

    return 0;
}

