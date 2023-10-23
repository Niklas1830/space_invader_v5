//
// Created by Nikla on 2023-10-22.
//

#ifndef SPACE_INVADER_V2_POWER_UPS_H
#define SPACE_INVADER_V2_POWER_UPS_H
#include "bullet.h"

class power_ups : public bullet{

public:
    /**
 * @brief Constructs a power_ups object.
 *
 * @param x The initial x-coordinate of the power-up.
 * @param y The initial y-coordinate of the power-up.
 * @param speed The speed of the power-up.
 */
    power_ups(double , double , double);

/**
 * @brief Returns the sprite of the power-up.
 *
 * @return sf::Sprite The sprite of the power-up.
 */
    sf::Sprite getSprite();
/**
 * @brief Moves the power-up and draws it on the window.
 *
 * @param window The window to draw the power-up on.
 */
    void move(sf::RenderWindow &);
/**
 * @brief Checks if the power-up is alive.
 *
 * @return bool True if the power-up is alive, false otherwise.
 */
    bool is_alive();
    /**
 * @brief Checks if the power-up is used.
 *
 * @return bool True if the power-up is used, false otherwise.
 */
    bool is_used();
    /**
 * @brief Checks if the power-up has hit the player.
 *
 * @return bool True if the power-up has hit the player, false otherwise.
 */
    bool is_player_hit();
    /**
 * @brief Sets the state of the power-up usage.
 *
 * @param state The state to set for the power-up usage.
 */
    void set_use_state(bool);
    /**
 * @brief Sets the state of the power-up's effect on the player.
 *
 * @param state The state to set for the power-up's effect on the player.
 */
    void set_player_hit(bool);
    /**
 * @brief Sets the state of the power-up's alive status.
 *
 * @param state The state to set for the power-up's alive status.
 */
    void set_alive(bool);
    /**
 * @brief Resets the power-up to its initial state.
 *
 * @param window The window to reset the power-up position on.
 */
    void reset(sf::RenderWindow &);


private:

    sf::Texture power_up_texture;
    sf::Sprite power_up_sprite;
    bool alive;
    bool used;
    bool player_hit;
};


#endif //SPACE_INVADER_V2_POWER_UPS_H
