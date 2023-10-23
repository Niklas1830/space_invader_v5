//
// Created by Nikla on 10/20/2023.
//

#ifndef SPACE_INVADER_V2_PLAYER_SHIP_H
#define SPACE_INVADER_V2_PLAYER_SHIP_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include "bullet.h"
#include "alien.h"
#include "game_events.h"


class player_ship {
public:
    explicit player_ship(std::vector<bullet> &bullets);

    void draw(sf::RenderWindow &window);

    void update(game_events &);

    double getPosX();

    double getPoxY();

    void player_kill(bool);

    bool player_alive();

    bool isStartOfGame() const;

    void setStartOfGame(bool startOfGame);

    void set_Shoot_Speed(double speed);

private:

    sf::Clock reload_clock;


    sf::Sprite player_sprite;
    sf::Sprite bullet_sprite;
    sf::Texture player_texture;
    sf::Texture bullet_texture;
    double speed;
    double player_size ;
    double fireRate;
    bool alive;
    bool start_of_game;
    std::vector<bullet> &bullets;
};


#endif //SPACE_INVADER_V2_PLAYER_SHIP_H
