//
// Created by Nikla on 2023-10-21.
//

#include "screen_state.h"

screen_state::screen_state(std::string state) : state(state) {

texture.loadFromFile(state);
sprite.setTexture(texture);
sprite.setPosition(0,0);
sprite.setScale(1,1);

}

void screen_state::draw(sf::RenderWindow & window) {


    window.draw(sprite);

}

void screen_state::clear_window() {

    sprite.setPosition(-1000,-1000);

}

void screen_state::reset_window() {
    sprite.setPosition(0,0);

}
