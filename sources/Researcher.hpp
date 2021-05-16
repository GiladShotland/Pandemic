#pragma once
#include "City.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    class Researcher : public Player
    {
    public:
        Researcher(Board b, City c) : Player(b, c){};
        Researcher &discover_cure(Color color);
        string role();
    };
}