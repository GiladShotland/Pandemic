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
        if (!has_station(this->current_city))
        {
            throw logic_error("This city doesn't have a research stations!");
        }
        uint color_as_index = static_cast<uint>(color);

        if (cards.size() < num_of_cards)
        {
            throw logic_error("you don't have enough cards from this color!");
        }
        find_n_and_erase(color, num_of_cards);
        return *this;
    }

}