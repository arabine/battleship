#include "Tile.h"
#include <iostream>

Tile::Tile()
    : m_state(TILE_EMPTY)
    , m_boat(nullptr)
{
}

Tile::~Tile()
{
}

void Tile::SetBoat(Boat &b)
{
    m_boat = &b;
    m_state = TILE_BOAT;
}

Tile::State Tile::GetState() const
{
    return m_state;}


void Tile::Print()
{
    if(m_state == TILE_EMPTY) {
        std::cout << "."
                  << " ";
    } else if(m_state == TILE_BOAT) {
        if(m_boat != nullptr) {
            m_boat->Print();
        } else {
            std::cout << "[TILE] Error! Invalid tile state: boat cannot be null" << std::endl;
        }
    } else if(m_state == TILE_SHOT) {
        std::cout << "O"
                  << " ";
    } else {
        std::cout << "[TILE] Error! Invalid tile state: unknown state value" << std::endl;
    }
}
