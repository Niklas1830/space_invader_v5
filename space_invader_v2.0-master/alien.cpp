//
// Created by Nikla on 10/20/2023.
//

#include <iostream>
#include "alien.h"


alien::alien(float x, float y, sf::Texture &texture, std::vector<bullet> &aliensbullets,
             sf::Texture &alien_bullet_texture) : alien_bullets(aliensbullets) {


    alien_sprite.setTexture(texture);
    alien_sprite.setPosition(x, y);
    alien_sprite.setScale(5, 5);
    alive = true;



    alien_bullet.setTexture(alien_bullet_texture);
    alien_bullet.setScale(3, 3);


}

sf::Sprite alien::getSprite() {
    return alien_sprite;
}

void alien::draw(sf::RenderWindow &window) {


    window.draw(alien_sprite);
    for (auto &e: alien_bullets) {


        alien_bullet.setPosition(e.posX(), e.posY());
        window.draw(alien_bullet);
    }


}

void alien::update(std::vector<alien> &aliens) {

    alien_sprite.move(move_direction, 0);


    if (alien_sprite.getPosition().x >= 750) {
        for (auto &e: aliens) {
            e.alien_sprite.move(0, 5);
            e.move_direction = -e.move_direction;
        }
    }


    if (alien_sprite.getPosition().x <= 0) {
        for (auto &e: aliens) {
            e.move_direction = -1 * e.move_direction;
            e.alien_sprite.move(0, 5);
        }
    }
    clock_move.restart();


    if (shoot_clock.getElapsedTime().asSeconds() > shoot_frequency) {
        for (auto &e: aliens) {


            if (rand() % 50 == 1) {



                alien_bullets.push_back(bullet(e.alien_getX() + 12, e.alien_getY(), -3 +rand() % 3));
            }
        }
        shoot_clock.restart();
    }



}


double alien::alien_getX() {
    return alien_sprite.getPosition().x;
}

double alien::alien_getY() {
    return alien_sprite.getPosition().y;
}

void alien::kill() {

    alive = false;

}


bool alien::isalive() {
    return alive;
}

alien &alien::operator=(const alien &rhs) {


    this->shoot_clock = rhs.shoot_clock;
    this->clock_move = rhs.clock_move;
    this->alien_sprite = rhs.alien_sprite;
    this->alien_bullets = rhs.alien_bullets;
    this->movetime = rhs.movetime;
    this->shoot_frequency = rhs.shoot_frequency;
    this->move_direction = rhs.move_direction;
    this->alive = rhs.alive;
    this->alien_bullets = rhs.alien_bullets;

    return *this;


}


