#include "window.hpp"
#include "graphics.hpp"
#include "Widget.hpp"
#include "Menu.hpp"
#include "palya.hpp"
#include <vector>
using namespace genv;

window::window() {
    szelesseg = 1800;
    magassag = 1000;
    gout.open(szelesseg, magassag);
    gout << font("LiberationSans-Regular.ttf", 20);
    gout << refresh;

    main_menu = new Menu();
    game_board = nullptr;
    game_started = false;
    game_solved = false;
}

window::~window() {
    delete main_menu;
    if (game_board != nullptr) {
        delete game_board;
    }
}

void window::event_loop() {
    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        if (!game_started) {
            main_menu->handle(ev, game_started);
            main_menu->draw();
        } else if (!game_solved) {
            if (game_board == nullptr) {
                game_board = new palya();
            }
            game_board->handle(ev);
            gout << move_to(0, 0) << color(0, 0, 0) << box_to(1800 - 1, 1000 - 1);
            game_board->draw();
            if (game_board->is_solved()) {
                game_solved = true;
            }
        } else {
            draw_congratulations();
        }
        gout << refresh;
    }
}

void window::draw_congratulations() {
    gout << move_to(0, 0) << color(0, 0, 0) << box(szelesseg, magassag);
    gout << move_to(szelesseg / 2 - 100, magassag / 2) << color(255, 255, 255) << text("Gratulalok!");
}
