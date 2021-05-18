#pragma once
#include "Player.hpp"
#include "City.hpp"
namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int num_of_cards;

    public:
        Scientist(Board &b, City c, int num) : Player(b, c) { this->num_of_cards = num; };
        Scientist &discover_cure(Color color);
        string role();
    };
}