#ifndef MENU_HPP
#define MENU_HPP

#include "Widget.hpp"
#include <vector>

class Menu {
public:
    Menu();
    void draw();
    void handle(genv::event ev, bool& start_game);

protected:
    std::vector<Widget*> widgets;
    bool game_started;
};

#endif
