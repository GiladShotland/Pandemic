#include "Medic.hpp"
#include "City.hpp"
#include "Board.cpp"
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

        vector<City> cards_at_this_city_color = cards_for_this_color(destination);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), destination);
        if (iter == cards_at_this_city_color.end())
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }
        cards_at_this_city_color.erase(iter);
        this->current_city = destination;
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
        if (!have_the_card(this->current_city))
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }

        vector<City> cards_at_this_city_color = cards_for_this_color(this->current_city);
        uint current_city_as_index = city_to_int(this->current_city);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), current_city_as_index);
        cards_at_this_city_color.erase(iter);
        this->current_city = destination;
        this->medic_arrived();
        return *this;
    }
    Medic &Medic::drive(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't drive to the same city!");
        }
        if (adj_list.at(current_city).find(destination) == adj_list.at(current_city).end())
        {
            throw logic_error("Can't drive to that city - there is no road between your currnt city and the given city");
        }
        this->current_city = destination;
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