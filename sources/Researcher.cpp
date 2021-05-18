#include "Researcher.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    Researcher &Researcher::discover_cure(Color color)
    {

        if (cards.size() < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("you don't have enough cards from this color!");
        }
        for (uint i = ZERO; i < NUM_OF_CARDS_FOR_CURING; i++)
        {
            cards.erase(cards.begin());
        }
        return *this;
    }
    string Researcher::role()
    {
        return "Researcher";
    }
}
