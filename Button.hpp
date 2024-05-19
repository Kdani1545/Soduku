#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Widget.hpp"
#include "graphics.hpp"
#include <string>

class Button : public Widget {
public:
    Button(int x, int y, int sx, int sy, std::string label);
    void draw() override;
    void handle(genv::event ev) override;
    bool is_pressed(genv::event ev);

protected:
    std::string label;
};

#endif
