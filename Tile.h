#ifndef TILE_H
#define TILE_H

#include "Boat.h"

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
	
	void Print();
    void SetBoat(Boat &b);
	Tile::State GetState() const;
    
private:
	State m_state;
	Boat *m_boat;
};


#endif // TILE_H
