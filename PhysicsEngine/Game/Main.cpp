//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Mi primer ventana SFML");
//    sf::CircleShape circle(50.0f);
//    circle.setFillColor(sf::Color::Green);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(circle);
//        window.display();
//    }
//
//    return 0;
//}