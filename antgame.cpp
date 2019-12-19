#include "antgame.h"

/*		Public		*/

AntGame::AntGame(WINDOW* win){
	//Create map//
	
	int rows;
	int cols;
	getmaxyx(win, rows, cols);
	
	_win = win;
	std::vector<bool> falseRow(cols, false);
	_map = boolMatrix(rows, falseRow);
	
	//Set ant//
	_ant.facing = up;
	_ant.xPos = cols/2;
	_ant.yPos = rows/2;	
	_ant.color = red;
	//Set colors//	
	start_color();
	Color bg = Color(-1);
	init_pair(red, red, bg);

}

void AntGame::tick(){
	_advanceAnt(_ant);
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
		
		mvwaddch(_win, _ant.yPos, _ant.xPos, ' ');
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
	mvwaddch(_win, _ant.yPos, _ant.xPos, 'x');
	attroff(COLOR_PAIR(ant.color));	

}












