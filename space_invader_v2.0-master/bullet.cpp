//
// Created by Nikla on 10/20/2023.
//

#include "bullet.h"

bullet::bullet(double x, double y , double speed ) : x(x), y(y) , bulletspeed(speed) {




}

double bullet::posX() {
    return x;
}

double bullet::posY() {
    return y;
}

double bullet::getBulletspeed() {
    return bulletspeed;
}

void bullet::updatePosition() {

    y += -bulletspeed;

}



bool bullet::isOnScreen(sf::RenderWindow &window) {


    if (posX() < 0 || posX() > window.getSize().x || posY() < 0 || posY() > window.getSize().y) {
        return false;
    }

    return true;

}


void bullet::setBulletSpeed(double speed) {

    bulletspeed = speed;

}



