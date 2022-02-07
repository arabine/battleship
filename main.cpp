#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Board.h"
#include "Battleship.h"
#include "Submarine.h"

int main(int argc, char **argv)
{
    Boat boats[] = { Battleship(), Submarine() };
//    uint32_t nbBoats = sizeof(boats) / sizeof(boats[0]);
    
	std::cout << "[BATTLE] Starting" << std::endl;
	Player player1;
	

    for (auto &b : boats)
    {
        player1.PrintMyBoard();
        while(!player1.PlaceBoat(b));
	}
    
    player1.PrintMyBoard();
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
	std::cout << "[BATTLE] Stopped" << std::endl;
	return 0;
}
