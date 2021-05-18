#pragma once
#include "Player.hpp"
#include "City.hpp"
using namespace std;
namespace pandemic
{
    class Virologist : public Player
    {
    public:
        Virologist(Board &b, City c) : Player(b, c){};
        Virologist &treat(City city);
        string role();
    };
}