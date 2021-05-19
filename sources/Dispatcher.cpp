#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    string Dispatcher::role() { return "Dispatcher"; }
    Dispatcher &Dispatcher::fly_direct(City city)
    {
        if (city == this->current_city)
        {
            throw logic_error("can't fly to the same city!");
        }
        if (!this->board.got_station(this->current_city) )
        {
            if(cards.count(city) == ZERO){
                throw logic_error("you dont have the card!");
            }
            this->current_city= city;
            cards.erase(city);
            return *this;
        }
        this->current_city = city;
        return *this;
    }

}