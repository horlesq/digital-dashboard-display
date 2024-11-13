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
        sf::Text accelText;
        sf::RectangleShape brakePedal;
        sf::Text brakeText;
        sf::Font font;
        
        void initPedals();
        void drawBackground(sf::RenderWindow &window);
        void handleArrowKeysInput();
        void handlePedalInput(sf::RenderWindow &window);

};

#endif