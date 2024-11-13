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
    speedometer.draw(window, font);
    tachometer.draw(window, font);
}