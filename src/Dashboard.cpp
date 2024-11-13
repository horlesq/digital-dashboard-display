#include "Dashboard.h"
#include <iostream>

Dashboard::Dashboard() : speedometer(), tachometer() {
    if (!font.loadFromFile("C:/Programming/GIT/digital-dashboard-display/assets/Montserrat-Regular.otf")) {
        std::cerr << "Failed to load font." << std::endl;
    }

    initPedals();
}

void Dashboard::initPedals() {
    // Acceleration pedal
    accelPedal.setSize(sf::Vector2f(100, 50));
    accelPedal.setFillColor(sf::Color(98, 98, 98));
    accelPedal.setOutlineThickness(3);
    accelPedal.setOutlineColor(sf::Color::Green);
    accelPedal.setPosition(300, 400);

    accelText.setFont(font);
    accelText.setString("Accelerate");
    accelText.setCharacterSize(16);
    accelText.setFillColor(sf::Color::Green);
    accelText.setPosition(307, 400);
    
    // Brake pedal
    brakePedal.setSize(sf::Vector2f(100, 50));
    brakePedal.setFillColor(sf::Color(98, 98, 98));
    brakePedal.setOutlineThickness(3);
    brakePedal.setOutlineColor(sf::Color::Red);
    brakePedal.setPosition(435, 400);

    brakeText.setFont(font);
    brakeText.setString("Brake");
    brakeText.setCharacterSize(16);
    brakeText.setFillColor(sf::Color::Red);
    brakeText.setPosition(458, 400);

}

void Dashboard::update(sf::RenderWindow &window) {
    handleArrowKeysInput();
    handlePedalInput(window);

    speedometer.update();
    tachometer.updateBasedOnSpeed(speedometer.getSpeed());
}

void Dashboard::handleArrowKeysInput() {
    // Increase or decrease speed with arrow keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        speedometer.increaseSpeed(0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speedometer.decreaseSpeed(0.1f);
    }
}

void Dashboard::handlePedalInput(sf::RenderWindow &window) {
    // Press pedal control
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (accelPedal.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            speedometer.increaseSpeed(0.1f);
        }

        if (brakePedal.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            speedometer.decreaseSpeed(0.2f);
        }
    }
}

void Dashboard::draw(sf::RenderWindow &window) {
    drawBackground(window);

    speedometer.draw(window, font);
    tachometer.draw(window, font);

    window.draw(accelPedal);
    window.draw(accelText);
    window.draw(brakePedal);
    window.draw(brakeText);
}

void Dashboard::drawBackground(sf::RenderWindow &window) {
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
}