#include <ncurses.h>
#include "src/StatusBar.hpp"

int main()
{
    initscr();
    clear();
    refresh();
    curs_set(0);
    noecho();

    if (!has_colors())
    {
        // Error message
        return 1;
    }

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);

    StatusBar statusbar;
    statusbar.setText(" NORMAL ", COLOR_PAIR(1));
    statusbar.draw();

    // attron(COLOR_PAIR(1));
    // mvprintw(LINES - 1, 0, " NORMAL ");
    // attroff(COLOR_PAIR(1));
    refresh();

    getch();
    endwin();
    return 0;
}