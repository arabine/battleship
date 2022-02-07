#include "Boat.h"
#include <iostream>

Boat::Boat()
    : m_name("unknown")
    , m_code(' ')
{
}

Boat::~Boat()
{
}

Boat::Boat(const std::string &name, char code, int size)
    : m_name(name)
    , m_code(code)
    , m_x(0)
    , m_y(0)
    , m_direction(VERTICAL)
    , m_size(size)
    , m_destroyed(false)
{
    
}


void Boat::Print()
{
    std::cout << m_code << " ";
}

int Boat::GetSize() const
{
    return m_size;    
}

std::string Boat::GetName() const
{
    return m_name;}

void Boat::SetPosition(int x, int y, Direction direction)
{
    m_x = x;
    m_y = y;
    m_direction = direction;
}


int Boat::GetX() const
{
    return m_x;
}

int Boat::GetY() const
{
    return m_y;
}

Boat::Direction Boat::GetDirection() const
{
    return m_direction;
}
