
#include"antGame.h"
#include"iostream"
binAntGame::binAntGame(WINDOW* w){
	_win = w;
	
	int height; int width;
	getmaxyx(w,height,width);	//fetches window size

	//Creates empty map
	std::vector<bool> row(width, false);
	for (int i = 0; i<height; i++){
		_map.push_back(row);
	}	
	
        _ant.dir=up;
        _ant.yPos=height/2;
        _ant.xPos=width/2;


}

void binAntGame::tick(){
	_advanceAnt();
	wrefresh(_win);	
}


void binAntGame::_advanceAnt(){

	if ( _antTile() ){
		_map[_ant.xPos][_ant.yPos] = !_antTile();
		mvwaddch(_win,_ant.yPos,_ant.xPos,' ');
		_ant.turnLeft();
		
	} else {
		_map[_ant.xPos][_ant.yPos] = !_antTile();
		mvwaddch(_win,_ant.yPos,_ant.xPos,'*');
		_ant.turnRight();
		
	}
	
}

bool binAntGame::_antTile(){
	
	return _map[_ant.xPos][_ant.yPos];
}


void binAntGame::printMap(){

	std::cout << "h: " << _map.size() << " w: " << _map[0].size() << std::endl;
}


















