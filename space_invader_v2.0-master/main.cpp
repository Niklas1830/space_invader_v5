#include <iostream>
#include <SFML/Graphics.hpp>
#include "player_ship.h"
#include "alien.h"
#include "game_events.h"
#include "screen_state.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    window.setFramerateLimit(60);


    std::vector<bullet> bullet_vector;
    std::vector<alien> alien_vector;
    std::vector<bullet> alien_bullets_vector;
    power_ups powerUps(350, 0, -2);
    float alien_startX = 10;
    float alien_startY = 10;
    std::string Start_Screen = "Texture/Strart_Screen.png";
    std::string Win_Screen = "Texture/Win.png";
    std::string Lose_screen = "Texture/Lose.png";

    //have to put textures here, if put power_up_texture in class it will not load the power_up_texture at all
    sf::Texture alien_texture;
    alien_texture.loadFromFile("Texture/Alien_UFO.png");
    sf::Texture alien_bullet_texture;
    alien_bullet_texture.loadFromFile("Texture/Alien_Bullet.png");


    screen_state start(Start_Screen);
    screen_state win(Win_Screen);
    screen_state lose(Lose_screen);
    player_ship p1(bullet_vector);

    game_events game_event(bullet_vector, alien_vector, p1, alien_bullets_vector, powerUps);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        start.draw(window);

        for (auto &e: alien_vector) {
            e.update(alien_vector);
            e.draw(window);


        }


        bool enter_is_pressed_check = false;
        if (!p1.player_alive() || alien_vector.empty() && p1.player_alive()) {
            if (!p1.isStartOfGame()) {
                lose.reset_window();
                lose.draw(window);
            }
            if (alien_vector.empty() && !p1.isStartOfGame() && p1.player_alive()) {
                win.reset_window();
                win.draw(window);

            }

            alien_vector.clear();
            alien_bullets_vector.clear();
            bullet_vector.clear();


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enter_is_pressed_check) {
                alien_startY = 10;
                alien_startX = 10;
                lose.clear_window();
                win.clear_window();
                start.clear_window();
                p1.player_kill(true);

                for (int i = 0; i < 21; ++i) {
                    if (alien_startX <= 400) {
                        alien_vector.push_back(
                                alien(alien_startX, alien_startY, alien_texture, alien_bullets_vector,
                                      alien_bullet_texture));
                        alien_startX += 70;
                    } else {
                        alien_vector.push_back(
                                alien(alien_startX, alien_startY, alien_texture, alien_bullets_vector,
                                      alien_bullet_texture));
                        alien_startX = 10;
                        alien_startY += 70;


                    }

                }

                p1.setStartOfGame(false);
                bool enter = true;

            }

                powerUps.reset(window);
            game_event.reset_power_up_clock(true);

        }


        if (p1.player_alive() ) {

            game_event.powerup(window);
        }


        game_event.playerkill(p1, alien_bullets_vector);
        game_event.checkCollision();
        game_event.updateposition();
        p1.draw(window);
        p1.update(game_event);

        window.display();
    }

    return 0;

}


