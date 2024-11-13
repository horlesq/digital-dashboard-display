#include "Dashboard.h"
#include <iostream>

Dashboard::Dashboard() : speedometer(), tachometer() {
    if (!font.loadFromFile("C:/Programming/GIT/digital-dashboard-display/assets/Montserrat-Regular.otf")) {
        std::cerr << "Failed to load font." << std::endl;
    }

    // Init pedals
    accelPedal.setSize(sf::Vector2f(100, 50));
    accelPedal.setFillColor(sf::Color(98, 98, 98));
    accelPedal.setOutlineThickness(3);
    accelPedal.setOutlineColor(sf::Color::Green);
    accelPedal.setPosition(300, 400);
    
    brakePedal.setSize(sf::Vector2f(100, 50));
    brakePedal.setFillColor(sf::Color(98, 98, 98));
    brakePedal.setOutlineThickness(3);
    brakePedal.setOutlineColor(sf::Color::Red);
    brakePedal.setPosition(435, 400);
}

void Dashboard::update(sf::RenderWindow &window) {
    // Arrow keys control
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        speedometer.increaseSpeed(0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speedometer.decreaseSpeed(0.1f);
    }
    speedometer.update();
    tachometer.updateBasedOnSpeed(speedometer.getSpeed());

    // Press pedal control
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Check if mouse is over the acceleration pedal
        if (accelPedal.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            speedometer.increaseSpeed(0.1f);
        }

        // Check if mouse is over the brake pedal
        if (brakePedal.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            speedometer.decreaseSpeed(0.2f);
        }
    }
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

    window.draw(accelPedal);
    window.draw(brakePedal);
}