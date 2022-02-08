#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Point.h"

class Player
{
public:
	Player();
	
	void Print();
    void PrintMyBoard();
    bool AskForPosition(Boat &b);
    bool PlaceBoat(Boat &b);

    void EnemyFire(const Point &p);

    Point PlayRandom();
    Point Play();

private:
	Board m_myBoard;
    Board m_myShots;

};

#endif // PLAYER_H
