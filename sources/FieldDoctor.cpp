
#include "Player.hpp"
#include "FieldDoctor.hpp"
#include "Board.hpp"
#include "Board.cpp"

using namespace std;
namespace pandemic
{
    string FieldDoctor::role()
    {
        return "FieldDoctor";
    }
    FieldDoctor &FieldDoctor::treat(City city)
    {
        if (city != this->current_city && adj_list.at(current_city).find(city) == adj_list.at(current_city).end())
        {
            throw logic_error("there is no way to drive to the city you want to treat!");
        }
        if (this->board[city] == 0)
        {
            throw logic_error("cant treat a healthy city");
        }
        this->board[city] = has_cure(city) ? 0 : --board[city];
        return *this;
    }
}