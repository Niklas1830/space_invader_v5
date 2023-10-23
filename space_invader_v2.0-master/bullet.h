//
// Created by Nikla on 10/20/2023.
//

#ifndef SPACE_INVADER_V2_BULLET_H
#define SPACE_INVADER_V2_BULLET_H

#include <SFML/Graphics.hpp>

class bullet {

public:

    /**
 * @brief Constructs a bullet object.
 *
 * @param x The initial x-coordinate of the bullet.
 * @param y The initial y-coordinate of the bullet.
 * @param speed The speed of the bullet.
 */
    bullet(double ,double ,double );

    /**
 * @brief Updates the position of the bullet based on its speed.
 */
    void updatePosition();
    /**
 * @brief Returns the speed of the bullet.
 *
 * @return double , The speed of the bullet.
 */
    double getBulletspeed();
    /**
* @brief Returns the x-coordinate of the bullet.
*
* @return double ,The x-coordinate of the bullet.
*/
    double posX();
    /**
 * @brief Returns the y-coordinate of the bullet.
 *
 * @return double ,The y-coordinate of the bullet.
 */
    double posY();

    /**
 * @brief Checks if the bullet is within the bounds of the window.
 *
 * @param window The window in which the bullet is checked.
 * @return bool True if the bullet is within the window, false otherwise.
 */

    bool isOnScreen(sf::RenderWindow &);
    /**
 * @brief Sets the speed of the bullet.
 *
 * @param speed The speed to be set for the bullet.
 */
    void setBulletSpeed(double );


protected:
    double x;
    double y;
    double bulletspeed;

};


#endif //SPACE_INVADER_V2_BULLET_H
