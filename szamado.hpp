#ifndef SZAMADO_HPP
#define SZAMADO_HPP
#include "Widget.hpp"
#include "graphics.hpp"

class szamado : public Widget {
public:
    szamado(int x, int y, int sx, int sy);
    void draw() override;
    void handle(genv::event ev) override;
    void novel();
    void csokkent();
    int get_szamlalo();
protected:
    int szamlalo = 0;
};

#endif
