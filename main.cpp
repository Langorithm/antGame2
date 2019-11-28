#include <ncurses.h>
#include "antgame.h"

int main(){

	//ncurses standard procedure
	initscr();
	cbreak();
	noecho();
	
	use_default_colors();

	nodelay(stdscr, false);
	bool pause = false;
	
	
	//set a game in the terminal screen
	AntGame game(stdscr);

	//Game loop. Stop with q
	char input = ' ';
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
