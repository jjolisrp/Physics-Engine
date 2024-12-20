#include <SFML/Graphics.hpp>

int main() {
    // Crear una ventana con tamaño 800x600 y título "Prueba SFML"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba SFML");

    // Bucle principal para mantener la ventana abierta
    while (window.isOpen()) {
        // Crear un evento para gestionar las acciones del usuario
        sf::Event event;
        while (window.pollEvent(event)) {
            // Si el evento es de tipo "cerrar la ventana", salir del bucle
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana con el color negro
        window.clear(sf::Color::Black);

        // Mostrar lo que hemos dibujado (en este caso nada)
        window.display();
    }

    return 0;
}
