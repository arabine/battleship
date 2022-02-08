#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Board.h"
#include "Battleship.h"
#include "Submarine.h"
#include "AircraftCarrier.h"
#include "Destroyer.h"
#include "Cruiser.h"

struct Fleet
{
    std::vector<Boat> boats;

    bool IsDestroyed() const {
        int counter = 0;
        for (const auto &b: boats)
        {
            if (b.IsDestroyed())
            {
                std::cout << b.GetName() << " is destroyed! " << std::endl;
                counter++;
            }
        }
        return counter == boats.size();
    }

    Fleet ()
    {
        boats.push_back(Battleship());
        boats.push_back(Submarine());
        boats.push_back(AircraftCarrier());
        boats.push_back(Destroyer());
        boats.push_back(Cruiser());
    }
};

int main(int argc, char **argv)
{
	std::cout << "[BATTLE] Starting" << std::endl;
    Player human;
    Player computer;

    Fleet fleet_human;
    Fleet fleet_computer;

    // ------------------- BOUCLE D'INIT DU JOUEUR -------------------

    for (auto &b : fleet_human.boats)
    {
        // on place le bateau du joueur humain
//        human.PrintMyBoard();
//        while(!human.AskForPosition(b));

        // Version automatique
        do {
            b.GenerateRandomPosition(10, 10);
        } while(!human.PlaceBoat(b));
    }

    // ------------------- BOUCLE D'INIT DU ROBOT -------------------
    for (auto &b : fleet_computer.boats)
    {
        // on place le bateau ennemi
        do {
            b.GenerateRandomPosition(10, 10);
        } while(!computer.PlaceBoat(b));
	}
    
    human.PrintMyBoard();
    computer.PrintMyBoard();

    // ------------------- BOUCLE DE JEU  -------------------

    bool victory = false;
    Point p;
    do
    {
        p = human.Play();
        std::cout << p;
        computer.EnemyFire(p);

        victory = fleet_human.IsDestroyed();

        p = computer.PlayRandom();
        human.EnemyFire(p);

        victory = fleet_computer.IsDestroyed();

        human.PrintMyBoard();
        computer.PrintMyBoard();
    }
    while (!victory);

    if (fleet_human.IsDestroyed())
    {
        std::cout << "===============================================\n";
        std::cout << "            VOUS AVEZ PERDU!                   \n";
        std::cout << "===============================================\n" << std::endl;
    }
    else
    {
        std::cout << "===============================================\n";
        std::cout << "            VOUS AVEZ GAGNÉ!                   \n";
        std::cout << "===============================================\n" << std::endl;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
	std::cout << "[BATTLE] Stopped" << std::endl;
	return 0;
}
