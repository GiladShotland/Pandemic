
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace std;
namespace pandemic
{
    string FieldDoctor::role()
    {
        return "FieldDoctor";
    }
    FieldDoctor &FieldDoctor::treat(City city)
    {
        if (have_road(city))
        {
            throw logic_error("there is no way to drive to the city you want to treat!");
        }
        if (this->board[city] == ZERO)
        {

            throw logic_error("cant treat healthy city");
        }
        this->board[city] = has_cure(city) ? 0 : board[city] - 1;
        return *this;
    }
}