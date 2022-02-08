#ifndef TILE_H
#define TILE_H

#include "Boat.h"
#include "Point.h"

class Tile
{

public:
	enum State {
		TILE_EMPTY,
		TILE_BOAT,
		TILE_SHOT,
	};

	Tile();
    ~Tile();
	
    void Print(const Point &p);
    void SetBoat(Boat &b);
    void SetShot(const Point &p);
	Tile::State GetState() const;
    
private:
	State m_state;
	Boat *m_boat;
};


#endif // TILE_H
