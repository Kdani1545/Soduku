// Menu.cpp
#include "Menu.hpp"
#include "graphics.hpp"
#include "Button.hpp"
#include <vector>
using namespace genv;

Menu::Menu() {

    Button* start_button = new Button(800, 400, 200, 50, "Start Game");
    widgets.push_back(start_button);
}

void Menu::draw() {
    gout << move_to(0, 0) << color(0, 0, 0) << box(1800, 1000);
    if (!game_started) {
        for (Widget* w : widgets) {
            w->draw();
        }
    }
}


void Menu::handle(event ev, bool& start_game) {
    for (Widget* w : widgets) {
        w->handle(ev);
        Button* button = dynamic_cast<Button*>(w);
        if (button && button->is_pressed(ev)) {
            start_game = true;
        }
    }
}
