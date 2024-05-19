#include "tiles.hpp"
#include "Widget.hpp"
#include "graphics.hpp"
using namespace genv;

tiles::tiles(int _x, int _y, int sx, int sy, int _number, bool _overwrite) : Widget(_x, _y, sx, sy), number(_number), overwrite(_overwrite) {}

void tiles::draw() {
    canvas c(size_x, size_y);
    c << color(0, 0, 0) << move_to(0, 0) << box(size_x, size_y) << color(tile_color) << move_to(2, 2) << box_to(size_x - 2, size_y - 2);
    if (number != 0) {
        c << color(255, 255, 255) << move_to(size_x / 2 - 5, size_y / 2 + 5) << text(std::to_string(number));
    }
    gout << stamp(c, x, y);
}

void tiles::handle(event ev) {

}

bool tiles::is_empty() {
    return number == 0;
}

void tiles::set_number(int num) {
    number = num;
}

void tiles::set_color(genv::color col) {
    tile_color = col;
}

int tiles::get_number() const {
    return number;
}

bool tiles::can_overwrite() const {
    return overwrite;
}
