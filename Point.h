#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point
{
public:
    Point(int x = 0, int y = 0);

    int GetX() const { return m_x; }
    int GetY() const { return m_y; }

    bool FromString(const std::string &coord);
    std::string ToString() const;

    friend std::ostream& operator<< (std::ostream& stream, const Point& p) {
        stream << "X: " << p.GetX() << ", Y: " << p.GetY() << std::endl;
        return stream;
    }

private:
    int m_x;
    int m_y;
};



#endif // POINT_H
