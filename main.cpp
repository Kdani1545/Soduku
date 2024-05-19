
#include "window.hpp"

int main()
{
    window* alap = new window();
    alap->event_loop();
    delete alap;
    return 0;
}
