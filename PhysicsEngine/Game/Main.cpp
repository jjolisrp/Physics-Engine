#include <SFML/Graphics.hpp>
#include "Vector2.hpp"
#include "RigidBody.hpp"

int main() {
    // Crear una ventana con tama�o 800x600 y t�tulo "Prueba SFML"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba SFML");

    // Bucle principal para mantener la ventana abierta
    while (window.isOpen()) {
        // Crear un evento para gestionar las acciones del usuario
        sf::Event event;
        while (window.pollEvent(event)) {
            // Si el evento es de tipo "cerrar la ventana", salir del bucle
            if (event.type == sf::Event::Closed)
                window.close();

            Vector2 vector;

            vector.x = 50;
            vector.y = 50;

            printf("length %f", vector.GetLength());
        }

        // Limpiar la ventana con el color negro
        window.clear(sf::Color::Black);

        // Mostrar lo que hemos dibujado (en este caso nada)
        window.display();
    }

    return 0;
}
