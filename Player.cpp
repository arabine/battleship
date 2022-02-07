
#include "Player.h"
#include <iostream>
#include <iomanip>

Player::Player()
{
	
}

void Player::PrintMyBoard()
{
    m_myBoard.Print();
}


void Player::Print()
{	
    PrintMyBoard();
	std::cout << "---------- MES TIRS ----------" << std::endl;
	m_myShots.Print();
}

bool Player::PlaceBoat(Boat& b)
{
    bool valid = false;
    
    std::cout << "Placement le bateau: " <<  b.GetName() << std::endl;
    std::cout << "Entrez les coordonnées de la proue (ex: B4): ";
    
    std::string coord;
    std::cin >> coord;
    
    std::cout << "Entrez l'orientation du bateau (sens croissant)(0=vertical, 1=horizontal): ";
    
    std::string direction;
    std::cin >> direction;
    
    if (isalpha(coord[0]) && isdigit(coord[1]))
    {
        int x = toupper(coord[0]) - 'A';
        int y = coord[1] - '1';
        
        if (isdigit(coord[2]))
        {
            y = 10 + coord[2] - '1';
        }
        
        Boat::Direction dir = Boat::HORIZONTAL;
        if (direction[0] == '0')
        {
            dir = Boat::VERTICAL;
        }
        
        std::cout << x << " " << y << std::endl;
        
        if ((x < m_myBoard.GetSize()) && (y < m_myBoard.GetSize()))
        {
            b.SetPosition(x, y, dir);
            valid = m_myBoard.AddBoat(b);
        }
    }
    
    if (!valid)
    {
        std::cout << "Coordonnées invalides" << std::endl;
    }
    
    return valid;
}
