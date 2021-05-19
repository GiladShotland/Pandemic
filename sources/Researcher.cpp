#include "Researcher.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    Researcher &Researcher::discover_cure(Color color)
    {

        if (this->board.has_cure(color))
        {
            return *this;
        }
        if (num_cards_in_color(color) < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("you dont have enough cards from this color");
        }
        remove_n_cards(color, NUM_OF_CARDS_FOR_CURING);
        this->board.set_cure(color);
        return *this;
    }
    string Researcher::role()
    {
        return "Researcher";
    }
}
