#!/usr/local/bin/python3.6

import curses,traceback

screen = curses.initscr()

screen.border(0)

screen.addstr(1,1,"Python curses in action!")
screen.addstr(2,1,"Python curses in action!")
#screen.clean()
#screen.addstr(2,1,"Python curses in action!")

screen.refresh()
screen.getch()

curses.endwin()









