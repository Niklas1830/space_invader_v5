//
// Created by Nikla on 10/20/2023.
//

#ifndef SPACE_INVADER_V2_BULLET_H
#define SPACE_INVADER_V2_BULLET_H

#include <SFML/Graphics.hpp>

class bullet {

public:

    bullet(double ,double ,double );
    void updatePosition();
    double getBulletspeed();
    double posX();
    double posY();
    void setBulletAlive(bool bulletAlive);
    bool isOnScreen(sf::RenderWindow &);
    void setBulletSpeed(double );


protected:
    double x;
    double y;
    double bulletspeed;

};


#endif //SPACE_INVADER_V2_BULLET_H
