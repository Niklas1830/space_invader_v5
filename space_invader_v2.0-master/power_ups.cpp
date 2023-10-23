//
// Created by Nikla on 2023-10-22.
//

#include <iostream>
#include "power_ups.h"

power_ups::power_ups(double x , double y , double speed ) : bullet(x,y,speed)  {


    power_up_texture.loadFromFile("Texture/Power_up.png");
    power_up_sprite.setTexture(power_up_texture);
    power_up_sprite.setScale(3,3);
    power_up_sprite.setPosition(x,y);
    setBulletSpeed(speed);
    player_hit = false;
    alive = true;
    used = false;

}

void power_ups::move(sf::RenderWindow & window) {


    power_up_sprite.setPosition(x,y);
    window.draw(power_up_sprite);
    power_up_sprite.move(0,-bulletspeed);
    updatePosition();




}

sf::Sprite power_ups::getSprite() {
    return power_up_sprite;
}



bool power_ups::is_alive() {

    return alive;
}

bool power_ups::is_used() {
    return used;
}

void power_ups::set_use_state(bool state) {

    used = state;

}

void power_ups::set_alive(bool state) {
    alive = state;

}

void power_ups::set_player_hit(bool state) {

    player_hit = state;

}

bool power_ups::is_player_hit() {
    return player_hit;
}

void power_ups::reset(sf::RenderWindow & window) {

    x = window.getSize().x / 2;
    y = window.getSize().y - window.getSize().y;
    player_hit = false;
    alive = true;
    used = false;

}
