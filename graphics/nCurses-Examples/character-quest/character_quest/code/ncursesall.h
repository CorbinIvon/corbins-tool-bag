#ifndef _FILE_NCURSES_
#define _FILE_NCURSES_

// --------------------------- NCurses for Windows / Linux ---------------------------

#ifdef LINUX
    #include <ncursesw/curses.h>
#else
  #ifdef WINDOWS
      #include <curses.h>
  #endif
#endif

#endif // _FILE_NCURSES_
