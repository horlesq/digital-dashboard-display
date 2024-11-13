#include "Tachometer.h"
#include <string>

Tachometer::Tachometer() : rpm(0.0f) {}

void Tachometer::updateBasedOnSpeed(float speed) {
    if (speed > 0) rpm = speed * 30; 
}

void Tachometer::update() {
}

float Tachometer::getRPM() const {
    return rpm;
}

void Tachometer::draw(sf::RenderWindow &window, const sf::Font &font) {
    sf::Text rpmText;
    rpmText.setFont(font);
    rpmText.setString("RPM: " + std::to_string(static_cast<int>(rpm)));
    rpmText.setCharacterSize(24);
    rpmText.setFillColor(sf::Color::White);
    rpmText.setPosition(50, 100);

    window.draw(rpmText);
}
