#ifndef TILES_HPP
#define TILES_HPP
#include "graphics.hpp"
#include "widget.hpp"
using namespace genv;

class tiles : public Widget {
protected:
    int number = 0;
    bool overwrite = false;
    genv::color tile_color = genv::color(51, 51, 175);

public:
    tiles(int x, int y, int sx, int sy, int number, bool overwrite);
    void draw() override;
    void handle(event ev) override;
    bool is_empty();
    void set_number(int num);
    void set_color(genv::color col);
    int get_number() const;
    bool can_overwrite() const;
};

#endif
