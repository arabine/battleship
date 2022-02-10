cmake_minimum_required(VERSION 3.5)

project(battleship LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(battleship
    main.cpp
    Random.h
    cpp-httplib/httplib.h

    Point.h
    Point.cpp

    Boat.cpp
    Boat.h

    Board.cpp
    Board.h

    Battleship.h
    Battleship.cpp

    Submarine.h
    Submarine.cpp

    Player.h
    Player.cpp

    Tile.h
    Tile.cpp

    AircraftCarrier.h
    AircraftCarrier.cpp

    Cruiser.h
    Cruiser.cpp

    Destroyer.h
    Destroyer.cpp

)

target_include_directories(battleship PUBLIC cpp-httplib)
