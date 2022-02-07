#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Tile.h"

class Board
{
    
public:
	Board();
	
	bool AddBoat(Boat &b);
    int GetSize() const { return m_gridSize; }
	void Print();
    
private:
    int m_gridSize = 10;
	Tile m_tiles[10][10];
	
	Boat m_boats[10];
	int m_nbBoats;
};

#endif // BOARD_H