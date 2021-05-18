#include "Virologist.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic
{
    string Virologist::role() { return "Virologist"; }
    Virologist &Virologist::treat(City city)
    {
        if (!check_the_card(city))
        {
            throw logic_error("You can't treat without having the card of the city!");
        }
        if (this->board[city] == 0)
        {
            throw logic_error("can't treat a healthy city!");
        }
        this->board[city] = has_cure(city) ? 0 : --this->board[city];
        return *this;
    }

}