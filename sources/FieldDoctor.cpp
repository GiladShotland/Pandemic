
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
        if (!Board::areNeighbors(this->current_city, city) && this->current_city != city)
        {
            throw logic_error("you dont have road to this city");
        }
        if (this->board[city] == ZERO)
        {
            throw logic_error("cant treat a healthy city");
        }
        if (this->board.has_cure(this->board.get_color_for_city(city)) )
        {

            this->board[city] = ZERO;
        }
        
        else
        {
            this->board[city]--;
        }

        return *this;
    }

}