#include "palya.hpp"
#include "graphics.hpp"
#include "tiles.hpp"
#include "szamado.hpp"
#include "widget.hpp"
#include <vector>

const int sudoku_board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

palya::palya() {
    int tile_size = 100;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int number = sudoku_board[i][j];
            bool is_initial = (number != 0);
            Widget *b1 = new tiles(j * tile_size, i * tile_size, tile_size, tile_size, number, !is_initial);
            widgets.push_back(b1);
        }
    }

    szamado *counter = new szamado(1600, 450, 100, 50);
    widgets.push_back(counter);
}

void palya::draw() {
    for (Widget *w : widgets) {
        w->draw();
    }
}

void palya::handle(genv::event ev) {
    szamado *counter = nullptr;
    for (Widget *w : widgets) {
        w->handle(ev);
        if (dynamic_cast<szamado*>(w) != nullptr) {
            counter = dynamic_cast<szamado*>(w);
        }
    }

    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (counter != nullptr) {
            for (Widget *w : widgets) {
                if (dynamic_cast<tiles*>(w) != nullptr && w->is_selected(ev.pos_x, ev.pos_y)) {
                    tiles *tile = dynamic_cast<tiles*>(w);
                    if (tile->is_empty() || tile->can_overwrite()) {
                        tile->set_number(counter->get_szamlalo());
                        if (check_validity(tile)) {
                            tile->set_color(genv::color(51, 51, 175));
                        } else {
                            tile->set_color(genv::color(255, 0, 0));
                        }
                    }
                }
            }
        }
    }
}

bool palya::check_validity(tiles* tile) {
    int index = -1;
    for (size_t i = 0; i < widgets.size(); ++i) {
        if (widgets[i] == tile) {
            index = i;
            break;
        }
    }
    if (index == -1) return false;

    int row = index / 9;
    int col = index % 9;
    int num = tile->get_number();

    for (int j = 0; j < 9; ++j) {
        if (j != col && dynamic_cast<tiles*>(widgets[row * 9 + j])->get_number() == num) {
            return false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (i != row && dynamic_cast<tiles*>(widgets[i * 9 + col])->get_number() == num) {
            return false;
        }
    }

    int start_row = row / 3 * 3;
    int start_col = col / 3 * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int r = start_row + i;
            int c = start_col + j;
            if ((r != row || c != col) && dynamic_cast<tiles*>(widgets[r * 9 + c])->get_number() == num) {
                return false;
            }
        }
    }

    return true;
}

bool palya::is_solved() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            tiles* tile = dynamic_cast<tiles*>(widgets[i * 9 + j]);
            if (tile->is_empty() || !check_validity(tile)) {
                return false;
            }
        }
    }
    return true;
}
