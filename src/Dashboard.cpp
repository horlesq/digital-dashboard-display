#include "Dashboard.h"
#include <iostream>

Dashboard::Dashboard() : speedometer(), tachometer() {
    if (!font.loadFromFile("C:/Programming/GIT/digital-dashboard-display/assets/Montserrat-Regular.otf")) {
        std::cerr << "Failed to load font." << std::endl;
    }
}

void Dashboard::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        speedometer.increaseSpeed(0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speedometer.decreaseSpeed(0.1f);
    }
    speedometer.update();
    tachometer.updateBasedOnSpeed(speedometer.getSpeed());
}


void Dashboard::draw(sf::RenderWindow &window) {
    sf::VertexArray gradient(sf::TrianglesFan, 4);
    gradient[0].position = sf::Vector2f(0, 0);
    gradient[1].position = sf::Vector2f(window.getSize().x, 0);
    gradient[2].position = sf::Vector2f(window.getSize().x, window.getSize().y);
    gradient[3].position = sf::Vector2f(0, window.getSize().y);
    gradient[0].color = sf::Color(50, 50, 50);
    gradient[1].color = sf::Color(0, 0, 0);
    gradient[2].color = sf::Color(0, 0, 0);
    gradient[3].color = sf::Color(50, 50, 50);
    
    window.draw(gradient);

    speedometer.draw(window, font);
    tachometer.draw(window, font);
}