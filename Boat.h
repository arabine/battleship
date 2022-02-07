#ifndef BOAT_H
#define BOAT_H

#include <string>

/*
    Aircraft carrier (5 cells)
    Battleship (4 cells)
    Cruiser (3 cells)
    Submarine (3 cells)
    Destroyer (2 cells)
*/

class Boat
{
public:
    enum Direction {
        VERTICAL,
        HORIZONTAL
    };

	Boat();
	Boat(const std::string &name, char code, int size);
    ~Boat();

	void Print();
    std::string GetName() const;
    void SetPosition(int x, int y, Direction direction);
    
    int GetX() const;
    int GetY() const;
    int GetSize() const; 
    Direction GetDirection() const;
	
private:
    std::string m_name;
	char m_code;
    int m_x;
    int m_y;
    Direction m_direction;
	int m_size;
	bool m_destroyed;

};

#endif // BOAT_H
