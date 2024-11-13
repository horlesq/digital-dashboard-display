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

    // RPM text labels
    int maxRPM = 6;
    int rpmIncrement = 1;
    float radius = 64.0f; // Radius for number positioning
    sf::Vector2f center(510, 225); // Center position of the tachometer

    for (int rpmLabel = 0; rpmLabel <= maxRPM; rpmLabel += rpmIncrement) {
        // Calculate angle for each label
        float angle = (rpmLabel / static_cast<float>(maxRPM)) * 180.0f;
        float radians = (225 - angle) * (3.14159f / 180.0f); // Convert to radians for SFML

        // Calculate label position on the circle
        sf::Vector2f labelPos;
        labelPos.x = center.x + std::cos(radians) * radius;
        labelPos.y = center.y - std::sin(radians) * radius;

        // Create text for each RPM label
        sf::Text label;
        label.setFont(font);
        label.setString(std::to_string(rpmLabel));
        label.setCharacterSize(10);
        label.setFillColor(sf::Color::Black);
        label.setPosition(labelPos.x - label.getLocalBounds().width / 2, labelPos.y - label.getLocalBounds().height / 2);

        window.draw(label);
    }

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
