#pragma once
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board &b, City c) : Player(b, c){};
        Dispatcher &fly_direct(City city);
        string role();
    };
}