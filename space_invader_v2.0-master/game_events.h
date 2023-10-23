//
// Created by Nikla on 2023-10-20.
//
#pragma once
#ifndef SPACE_INVADER_V2_GAME_EVENTS_H
#define SPACE_INVADER_V2_GAME_EVENTS_H

#include <SFML/GpuPreference.hpp>
#include "alien.h"
#include "bullet.h"
#include "power_ups.h"


//declaration foward , got issue with "circular dependency"
class player_ship;

class game_events {

public:
    explicit game_events(std::vector<bullet> &bullets, std::vector<alien> &aliens , player_ship & , std::vector<bullet> &alien_bullets, power_ups &);

    void checkCollision();

    void updateposition();

    void playerkill(player_ship & , std::vector<bullet> &alien_bullets );

    void powerup(sf::RenderWindow & );

    void reset_power_up_clock(bool);

private:

    std::vector<bullet> &bullets;
    std::vector<bullet> &alien_bullets;
    std::vector<alien> &aliens;
    player_ship &playerShip;
    power_ups &powerUps_ref;
    bool clock_reset;

    sf::Clock power_up_clock;
    int power_up_timer = 3; // as seconds



};


#endif //SPACE_INVADER_V2_GAME_EVENTS_H
