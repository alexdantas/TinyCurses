#include "../TinyCurses.hpp"

int main(int argc, char* argv[])
{
    TinyCurses::initscr();

    TinyCurses::mvaddch(1, 1, 'x');
    TinyCurses::refresh();
    TinyCurses::getch();

    return 0;
}

