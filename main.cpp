#include <ncurses.h>
#include "antgame.h"

int main(){

	//ncurses standard procedure
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, false);
	use_default_colors();	


	//set a game in the terminal screen
	AntGame game(stdscr, 5);
	
	//Game loop. Stop with q
	char input = ' ';
	bool pause = false;
	while (input != 'q'){

		if (input == 'p'){
			pause = !pause;
			nodelay(stdscr, pause);
		}
		input = getch();
		game.tick();		
	}


	//free window memory
	endwin();



	return 0;
}
