//
// Created by Nikla on 10/20/2023.
//

#ifndef SPACE_INVADER_V2_ALIEN_H
#define SPACE_INVADER_V2_ALIEN_H

#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <vector>



class alien {

public:
    /**
 * @brief Constructs an alien object.
 *
 * @param x The x-coordinate of the alien.
 * @param y The y-coordinate of the alien.
 * @param texture The texture of the alien.
 * @param aliensbullets Reference to the vector of alien bullets.
 * @param alien_bullet_texture The texture of the alien's bullet.
 */
   explicit alien(float, float , sf::Texture & , std::vector<bullet> & , sf::Texture &) ;

    /**
  * @brief Returns the sprite of the alien.
  *
  * @return sf::Sprite The sprite of the alien.
  */
    sf::Sprite getSprite();
/**
 * @brief Draws the alien and its bullets to the specified window.
 *
 * @param window The window to draw the alien and its bullets on.
 */
    void draw(sf::RenderWindow &window);
/**
 * @brief Updates the position and behavior of the alien.
 *
 * @param aliens A vector of all the alien objects.
 */
    void update(std::vector<alien> & aliens);


    /**
 * @brief Assigns the properties of one alien object to another.
 *
 * @param rhs The alien object to copy the properties from.
 * @return alien& The reference to the updated alien object.
 */
   alien &operator =(const alien &);
/**
 * @brief Returns the x-coordinate of the alien.
 *
 * @return double The x-coordinate of the alien.
 */
    double alien_getX();
/**
 * @brief Returns the y-coordinate of the alien.
 *
 * @return double The y-coordinate of the alien.
 */
    double alien_getY();
/**
 * @brief Sets the alive status of the alien to false, indicating that it is killed.
 */
    void kill();
/**
 * @brief Checks if the alien is alive.
 *
 * @return bool True if the alien is alive, false otherwise.
 */
    bool isalive();




private:

    sf::Clock shoot_clock;
    sf::Clock clock_move;
    sf::Sprite alien_sprite;
    sf::Sprite alien_bullet;

    double movetime = 0.05f;
    double shoot_frequency = 1.0 + (rand() % 5) ;
    double move_direction = 1;
    bool alive;

    std::vector<bullet> &alien_bullets;


};


#endif //SPACE_INVADER_V2_ALIEN_H
