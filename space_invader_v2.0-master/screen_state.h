//
// Created by Nikla on 2023-10-21.
//

#ifndef SPACE_INVADER_V2_SCREEN_STATE_H
#define SPACE_INVADER_V2_SCREEN_STATE_H

#include <SFML/Graphics.hpp>

class screen_state {
public:
    screen_state(std::string );


    void reset_window();
    void clear_window();
    void draw(sf::RenderWindow &);

private:

    std::string state;
    sf::Sprite sprite;
    sf::Texture texture;

};


#endif //SPACE_INVADER_V2_SCREEN_STATE_H
