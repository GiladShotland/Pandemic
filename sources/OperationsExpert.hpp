#pragma once
#include "Player.hpp"
#include "City.hpp"
using namespace std;
namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board &b, City c) : Player(b, c){};
        OperationsExpert &build();
        string role();
    };
}