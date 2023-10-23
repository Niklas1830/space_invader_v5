//
// Created by Nikla on 10/20/2023.
//

#include <iostream>
#include "player_ship.h"



player_ship::player_ship(std::vector<bullet> &bullets) : bullets(bullets) {

    fireRate = 0.5f;
    speed = 3;
    player_size = 3;
    alive = false;
    start_of_game = true;

    player_texture.loadFromFile("Texture\\Player_Ship.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setScale(player_size, player_size);
    player_sprite.setPosition(400, 500);


    bullet_texture.loadFromFile("Texture/Bullet.png");
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setScale(3,3);




}

void player_ship::draw(sf::RenderWindow &window) {

    window.draw(player_sprite);

    for (auto &e: bullets) {

        bullet_sprite.setPosition(e.posX(), e.posY());
        window.draw(bullet_sprite);


    }



}

void player_ship::update(game_events &game_event) {

    if (player_sprite.getPosition().x > 100) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player_sprite.move(-speed, 0);
        }
    }

    if (player_sprite.getPosition().x  < 700 - player_sprite.getScale().x-30) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player_sprite.move(speed, 0);
        }
    }

    if (reload_clock.getElapsedTime().asSeconds() > fireRate) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            bullets.emplace_back(getPosX() + 12, getPoxY() , 3);

            reload_clock.restart();
        }

    }


    game_event.updateposition(); //updates the position of the alien and bullet and alien bullets














}

double player_ship::getPosX() {

    return player_sprite.getPosition().x;
}

double player_ship::getPoxY() {
    return player_sprite.getPosition().y;
}

bool player_ship::player_alive() {

    return alive;
}

void player_ship::player_kill(bool kill) {
    alive = kill;

}

bool player_ship::isStartOfGame() const {
    return start_of_game;
}

void player_ship::setStartOfGame(bool startOfGame) {
    start_of_game = startOfGame;
}

void player_ship::set_Shoot_Speed(double firespeed) {
    fireRate = firespeed;
}

