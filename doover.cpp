#include "antgame.h"

/*		Public		*/

AntGame::AntGame(WINDOW* win){
	//Create map//
	int rows;
	int cols;
	getmaxyx(win, rows, cols);

	std::vector<bool> falseRow(cols, false);
	_map = boolMatrix(rows, falseRow);
	
	//Set ant//
	_ant.facing = up;
	_ant.xPos = cols/2;
	_ant.yPos = rows/2;	

}

void AntGame::tick(){
	_advanceAnt();
	system("echo SI > SI");
	wrefresh(_win);
	
}

int AntGame::height() const{
	return _map.size();
}

int AntGame::width() const{
	return _map[0].size();
}

/*		Private		*/

bool AntGame::_antTile(){
	return _map[_ant.yPos][_ant.xPos];
}

void AntGame::_forwardAnt(){

	//advance in direction
	switch (_ant.facing){
	
		case up:
			_ant.yPos++; 
			break;
		case down:
			_ant.yPos--;
			break;
		case right:
			_ant.xPos++;
			break;
		case left:
			_ant.xPos--; 
			break;
	}
	
	//Loop around
//	_ant.xPos = (_ant.xPos + width()) % width();
//	_ant.yPos = (_ant.yPos + height()) % height();

}

void AntGame::_advanceAnt(){
	
	//Change direction
	if ( _antTile()){
		_ant.turnRight();
		mvwaddch(_win, _ant.xPos, _ant.yPos, ' ');
	} else {
		_ant.turnLeft();
		mvwaddch(_win, _ant.xPos, _ant.yPos, 'x');
	}

	//Change tile color
	_map[_ant.yPos][_ant.xPos] = !_antTile();
	
	//Move
	_forwardAnt();

	
}














