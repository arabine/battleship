
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
            m_tiles[i][j].Print(Point(j, i));
		}
		std::cout << "\n" << std::endl;
    }
}

void Board::Fire(const Point &p)
{
    Tile &t = m_tiles[p.GetY()][p.GetX()];
    t.SetShot(p);
}

bool Board::AddBoat(Boat &b)
{
    bool valid = true;
    int x = b.GetX();
    int y = b.GetY();
    
    if (b.GetDirection() == Boat::VERTICAL)
    {
        // On regarde s'il y a de la place vers le bas (que ça ne sorte pas de la grille)
        if ((y + b.GetSize()) <= m_gridSize)
        {
            // On vérifie les cases libres
            for (int i = 0; i < b.GetSize(); i++)
            {
                if (m_tiles[y+i][x].GetState() != Tile::TILE_EMPTY)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                for (int i = 0; i < b.GetSize(); i++)
                {
                    m_tiles[y+i][x].SetBoat(b);
                }
            }
        }
        else
        {
            valid = false;
        }
    }
    else
    {
        // On regarde s'il y a de la place vers a droite
        if ((x + b.GetSize()) <= m_gridSize)
        {
            for (int i = 0; i < b.GetSize(); i++)
            {
                if (m_tiles[y][x+i].GetState() != Tile::TILE_EMPTY)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                for (int i = 0; i < b.GetSize(); i++)
                {
                    m_tiles[y][x+i].SetBoat(b);
                }
            }
        }
        else
        {
            valid = false;
        }
    }

    
    return valid;
	
}
