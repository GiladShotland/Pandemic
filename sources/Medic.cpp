#include "Medic.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <vector>
#include <algorithm>

using namespace std;
namespace pandemic
{
    void Medic::medic_arrived(City city)
    {
        Color c = this->board.get_color_for_city(city);
        if (this->board.has_cure(c))
        {
            cout << "im in" << endl;
            this->board[this->current_city] = ZERO;
        }
    }
    Medic &Medic::drive(City city)
    {
        if (Board::areNeighbors(this->current_city, city))
        {
            this->current_city = city;
            medic_arrived(city);
            return *this;
        }
        throw logic_error("you dont have road to this city");
    }
    Medic &Medic::fly_direct(City city)
    {
        if (cards.find(city) == cards.end())
        {
            throw logic_error("you dont have the card");
        }
        if (this->current_city == city)
        {
            throw logic_error("cant fly to the same city");
        }
        this->current_city = city;
        cards.erase(city);
        medic_arrived(city);
        return *this;
    }
    Medic &Medic::fly_charter(City city)
    {
        if (cards.find(this->current_city) == cards.end())
        {
            throw logic_error("you dont have the card");
        }
        cards.erase(this->current_city);
        this->current_city = city;
        medic_arrived(city);
        return *this;
    }
    Medic &Medic::fly_shuttle(City city)
    {
        if (!this->board.got_station(city))
        {
            throw logic_error("this city don't have a research station");
        }
        if (!this->board.got_station(this->current_city))
        {
            throw logic_error("your city don't have a research station");
        }
        this->current_city = city;
        medic_arrived(city);
        return *this;
    }
    Medic &Medic::treat(City city)
    {
        if (this->current_city != city)
        {
            throw logic_error("you need to treat your own city");
        }
        if (this->board[city] == ZERO)
        {
            throw logic_error("you cant treat a healthy city");
        }
        this->board[city] = ZERO;
        return *this;
    }

    string Medic::role() { return "Medic"; }

}