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

/**
 * @brief Constructs a player_ship object.
 *
 * @param bullets Reference to the vector of bullets.
 */
    explicit player_ship(std::vector<bullet> &bullets);

/**
 * @brief Draws the player ship and its bullets on the window.
 *
 * @param window The window to draw the player ship and its bullets on.
 */
    void draw(sf::RenderWindow &window);
/**
 * @brief Updates the position of the player ship based on the user input and handles shooting mechanics.
 *
 * @param game_event The game_events object to update the game state.
 */
    void update(game_events &);
/**
 * @brief Returns the x-coordinate of the player ship.
 *
 * @return double The x-coordinate of the player ship.
 */
    double getPosX();
/**
 * @brief Returns the y-coordinate of the player ship.
 *
 * @return double The y-coordinate of the player ship.
 */
    double getPoxY();
/**
 * @brief Sets the status of the player ship to alive or killed.
 *
 * @param kill The status of the player ship. True if killed, false if alive.
 */
    void player_kill(bool);
/**
 * @brief Checks if the player ship is alive.
 *
 * @return bool True if the player ship is alive, false otherwise.
 */
    bool player_alive();
/**
 * @brief Checks if it's the start of the game.
 *
 * @return bool True if it's the start of the game, false otherwise.
 */
    bool isStartOfGame() const;
/**
 * @brief Sets the start of the game state.
 *
 * @param startOfGame The state to set for the start of the game.
 */
    void setStartOfGame(bool startOfGame);
/**
 * @brief Sets the shooting speed of the player ship.
 *
 * @param firespeed The speed to set for the player ship's shooting rate.
 */
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
