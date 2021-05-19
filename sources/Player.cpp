#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <climits>
#include <unordered_map>
#include <map>
#include <set>
#include "Player.hpp"
#include <utility>
#include <set>
#include <algorithm>

#include <algorithm>
using namespace std;

namespace pandemic
{

    Player &Player::drive(City city)
    {
        if (city == this->current_city)
        {
            throw logic_error("Cant drive your own city");
        }
        if (!Board::areNeighbors(this->current_city, city))
        {
            throw logic_error("you dont have a road for this city");
        }
        this->current_city = city;
        return *this;
    }
    Player &Player::fly_direct(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("cant fly to your own city...");
        }
        if (cards.count(destination) == ZERO)
        {
            throw logic_error("cant fly - you dont have the card");
        }
        this->current_city = destination;
        cards.erase(destination);

        return *this;
    }
    Player &Player::fly_charter(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't fly to your city");
        }

        if (cards.count(this->current_city) == ZERO)
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }
        City temp = this->current_city;
        this->current_city = destination;
        cards.erase(temp);

        return *this;
    }
    Player &Player::fly_shuttle(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("cant fly from a city to itself");
        }
        if (!this->board.got_station(this->current_city) || !this->board.got_station(destination))
        {
            throw logic_error("dest dont have station");
        }

        this->current_city = destination;
        return *this;
    }
    Player &Player::build()
    {

        if (cards.find(this->current_city) == cards.end())
        {
            throw logic_error("dont have the card for building");
        }
        this->board.update_station(this->current_city);
        cards.erase(this->current_city);
        return *this;
    }
    Player &Player::discover_cure(Color color)
    {
        if (this->board.has_cure(color))
        {
            return *this;
        }
        if (!this->board.got_station(this->current_city))
        {
            throw logic_error("you must have research station in your city");
        }
        if (num_cards_in_color(color) < NUM_OF_CARDS_FOR_CURING)
        {
            throw logic_error("you dont have enough cards for curing!");
        }
        remove_n_cards(color, NUM_OF_CARDS_FOR_CURING);
        this->board.set_cure(color);
        return *this;
    }
    int Player::num_cards_in_color(Color c)
    {
        int counter = 0;
        for (auto card : cards)
        {
            if (Board::color_for_city.at(static_cast<uint>(card)) == c)
            {
                counter++;
            }
        }
        return counter;
    }

    Player &Player::treat(City city)
    {
        if (this->board[city] == 0)
        {
            throw logic_error("cant treat healthy city");
        }
        if (city != this->current_city)
        {
            throw logic_error("you need to treat your city");
        }
        Color c = Board::color_for_city.at(static_cast<uint>(city));
        if (this->board.cures_founded.at(c))
        {
            this->board[city] = 0;
        }
        else
        {
            this->board[city]--;
        }
        return *this;
    }
    string Player::role() { return ""; }
    Player &Player::take_card(const City city)
    {

        this->cards.insert(city);

        return *this;
    }

    void Player::remove_n_cards(Color &c, int n)
    {
        int counter = 0;
        set<City>::iterator it = this->cards.begin();
        while (it != cards.end())
        {
            if (this->board.get_color_for_city(*it) == c)
            {
                it = cards.erase(it);
                counter++;
            }
            
            if (counter == n)
            {
                break;
            }
            it++;
        }
    }
    void Player::remove_cards()
    {
        cards.clear();
    }
}
