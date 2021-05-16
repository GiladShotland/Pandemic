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
        uint color_as_index = color_to_int(color);
        vector<City> cities_for_color = cards_by_colors.at(color_as_index);
        if (cities_for_color.size() < num_of_cards)
        {
            throw logic_error("you don't have enough cards from this color!");
        }
        for (int i = ZERO; i < num_of_cards; i++)
        {
            cities_for_color.pop_back();
        }
        return *this;
    }

}