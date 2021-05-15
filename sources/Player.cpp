#include <iostream>
#include "City.hpp"
#include "Player.hpp"
#include "Board.cpp"
using namespace std;

namespace pandemic
{
    Player &Player::drive(City city)
    {
        if (adj_list.at(current_city).find(city) != adj_list.at(current_city).end())
        {
            this->current_city = city;
            return *this;
        }
        throw logic_error("Can't drive to that city - there is no road between your currnt city and the given city");
    }
    Player &Player::fly_direct(City destination) { return *this; }
    Player &Player::fly_charter(City destination) { return *this; }
    Player &Player::fly_shuttle(City destination) { return *this; }
    Player &Player::build() { return *this; }
    Player &Player::discover_cure(Color color) { return *this; }
    Player &Player::treat(City city) { return *this; }
    string Player::role() { return ""; }
    Player &Player::take_card(City city) { return *this; }
}