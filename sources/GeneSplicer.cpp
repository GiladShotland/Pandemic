#include "GeneSplicer.hpp"
#include "Player.hpp"

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
        if (cards.size() < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("You don't have enough cards!");
        }

        for (uint i = ZERO; i < NUM_OF_CARDS_FOR_CURING; i++)
        {

            cards.erase(cards.begin());
        }
        this->update_cure(color);
        return *this;
    }

    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
}