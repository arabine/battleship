#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
public:
	Player();
	
	void Print();
    void PrintMyBoard();
    bool PlaceBoat(Boat &b);
    
private:
	Board m_myBoard;
	Board m_myShots;
};

#endif // PLAYER_H