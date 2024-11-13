#include "Speedometer.h"
#include <string>

Speedometer::Speedometer() : speed(0.0f) {}

void Speedometer::increaseSpeed(float delta) {
    if (speed < 200) {
        speed += delta;
    }
}

void Speedometer::decreaseSpeed(float delta) { 
    if (speed > 0) {
        speed -= delta;
    }
}

void Speedometer::update() {

}

float Speedometer::getSpeed() const {
    return speed;
}

void Speedometer::draw(sf::RenderWindow &window, const sf::Font &font) {

    // Background circle
    sf::CircleShape outerCicle(100);
    outerCicle.setFillColor(sf::Color(50, 150, 50));
    outerCicle.setPosition(210, 110);

    sf::CircleShape innterCicrlce(90);
    innterCicrlce.setFillColor(sf::Color(50, 250, 50));
    innterCicrlce.setPosition(220, 120);

    window.draw(outerCicle);
    window.draw(innterCicrlce);

    // speed indicator
    float angle = (speed / 200.0f) * 270.0f;
    sf::RectangleShape speedIndicator(sf::Vector2f(5, 80));
    speedIndicator.setFillColor(sf::Color::Red);
    speedIndicator.setOrigin(2, 80);
    speedIndicator.setPosition(310, 210);
    speedIndicator.setRotation(225 + angle);

    window.draw(speedIndicator);

    // Speed text
    sf::Text speedText;
    speedText.setFont(font);
    speedText.setString("Speed: " + std::to_string(static_cast<int>(speed)) + " km/h");
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(220, 70);

    window.draw(speedText);
}
