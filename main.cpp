#include <ncurses.h>
#include "antGame.cpp"

int main(){

	//ncurses standard procedure
	initscr();
	cbreak();
	noecho();

	
	//set a game in the terminal screen
	binAntGame game(stdscr);

	//Game loop. Stop with q
	char input = ' ';
	while (input != 'q'){
		input = getch();
		game.tick();		
	}


	//free window memory
	endwin();



	return 0;
}
