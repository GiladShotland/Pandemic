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
        if (!this->has_station(city))
        {
            throw logic_error("city has no research station!");
        }
        this->current_city = city;
        return *this;
    }

}