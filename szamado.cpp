#include "szamado.hpp"
#include "graphics.hpp"
#include <string>
using namespace genv;
using namespace std;

szamado::szamado(int x, int y, int sx, int sy) : Widget(x, y, sx, sy) {
    szamlalo = 1;
}

void szamado::draw() {
    gout << move_to(x, y) << color(255, 255, 255) << box(size_x, size_y);
    gout << move_to(x + 2, y + 2) << color(128, 128, 128) << box(size_x - 4, size_y - 4);
    gout << move_to(x - 4 + (size_x / 2), y -10 + (size_y / 2)) << color(0, 0, 0) << text(to_string(szamlalo));
    gout << color(128, 128, 128) << move_to(x + (size_x + 4), y) << box(size_x / 3, size_x / 3)
         << color(0, 0, 0) << move_to(x-5 + (size_x + 20), y-20  + (size_y / 2)) << text("+");
    gout << color(128, 128, 128) << move_to(x + (size_x + 4), y + size_y + 4) << box(size_x / 3, size_x / 3)
         << color(0, 0, 0) << move_to(x-3 + (size_x + 20), y + size_y + 7) << text("-");
}

void szamado::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (ev.pos_x >= x + (size_x + 4) && ev.pos_x <= x + (size_x + size_x / 2) && ev.pos_y >= y && ev.pos_y <= y + size_y / 2) {
            novel();
        } else if (ev.pos_x >= x + (size_x + 4) && ev.pos_x <= x + (size_x + size_x / 2) && ev.pos_y >= y + size_y + 4 && ev.pos_y <= y + size_y + size_y / 2) {
            csokkent();
        }
    }
}

void szamado::novel() {
    if(szamlalo<9)
    {
        ++szamlalo;
    }

}

void szamado::csokkent() {
    if (szamlalo > 1) {
        --szamlalo;
    }
}

int szamado::get_szamlalo() {

    return szamlalo;
}
