#pragma once
#include "Player.hpp"
#include "City.hpp"
namespace pandemic
{
    class Medic : public Player
    {
    private:
        void medic_arrived();

    public:
        Medic(Board &b, City c) : Player(b, c){};
        Medic &fly_direct(City destination);
        Medic &fly_shuttle(City destination);
        Medic &fly_charter(City destination);
        Medic &drive(City destination);
        Medic &treat(City city);
        string role();
    };
}