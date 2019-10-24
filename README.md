# antgame

This is an implementation of Langton's Ant.
Currently it uses ncurses to run, so before compiling you must install ncurses.

### Getting ready
Install ncurses. In ubuntu do:
    
    apt install libncurses5-dev libncursesw5-dev

Compile. There is no makefile yet, so run:

    g++ main.cpp antgame.cpp -lncurses
    
---

### Controls

* **Q**: Quit
* **P**: Toggle auto-step
* Pressing any other key will advance a game 1 step
