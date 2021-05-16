#include "GeneSplicer.hpp"
#include "Player.cpp"
#include "Board.hpp"
using namespace std;
namespace pandemic
{
    bool num_of_elements(vector<vector<City>> matrix)
    {
        int counter = ZERO;
        for (uint i = ZERO; i < matrix.size(); i++)
        {
            counter += matrix.at(i).size();
        }
        return counter >= NUM_OF_CARDS_FOR_CURING;
    }
    GeneSplicer &GeneSplicer::discover_cure(Color color)
    {
        if (!has_station(this->current_city))
        {
            throw logic_error("This city doesn't have a research stations!");
        }
        if (!num_of_elements(this->cards_by_colors))
        {
            throw logic_error("You don't have enough cards!");
        }
        int cards_throwed = ZERO;

        for (uint i = ZERO; i < NUM_OF_DISEASES && cards_throwed < NUM_OF_CARDS_FOR_CURING; i++)
        {
            while (cards_throwed<NUM_OF_CARDS_FOR_CURING &&this->cards_by_colors.at(i).size()> ZERO)
            {
                cards_by_colors.at(i).pop_back();
            }
        }
        this->update_cure(color);
        return *this;
    }

    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
}