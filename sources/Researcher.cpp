#include "Researcher.hpp"
#include "Player.cpp"
using namespace std;
namespace pandemic
{
    Researcher &Researcher::discover_cure(Color color)
    {

        uint color_as_index = color_to_int(color);
        vector<City> cities_for_color = cards_by_colors.at(color_as_index);
        if (cities_for_color.size() < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("you don't have enough cards from this color!");
        }
        for (int i = ZERO; i < NUM_OF_CARDS_FOR_CURING; i++)
        {
            cities_for_color.pop_back();
        }
        return *this;
    }
    string Researcher::role()
    {
        return "Researcher";
    }
}
