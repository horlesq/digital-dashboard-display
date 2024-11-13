#include "Tachometer.h"
#include <string>

Tachometer::Tachometer() : rpm(0.0f) {}

void Tachometer::updateBasedOnSpeed(float speed) {
    if (speed >= 0) rpm = speed * 30; 
}

void Tachometer::update() {
}

float Tachometer::getRPM() const {
    return rpm;
}

void Tachometer::draw(sf::RenderWindow &window, const sf::Font &font) {
    // Background circle
    sf::CircleShape outerCircle(80);
    outerCircle.setFillColor(sf::Color(50, 150, 50));
    outerCircle.setPosition(430, 150);

    sf::CircleShape innerCircle(70); 
    innerCircle.setFillColor(sf::Color(50, 250, 50));
    innerCircle.setPosition(440, 160);
    
    window.draw(outerCircle);
    window.draw(innerCircle);

    // RPM indicator
    float angle = (rpm  / 6000.0f) * 180.0f;
    sf::RectangleShape rpmIndicator(sf::Vector2f(5, 60));
    rpmIndicator.setFillColor(sf::Color::Red);
    rpmIndicator.setOrigin(2, 60);
    rpmIndicator.setPosition(510, 230);
    rpmIndicator.setRotation(225 + angle);

    window.draw(rpmIndicator);

    // RPM text
    sf::Text rpmText;
    rpmText.setFont(font);
    rpmText.setString("RPM: " + std::to_string(static_cast<int>(rpm)));
    rpmText.setCharacterSize(24);
    rpmText.setFillColor(sf::Color::White);
    rpmText.setPosition(440, 100);

    window.draw(rpmText);
}
