#pragma once
#include "Player.hpp"
#include "City.hpp"
using namespace std;
namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        GeneSplicer(Board b, City c) : Player(b, c){};
        GeneSplicer &discover_cure(Color color);
        string role();
    };
}