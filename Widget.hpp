#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget{
protected:
    int x, y, size_x, size_y;
public:
    Widget(int _x, int _y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;


};

#endif

