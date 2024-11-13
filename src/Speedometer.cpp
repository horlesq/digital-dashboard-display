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
    sf::Text speedText;
    speedText.setFont(font);
    speedText.setString("Speed: " + std::to_string(static_cast<int>(speed)) + " km/h");
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(50, 50);

    window.draw(speedText);
}
