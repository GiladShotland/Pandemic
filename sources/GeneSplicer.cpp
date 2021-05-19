#include "GeneSplicer.hpp"
#include "Player.hpp"
#include<set>


using namespace std;
namespace pandemic
{
    GeneSplicer &GeneSplicer::discover_cure(Color color)
    {

        if (this->board.has_cure(color))
        {
            return *this;
        }
        if (cards.size() < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("you dont have enough cards");
        }
        if (!this->board.got_station(this->current_city))
        {
            throw logic_error("you need a research station in your city");
        }
        int counter = ZERO;
        set<City>::iterator it = cards.begin();
        while (it != cards.end())
        {
            
            
                it = this->cards.erase(it);
                counter++;
                it++;
                
            
            if (counter == NUM_OF_CARDS_FOR_CURING)
                {
                    break;
                }
            
        }
        this->board.set_cure(color);

        return *this;
    }

    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
}