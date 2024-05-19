#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Widget.hpp"
#include "Menu.hpp"
#include "palya.hpp"
#include <vector>

class window {
protected:
    int magassag, szelesseg;
    Menu* main_menu;
    palya* game_board;
    bool game_started;
    bool game_solved;

public:
    window();
    ~window();
    void event_loop();
    void draw_congratulations();
};

#endif // WINDOW_HPP
