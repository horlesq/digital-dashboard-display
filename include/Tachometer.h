#ifndef TACHOMETER_H
#define TACHOMETER_H

#include <SFML/Graphics.hpp>

class Tachometer {
public:
    Tachometer();
    void updateBasedOnSpeed(float speed);
    void update();

    float getRPM() const;

    void draw(sf::RenderWindow &window, const sf::Font &font);

private:
    float rpm;
};

#endif
