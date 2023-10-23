//
// Created by Nikla on 2023-10-20.
//

#include <iostream>
#include "game_events.h"
#include "player_ship.h"


game_events::game_events(std::vector<bullet> &bullets, std::vector<alien> &aliens, player_ship &playerShip,
                         std::vector<bullet> &alien_bullets, power_ups &powerUps2)
        : bullets(bullets), aliens(aliens), playerShip(playerShip), alien_bullets(alien_bullets),
          powerUps_ref(powerUps2) {


    clock_reset = true;
}


void game_events::updateposition() {

    for (auto &e: bullets) {

        e.updatePosition();

    }

    for (auto &e: aliens) {

        e.update(aliens);
    }

    for (auto &e: alien_bullets) {

        e.updatePosition();
    }


}

void game_events::checkCollision() {
    for (auto it = aliens.begin(); it != aliens.end();) {
        for (auto b = bullets.begin(); b != bullets.end();) {
            if (b->posX() - it->alien_getX() < 50 && b->posX() - it->alien_getX() > -20 &&
                b->posY() - it->alien_getY() < 50 && b->posY() - it->alien_getY() > -20) {
                it->kill();
                b = bullets.erase(b);
            } else if (b->posY() < 0) {
                b = bullets.erase(b);
            } else {
                ++b;
            }

        }
        if (!it->isalive()) {
            it = aliens.erase(it);
        } else {
            ++it;
        }
    }

    if (playerShip.getPosX() - powerUps_ref.posX() < 40 && playerShip.getPosX() - powerUps_ref.posX() >-30
    && playerShip.getPoxY() - powerUps_ref.posY() < 40 && playerShip.getPoxY() - powerUps_ref.posY() >-30 ){





        powerUps_ref.set_alive(false);
        powerUps_ref.set_player_hit(true);
        if (clock_reset)
        {

            power_up_clock.restart();
            clock_reset = false;
        }


    }

}

void game_events::playerkill(player_ship &playerShip1, std::vector<bullet> &alienbullets) {


    for (auto &e: alienbullets) {


        if (playerShip1.getPosX() - e.posX() < 10 && playerShip1.getPosX() - e.posX() > -10 &&
            playerShip1.getPoxY() - e.posY() < 20 && playerShip1.getPoxY() - e.posY() > -10) {

            playerShip1.player_kill(false);

        }
    }


    if (!alienbullets.empty()) {
        for (auto it = alienbullets.begin(); it != alienbullets.end();) {
            if (it->posY() > 600) {
                it = alienbullets.erase(it); // Remove the bullet
            } else {
                ++it;
            }
        }
    }

}


void game_events::powerup(sf::RenderWindow &window) {




    if (powerUps_ref.is_player_hit() && !powerUps_ref.is_used())
    {
        if (power_up_clock.getElapsedTime().asSeconds() < power_up_timer)
        {

            playerShip.set_Shoot_Speed(0.05);

        }
        if (power_up_clock.getElapsedTime().asSeconds() >= power_up_timer)
        {
            powerUps_ref.set_use_state(true);
            playerShip.set_Shoot_Speed(0.5);
        }

    }

    if (powerUps_ref.is_alive()) {

        powerUps_ref.move(window);
    }


}

void game_events::reset_power_up_clock(bool state) {

    clock_reset = state;

}


