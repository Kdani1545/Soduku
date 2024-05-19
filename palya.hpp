#ifndef PALYA_HPP
#define PALYA_HPP
#include "graphics.hpp"
#include "tiles.hpp"
#include "widget.hpp"

class palya {
public:
    palya();
    void draw();
    void handle(genv::event ev);
    bool is_solved();

protected:
    std::vector<Widget*> widgets;
    bool check_validity(tiles* tile);
};

#endif
