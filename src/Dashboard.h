#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <SFML/Graphics.hpp>

class Dashboard {
    public:
        Dashboard();
        void update();
        void draw(sf::RenderWindow &window);

    private:
        float speed;
        float rpm;
};

#endif