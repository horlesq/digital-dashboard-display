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
    
    void drawBackgroundCircles(sf::RenderWindow &window);
    void drawRPMLabels(sf::RenderWindow &window, const sf::Font &font);
    void drawRPMIndicator(sf::RenderWindow &window);
    void drawRPMText(sf::RenderWindow &window, const sf::Font &font);
};

#endif
