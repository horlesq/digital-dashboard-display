#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <SFML/Graphics.hpp>
#include "Speedometer.h"
#include "Tachometer.h"

class Dashboard {
    public:
        Dashboard();
        void update(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);

    private:
        Speedometer speedometer;
        Tachometer tachometer;
        sf::RectangleShape accelPedal;
        sf::RectangleShape brakePedal;
        sf::Font font;

};

#endif