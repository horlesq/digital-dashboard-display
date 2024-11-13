#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <SFML/Graphics.hpp>
#include "Speedometer.h"
#include "Tachometer.h"

class Dashboard {
    public:
        Dashboard();
        void update();
        void draw(sf::RenderWindow &window);

    private:
        Speedometer speedometer;
        Tachometer tachometer;
        sf::Font font;

};

#endif