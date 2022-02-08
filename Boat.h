#ifndef BOAT_H
#define BOAT_H

#include <string>
#include <random>
/*
    Aircraft carrier (5 cells)
    Battleship (4 cells)
    Cruiser (3 cells)
    Submarine (3 cells)
    Destroyer (2 cells)
*/

#include "Point.h"

class Boat
{
public:
    enum Direction {
        VERTICAL = 0,
        HORIZONTAL = 1
    };

	Boat();
	Boat(const std::string &name, char code, int size);
    ~Boat();

    void Print(const Point &p);
    std::string GetName() const;
    void SetPosition(const Point &p, Direction direction);
    void GenerateRandomPosition(int max_x, int max_y);

    void SetShot(const Point &p);

    bool IsDestroyed() const;
    
    int GetX() const;
    int GetY() const;
    int GetSize() const; 
    Direction GetDirection() const;
	
private:
    std::string m_name;
    std::vector<bool> m_shots;
	char m_code;
    int m_x;
    int m_y;
    Direction m_direction;
	int m_size;
    bool m_destroyed;
    bool GetOffset(const Point &p, int &offset);
};

#endif // BOAT_H
