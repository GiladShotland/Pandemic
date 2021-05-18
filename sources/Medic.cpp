#include "Medic.hpp"
#include "City.hpp"

#include <vector>
#include <algorithm>

using namespace std;
namespace pandemic
{
    void Medic::medic_arrived()
    {
        City arrive_city = this->current_city;
        if (has_cure(arrive_city))
        {
            this->board[arrive_city] = 0;
        }
    }
    Medic &Medic::fly_direct(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't drive to the same city!");
        }

        set<City>::iterator iter = find_the_card(destination);
        if (iter == cards.end())
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }
        cards.erase(destination);
        this->current_city = destination;
        this->medic_arrived();
        return *this;
    }
    Medic &Medic::fly_shuttle(City destination)
    {
        if (!has_station(destination) && !has_station(this->current_city))
        {
            throw logic_error("Both of the cities don't have research stations!");
        }
        if (!has_station(destination))
        {
            throw logic_error("Your destination city doesn't have a research station!");
        }
        if (!has_station(this->current_city))
        {
            throw logic_error("Your current city doesn't have a research station!");
        }
        this->current_city = destination;
        this->medic_arrived();
        return *this;
    }
    Medic &Medic::fly_charter(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't fly to your city");
        }
        if (!check_the_card(this->current_city))
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }

        remove_card(this->current_city);
        this->current_city = destination;
        this->medic_arrived();
        return *this;
    }
    Medic &Medic::drive(City destination)
    {
        Player::drive(destination);
        medic_arrived();
        return *this;
    }
    Medic &Medic::treat(City city)
    {
        if (this->current_city != city)
        {
            throw logic_error("cant treat the city when you're not in it!");
        }
        this->board[city] = 0;
        return *this;
    }
    string Medic::role() { return "Medic"; }

}