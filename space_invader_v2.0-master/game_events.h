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
/**
 * @brief Constructs a game_events object.
 *
 * @param bullets Reference to the vector of bullets.
 * @param aliens Reference to the vector of aliens.
 * @param playerShip Reference to the player_ship object.
 * @param alien_bullets Reference to the vector of alien bullets.
 * @param powerUps2 Reference to the power_ups object.
 */
public:
    explicit game_events(std::vector<bullet> &bullets, std::vector<alien> &aliens , player_ship & , std::vector<bullet> &alien_bullets, power_ups &);

    /**
 * @brief Checks for collisions between bullets and aliens, as well as collision between the player ship and power-ups.
 */
    void checkCollision();

    /**
 * @brief Updates the positions of the bullets, aliens, and alien bullets.
 */
    void updateposition();

    /**
 * @brief Checks if the player is hit by alien bullets and handles the removal of bullets reaching the bottom of the screen.
 */
    void playerkill(player_ship & , std::vector<bullet> &alien_bullets );

    /**
 * @brief Handles the power-up functionality, including power-up effects and movement.
 *
 * @param window The window on which the power-up is moving.
 */
    void powerup(sf::RenderWindow & );
/**
 * @brief Resets the power-up clock to the specified state.
 *
 * @param state The state to reset the power-up clock to.
 */
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
