#include "antgame.h"

/*		Public		*/

AntGame::AntGame(WINDOW* win, int antNumber){
	antNumber = antNumber > 8 ? 8 : antNumber; //max 8 ants
	
	//Create map//
	
	int rows;
	int cols;
	getmaxyx(win, rows, cols);
	
	_win = win;
	std::vector<bool> falseRow(cols, false);
	_map = boolMatrix(rows, falseRow);
	
	start_color(); 	//needed to use colors in ncurses
	Color bg = Color(-1);
	
	//Set ant//

	for (int i = 0; i < antNumber; i++){
		Ant aux;
		aux.facing = Dir(i);
		aux.xPos = cols/(i+2);
		aux.yPos = rows/(i+2);
		aux.color = Color(i+1);
	
		_ants.push_back(aux);

		init_pair(i+1, i+1, bg);
}
	//Set colors//	
	
	
}

void AntGame::tick(){
	
	for (Ant &ant : _ants){
		_advanceAnt(ant);
	}
	wrefresh(_win);
	
}

int AntGame::height() const{
	return _map.size();
}

int AntGame::width() const{
	return _map[0].size();
}

/*		Private		*/

bool AntGame::_antTile(Ant ant){
	return _map[ant.yPos][ant.xPos];
}

void AntGame::_forwardAnt(Ant& ant){

	//advance in direction
	switch (ant.facing){
	
		case up:
			ant.yPos++; 
			break;
		case down:
			ant.yPos--;
			break;
		case right:
			ant.xPos++;
			break;
		case left:
			ant.xPos--; 
			break;
	}
	
	//Loop around
	ant.xPos = (ant.xPos + width()) % width();
	ant.yPos = (ant.yPos + height()) % height();

}

void AntGame::_advanceAnt(Ant& ant){
	
	//Change direction
	if ( _antTile(ant)){
		
		mvwaddch(_win, ant.yPos, ant.xPos, ' ');
		ant.turnLeft();
	} else {
		_printAnt(ant);
		ant.turnRight();
	}

	//Change tile color
	_map[ant.yPos][ant.xPos] = !_antTile(ant);
	
	//Move
	_forwardAnt(ant);

	
}

void AntGame::_printAnt(Ant ant){
	attron(COLOR_PAIR(ant.color));	
	mvwaddch(_win, ant.yPos, ant.xPos, 'x');
	attroff(COLOR_PAIR(ant.color));	

}












