//
// Created by Nikla on 2023-10-22.
//

#ifndef SPACE_INVADER_V2_POWER_UPS_H
#define SPACE_INVADER_V2_POWER_UPS_H
#include "bullet.h"

class power_ups : public bullet{

public:
    power_ups(double , double , double);
    sf::Sprite getSprite();

    void move(sf::RenderWindow &);

    bool is_alive();
    bool is_used();
    bool is_player_hit();
    void set_use_state(bool);
    void set_player_hit(bool);
    void set_alive(bool);
    void reset(sf::RenderWindow &);


private:

    sf::Texture power_up_texture;
    sf::Sprite power_up_sprite;
    bool alive;
    bool used;
    bool player_hit;
};


#endif //SPACE_INVADER_V2_POWER_UPS_H
