#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <SFML/Graphics.hpp>

class Speedometer {
public:
    Speedometer();
    void increaseSpeed(float delta);
    void decreaseSpeed(float delta);
    void update();

    float getSpeed() const;

    void draw(sf::RenderWindow &window, const sf::Font &font);

private:
    float speed;
};

#endif