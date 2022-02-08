#include "Boat.h"
#include <iostream>
#include "Random.h"

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
    m_shots.clear();
    for (int i = 0; i < size; i++)
    {
        m_shots.push_back(false);
    }
}

bool Boat::GetOffset(const Point &p, int &offset)
{
    bool inBoat = false;

    if (m_direction == VERTICAL)
    {
        // Same column X ?
        if (p.GetX() == m_x)
        {
            if (p.GetY() >= m_y)
            {
                offset = p.GetY() - m_y;
                if (offset < m_size)
                {
                    inBoat = true;
                }
            }
        }
    }
    else
    {
        // Same line Y ?
        if (p.GetY() == m_y)
        {
            if (p.GetX() >= m_x)
            {
                offset = p.GetX() - m_x;
                if (offset < m_size)
                {
                    inBoat = true;
                }
            }
        }
    }

    return inBoat;
}


void Boat::Print(const Point &p)
{
    int offset = 0;
    if (GetOffset(p, offset))
    {
        if (m_shots[offset])
        {
            char low = (m_code - 'A') + 'a';
            std::cout << low << " ";
        }
        else
        {
            std::cout << m_code << " ";
        }
    }
    else
    {
        std::cout << "CANNOT PRINT OUT OF BOAT !!" << std::endl;
    }
}

int Boat::GetSize() const
{
    return m_size;    
}

std::string Boat::GetName() const
{
    return m_name;
}

void Boat::SetPosition(const Point &p, Direction direction)
{
    m_x = p.GetX();
    m_y = p.GetY();
    m_direction = direction;
}

void Boat::GenerateRandomPosition(int max_x, int max_y)
{
    {
        Random rng(0, max_x - 1);
        m_x = rng.get();
    }

    {
        Random rng(0, max_y - 1);
        m_y = rng.get();
    }

    {
        Random rng(0, 1);
        m_direction = static_cast<Direction>(rng.get());
    }
}

void Boat::SetShot(const Point &p)
{
    int offset = 0;
    if (GetOffset(p, offset))
    {
        m_shots[offset] = true;
    }
}

bool Boat::IsDestroyed() const
{
    int count = 0;
    for (auto s : m_shots)
    {
        if (s)
        {
            count++;
        }
    }
    return count == m_size;
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
