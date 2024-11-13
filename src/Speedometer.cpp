#include "Speedometer.h"
#include <string>

const float MAX_SPEED = 200.0f;
const float ANGLE_RANGE = 270.0f;
const float ANGLE_OFFSET = 225.0f;
const sf::Vector2f CENTER_POSITION(310, 205);

Speedometer::Speedometer() : speed(0.0f) {}

void Speedometer::increaseSpeed(float delta) {
    if (speed < MAX_SPEED) {
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
    drawBackgroundCircles(window);

    // Speed text labels
    drawSpeedLabels(window, font);

    // Speed indicator
    drawSpeedIndicator(window);

    // Speed text
    drawSpeedText(window, font);
}

void Speedometer::drawBackgroundCircles(sf::RenderWindow &window) {
    sf::CircleShape outerCicle(100);
    outerCicle.setFillColor(sf::Color(50, 150, 50));
    outerCicle.setPosition(210, 110);

    sf::CircleShape innterCicrlce(90);
    innterCicrlce.setFillColor(sf::Color::Green);
    innterCicrlce.setPosition(220, 120);

    window.draw(outerCicle);
    window.draw(innterCicrlce);
}

void Speedometer::drawSpeedLabels(sf::RenderWindow &window, const sf::Font &font) {
    int maxSpeed = 200;
    int increment = 20;
    float radius = 80.0f; // Set radius for number positioning
    sf::Vector2f center(310, 205); // Center position of the speedometer

    for (int speedLabel = 0; speedLabel <= maxSpeed; speedLabel += increment) {
        // Calculate angle for each label
        float angle = (speedLabel / static_cast<float>(maxSpeed)) * 270.0f;
        float radians = (225 - angle) * (3.14159f / 180.0f); // Convert to radians for SFML

        // Calculate label position on the circle
        sf::Vector2f labelPos;
        labelPos.x = center.x + std::cos(radians) * radius;
        labelPos.y = center.y - std::sin(radians) * radius;

        // Create text for each speed label
        sf::Text label;
        label.setFont(font);
        label.setString(std::to_string(speedLabel));
        label.setCharacterSize(12);
        label.setFillColor(sf::Color::Black);
        label.setPosition(labelPos.x - label.getLocalBounds().width / 2, labelPos.y - label.getLocalBounds().height / 2);

        window.draw(label);
    }
}

void Speedometer::drawSpeedIndicator(sf::RenderWindow &window) {
    float angle = (speed / 200.0f) * 270.0f;
    sf::RectangleShape speedIndicator(sf::Vector2f(5, 80));
    speedIndicator.setFillColor(sf::Color::Red);
    speedIndicator.setOrigin(2, 80);
    speedIndicator.setPosition(310, 210);
    speedIndicator.setRotation(225 + angle);

    window.draw(speedIndicator);
}

void Speedometer::drawSpeedText(sf::RenderWindow &window, const sf::Font &font) {
    sf::Text speedText;
    speedText.setFont(font);
    speedText.setString("Speed: " + std::to_string(static_cast<int>(speed)) + " km/h");
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(220, 70);

    window.draw(speedText);
}