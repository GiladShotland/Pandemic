#pragma once
#include "Player.hpp"
#include "City.hpp"
namespace pandemic
{
    class Medic : public Player
    {
    private:
        void medic_arrived(City city);

    public:
        Medic(Board &b, City c) : Player(b, c){};
        Medic &fly_direct(City city);
        Medic &fly_shuttle(City city);
        Medic &fly_charter(City city);
        Medic &drive(City city);
        Medic &treat(City city);
        string role();
    };
}