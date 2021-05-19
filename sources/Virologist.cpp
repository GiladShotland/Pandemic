#include "Virologist.hpp"
#include "Color.hpp"
#include <algorithm>
#include <set>
using namespace std;
namespace pandemic
{
    string Virologist::role() { return "Virologist"; }
    Virologist &Virologist::treat(City city)
    {
        if (this->board[city] == 0)
        {
            throw logic_error("cant treat healthy city");
        }

        if (city != this->current_city && cards.count(city) == ZERO)
        {
            
            throw logic_error("you dont have card");
            
        }
        Color c = this->board.get_color_for_city(city);
        if (this->board.has_cure(c))
        {
            this->board[city] = 0;
        }
        else
        {
            this->board[city]--;
        }
        cards.erase(city);
        return *this;
    }
}