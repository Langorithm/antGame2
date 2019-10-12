#include <vector>
#include "ncurses.h"

enum Dir{up, right, down, left};

typedef std::vector< std::vector<bool> > boolMatrix;

class binAntGame {



public:
	
	binAntGame(WINDOW* w);
	
	void tick();

	int height();
	int width();

	void printMap();
private:
	
	/*		INTERNAL STRUCTURES		*/

	//Defining Ant, the centerpiece to the game
	struct Ant {
		int xPos;
		int yPos;
		Dir dir;
		
		//Ant constructor, set at map's center, looking upwards
//		Ant() : xPos(_map.size() /2), yPos(_map[0].size() /2), Dir(up) {}
		
		void turnLeft(){
			if (dir == up){xPos--;dir=left;return;}
			if (dir == down){xPos++;dir=right;return;}
			if (dir == left){yPos--;dir=down;return;}
			if (dir == right){yPos++;dir=up;return;}
		}
		void turnRight(){
			if (dir == up){xPos++;dir=right;return;}
			if (dir == down){xPos--;dir=left;return;}
			if (dir == left){yPos++;dir=up;return;}
			if (dir == right){yPos--;dir=down;return;}
		}
	};

	WINDOW* _win;	//The window in which the game will be displayed

	boolMatrix _map;	//representation of the grid, with O(1) access to any point in the map
				//must be kept the same as the drawing window
	
	Ant _ant;	//The game's only ant
	
	
		
	/* 	FUNCTIONS	*/

	void _advanceAnt();	//moves ant one step	
	bool _antTile();		// returns a reference to tile the ant is standing on






};
