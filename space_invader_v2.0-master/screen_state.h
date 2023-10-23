//
// Created by Nikla on 2023-10-21.
//

#ifndef SPACE_INVADER_V2_SCREEN_STATE_H
#define SPACE_INVADER_V2_SCREEN_STATE_H

#include <SFML/Graphics.hpp>

class screen_state {
public:
    /**
 * @brief Constructs a screen_state object.
 *
 * @param  The state of the screen represented by a string to hold the texture in a location.
 */
    screen_state(std::string );

/**
 * @brief Resets the window by repositioning the sprite to the default position.
 */
    void reset_window();
    /**
 * @brief Clears the window by repositioning the sprite off-screen.
 */
    void clear_window();

/**
 * @brief Draws the screen state on the window.
 *
 * @param window The window to draw the screen state on.
 */
    void draw(sf::RenderWindow &);

private:

    std::string state;
    sf::Sprite sprite;
    sf::Texture texture;

};


#endif //SPACE_INVADER_V2_SCREEN_STATE_H
