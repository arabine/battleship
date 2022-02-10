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


#include "httplib.h"

#define GAME_TCP_PORT1   12345
#define GAME_TCP_PORT2   12346

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


class Game
{

public:
    enum State {
        MY_TURN,
        HIS_TURN,
    };

    Game(Game::State state)
        : mState(state)
    {
        for (auto &b : mFleet.boats)
        {
            do {
                b.GenerateRandomPosition(10, 10);
            } while(!mPlayer.PlaceBoat(b));
        }

        mPlayer.PrintMyBoard();
    }

protected:
    State mState;
    Player mPlayer;
    Fleet mFleet;
};

class NetGame : public Game
{

public:

    NetGame(int myPort, int opponentPort, Game::State state)
        : Game(state)
        , mPort(myPort)
        , mOpponentPort(opponentPort)
    {

    }

    void Start() {
        mServer.Post("/play", [this](const httplib::Request &req, httplib::Response &res) {

            // On reçoit le tir ennemy
            if (mState == HIS_TURN)
            {
               Point p;
               p.FromString(std::string(req.body));
               std::cout << "CLIENT played: " << p;
               mPlayer.EnemyFire(p);
               mPlayer.PrintMyBoard();

               // C'est à nous de jouer
                Play();

//               res->status;
//               res->body;
            }
            else
            {

            }

            res.set_content("Hello World!", "text/plain");
        });


        // On commence à tirer si c'est à notre tour de commencer ...
        if (mState == MY_TURN)
        {
            std::cout << "[NET] Wait for oppent start..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));

            mState = HIS_TURN;
            Play();
        }

        mServer.listen("127.0.0.1", mPort);
    }

    void Play()
    {
        std::cout << "PLAY" << std::endl;
        Point p = mPlayer.Play();
        httplib::Client cli("127.0.0.1", mOpponentPort);

        auto res = cli.Post("/play", p.ToString(), "text/plain");
    }
private:
    int mPort = 12345;
    int mOpponentPort;
//    httplib::Client mClient;
    httplib::Server mServer;
};


void RunSoloGameVersusAI()
{
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

        if (!victory)
        {
            p = computer.PlayRandom();
            human.EnemyFire(p);

            victory = fleet_computer.IsDestroyed();

            human.PrintMyBoard();
            computer.PrintMyBoard();
        }
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
}


int main(int argc, char **argv)
{
	std::cout << "[BATTLE] Starting" << std::endl;

    bool solo = true;
    bool start = false;

    if (argc > 1) {
        solo = false;
        if (std::string(argv[1]) == "start")
        {
            start = true;
        }
    }

    if (solo)
    {
        RunSoloGameVersusAI();
    }
    else
    {
        int port1 = start ? GAME_TCP_PORT1 : GAME_TCP_PORT2;
        int port2 = start ? GAME_TCP_PORT2 : GAME_TCP_PORT1;
        Game::State state = start ? Game::MY_TURN : Game::HIS_TURN;

        NetGame game(port1, port2, state);
        game.Start();
    }


	return 0;
}
