#include "Widget.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int _x, int _y, int sx, int sy) : x(_x), y(_y), size_x(sx), size_y(sy)
{
}
bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>x && mouse_x<x+size_x && mouse_y>y && mouse_y<y+size_y;
}
