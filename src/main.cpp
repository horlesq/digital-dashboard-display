#include <SFML/Graphics.hpp>
#include "Dashboard.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Digital Dashboard Display");
    Dashboard dashboard;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dashboard.update(window);

        window.clear();
        dashboard.draw(window);
        window.display();
    }

    return 0;
}