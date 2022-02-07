
#include "Board.h"
#include <iostream>

Board::Board()
{
	m_nbBoats = 0;
}

void Board::Print()
{
    char hor = 'A';
    std::cout << "   ";
    // On affiche les coordonnées
    for (int i = 0; i < m_gridSize; i++) {
        std::cout << hor << " ";
        hor++;
    }
    std::cout << std::endl; 
    
	for (int i = 0; i < m_gridSize; i++)
	{
        if (i < 9)
        {
            std::cout << " ";
        }
        std::cout << i+1 << " ";
		for (int j = 0; j < m_gridSize; j++)
		{
			m_tiles[i][j].Print();
		}
		std::cout << "\n" << std::endl;
	}
}

bool Board::AddBoat(Boat &b)
{
    bool valid;
    int x = b.GetX();
    int y = b.GetY();
    
    // On teste d'abord si l'emplacement de la proue est libre
    if (m_tiles[y][x].GetState() == Tile::TILE_EMPTY)
    {
        if (b.GetDirection() == Boat::VERTICAL)
        {
            // On regarde s'il y a de la place vers le bas
            if ((y + b.GetSize()) < m_gridSize)
            {
                for (int i = 0; i < b.GetSize(); i++)
                {
                    m_tiles[y+i][x].SetBoat(b);
                }
                valid = true;
            }
        }
        else
        {
            // On regarde s'il y a de la place vers a droite
            if ((x + b.GetSize()) < m_gridSize)
            {
                for (int i = 0; i < b.GetSize(); i++)
                {
                    m_tiles[y][x+i].SetBoat(b);
                }
                valid = true;
            }
        }
        
        valid = true;
    }
    
    return valid;
	
}
