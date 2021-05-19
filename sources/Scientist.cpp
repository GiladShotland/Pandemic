#include "Scientist.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic
{
    string Scientist::role()
    {
        return "Scientist";
    }
    Scientist &Scientist::discover_cure(Color color)
    {
        if (this->board.has_cure(color))
        {
            return *this;
        }
        if (num_cards_in_color(color) < this->num_of_cards)
        {
            throw logic_error("you dont have enough cards");
        }
        if (!this->board.got_station(this->current_city))
        {
            throw logic_error("you dont have a research station in your city");
        }
        remove_n_cards(color, this->num_of_cards);
        this->board.set_cure(color);
        return *this;
    }

}