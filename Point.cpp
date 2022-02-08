#include "Point.h"



Point::Point(int x, int y)
    : m_x(x)
    , m_y(y)
{

}

bool Point::FromString(const std::string &coord)
{
    bool valid = false;
    if (coord.size() >= 2)
    {
        if (isalpha(coord[0]) && isdigit(coord[1]))
        {
            m_x = toupper(coord[0]) - 'A';
            m_y = coord[1] - '1';

            if (coord.size() >= 3)
            {
                if (isdigit(coord[2]))
                {
                    m_y = 10 + coord[2] - '1';
                    valid = true;
                }
            }
            else
            {
                valid = true;
            }
        }
    }
    return valid;
}
