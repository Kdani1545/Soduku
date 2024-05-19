#include "Button.hpp"
#include "graphics.hpp"
using namespace genv;

Button::Button(int x, int y, int sx, int sy, std::string label) : Widget(x, y, sx, sy), label(label) {}

void Button::draw() {
    gout << move_to(x, y) << color(200, 200, 200) << box(size_x, size_y);
    gout << move_to(x + 10, y + size_y / 2) << color(0, 0, 0) << text(label);
}

void Button::handle(event ev) {

}

bool Button::is_pressed(event ev) {
    return ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y);
}
