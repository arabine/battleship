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

std::string Point::ToString() const
{
    std::string pos;
    char y = 'A' + m_x;
    pos.push_back(y);

    if (m_y == 9)
    {
        pos.push_back('1');
        pos.push_back('0');
    }
    else
    {
        char y = '1' + m_y;
        pos.push_back(y);
    }
    pos.push_back(0);
    return pos;
}
