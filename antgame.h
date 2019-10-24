#include <vector>
#include <ncurses.h>

typedef std::vector< std::vector <bool> > boolMatrix;

enum Dir {up = 0, right = 1, down = 2, left = 3};

struct Ant {
	int xPos;
	int yPos;

	Dir facing;
	
	void turnRight(){
		facing = Dir((facing + 1) % 4);
	}

	void turnLeft(){
		facing = Dir((facing + 3) % 4);	// (a + 3) mod 4 = a - 1, the % is used to stay in the naturals
	}
};

class AntGame {
	
public:
	/*		   Constructors			*/
	AntGame(WINDOW* win);

	/*		    Functions			*/
	void tick();
	
	int height() const;
	int width() const;

private:

	/*		Internal Structures		*/

	boolMatrix _map;

	Ant _ant;
	
	WINDOW* _win;
	/*		    Functions			*/

	bool _antTile();
	
	void _forwardAnt();	//move ant in the direction it is facing
	void _advanceAnt();     //change tile,turn and forward the ant

};
