#include <iostream>
// #include "City.hpp"
#include "Player.hpp"

#include <algorithm>
using namespace std;

namespace pandemic
{

    Player &Player::drive(City city)
    {
        if (this->current_city == city)
        {
            throw logic_error("can't drive to the same city!");
        }
        if (!have_road(city))
        {
            throw logic_error("Can't drive to that city - there is no road between your currnt city and the given city");
        }
        this->current_city = city;
        return *this;
    }
    Player &Player::fly_direct(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't drive to the same city!");
        }

        set<City>::iterator iter = find(cards.begin(), cards.end(), destination);
        if (iter == cards.end())
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }
        cards.erase(destination);
        this->current_city = destination;
        return *this;
    }
    Player &Player::fly_charter(City destination)
    {
        if (this->current_city == destination)
        {
            throw logic_error("can't fly to your city");
        }
        set<City>::iterator iter = find_the_card(destination);
        if (iter == cards.end())
        {
            throw logic_error("cant fly to that city - you don't have the card!");
        }
        cards.erase(destination);
        this->current_city = destination;
        return *this;
    }
    Player &Player::fly_shuttle(City destination)
    {
        if (!has_station(destination) && !has_station(this->current_city))
        {
            throw logic_error("Both of the cities don't have research stations!");
        }
        if (!has_station(destination))
        {
            throw logic_error("Your destination city doesn't have a research station!");
        }
        if (!has_station(this->current_city))
        {
            throw logic_error("Your current city doesn't have a research station!");
        }
        this->current_city = destination;
        return *this;
    }
    Player &Player::build()
    {

        if (has_card(this->current_city))
        {

            update_research_station(current_city);
            remove_card(current_city); //remove the card
            return *this;
        }
        throw logic_error("you don't have a card for your city!");
    }
    Player &Player::discover_cure(Color color)
    {
        if (!has_station(this->current_city))
        {
            throw logic_error("This city doesn't have a research stations!");
        }
        find_n_and_erase(color, NUM_OF_CARDS_FOR_CURING);
        update_cure(color);
        return *this;
    }
    bool Player::find_n_and_erase(Color color, int n)
    {
        vector<City> temp;
        int counter = ZERO;
        for (const auto &card : cards)
        {
            uint card_as_index = static_cast<uint>(card);
            if (Board::color_for_city.at(card_as_index) == color)
            {
                temp.push_back(card);
                remove_card(card);
                counter++;
            }
            if (counter == n)
            {
                break;
            }
        }

        if (counter < n)
        {
            for (auto &card : temp)
            {
                cards.insert(card);
            }
            throw logic_error("You don't have enough cards from this color!");
        }
        return true;
    }

    Player &Player::treat(City city)
    {
        if (city != this->current_city)
        {
            throw logic_error("you need to treat your current city");
        }
        if (this->board[this->current_city] == ZERO)
        {

            throw logic_error("cant treat a healthy city");
        }
        this->board[city] = has_cure(city) ? 0 : --this->board[city];
        return *this;
    }
    string Player::role() { return ""; }
    Player &Player::take_card(City city)
    {

        this->cards.insert(city);
        return *this;
    }
    set<City>::iterator Player::find_the_card(City city)
    {
        set<City>::iterator it;
        it = cards.find(city);
        return it;
    }
    bool Player::check_the_card(City city)
    {
        return find_the_card(city) != cards.end();
    }
    bool Player ::has_card(City city)
    {
        return this->cards.find(city) != this->cards.end();
    }

    void Player::update_research_station(City city)
    {

        this->board.have_research_station.find(city)->second = true;
    }

    void Player::remove_card(City city)
    {
        cards.erase(city);
    }

    bool Player::has_station(City city)
    {

        return this->board.got_station(city);
    }
    bool Player::has_cure(City city)

    {
        uint city_as_index = static_cast<uint>(city);
        Color color_of_city = Board::color_for_city.at(city_as_index);
        return this->board.has_cure(color_of_city);
    }
    void Player::remove_cards()
    {
        cards.clear();
    }
    void Player::update_cure(Color color)
    {
        this->board.set_cure(color);
    }
    bool Player::have_road(City city)
    {
        vector<City> neighbors = Board::adj_list.at(this->current_city);

        for (City neighbor : Board::adj_list.at(this->current_city))
        {
            if (neighbor == city)
            {

                return true;
            }
        }
        // for (unsigned int i = ZERO; i < this->board.adj_list.at(this->current_city); i++)
        // {
        //     if (this->board.adj_list.at(this->current_city).at(i) == city)
        //     {
        //         return true;
        //     }
        // }
        return false;
    }
}