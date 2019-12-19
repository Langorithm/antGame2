#include <vector>
#include <ncurses.h>


typedef std::vector< std::vector <bool> > boolMatrix;
/*typedef int Color;


#define bg 	-1;
#define black 	 0;
#define red 	 1;
#define green 	 2;
#define yellow 	 3;
#define blue 	 4;
#define magenta  5;
#define cyan 	 6;
#define white 	 7;
*/
enum Dir {up = 0, right = 1, down = 2, left = 3};
enum Color {black = 0, red = 1, green = 2, yellow = 3, blue = 4, magenta = 5, cyan = 6, white = 7, bg = -1};


struct Ant {
	int xPos;
	int yPos;
	Color color;
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

	bool _antTile(Ant ant);
	
	void _forwardAnt(Ant& ant);	//move ant in the direction it is facing
	void _advanceAnt(Ant& ant);     //change tile,turn and forward the ant
	void _printAnt(Ant ant);

};
