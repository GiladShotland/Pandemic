#include <iostream>
#include "City.hpp"
#include "Player.hpp"
#include "Board.cpp"
#include <algorithm>
using namespace std;

namespace pandemic
{
    const int NUM_OF_CARDS_FOR_CURING = 5;
    Player &Player::drive(City city)
    {
        if (adj_list.at(current_city).find(city) != adj_list.at(current_city).end())
        {
            this->current_city = city;
            return *this;
        }
        throw logic_error("Can't drive to that city - there is no road between your currnt city and the given city");
    }
    Player &Player::fly_direct(City destination)
    {
        int dest_as_index = city_to_int(destination);
        int color_as_index = color_for_city.at(dest_as_index);
        vector<City> cards_at_this_city_color = cards_by_colors.at(color_as_index);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), destination);
        if (iter != cards_at_this_city_color.end())
        {
            cards_at_this_city_color.erase(iter);
            this->current_city = destination;
            return *this;
        }
        throw logic_error("cant fly to that city - you don't have the card!");
    }
    Player &Player::fly_charter(City destination)
    {
        int current_city_as_index = city_to_int(this->current_city);
        int color_as_index = color_for_city.at(current_city_as_index);
        vector<City> cards_at_this_city_color = cards_by_colors.at(color_as_index);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), current_city_as_index);
        if (iter != cards_at_this_city_color.end())
        {
            cards_at_this_city_color.erase(iter);
            this->current_city = destination;
            return *this;
        }
        throw logic_error("cant fly to that city - you don't have the card!");
    }
    Player &Player::fly_shuttle(City destination)
    {
        if (has_station(destination) && has_station(this->current_city))
        {
            this->current_city = destination;
            return *this;
        }
        //3 different errors for 3 different cases - to acknowledge the user for the right logic problem
        //case 1: problem i the current city of the player
        if (has_station(destination))
        {
            throw logic_error("Your current city doesn't have a research station!");
        }
        //case 2: problem i the destination city
        if (has_station(this->current_city))
        {
            throw logic_error("Your destination city doesn't have a research station!");
        }
        //case 3: both cities
        throw logic_error("Both of the cities don't have research stations!");
    }
    Player &Player::build()
    {

        if (have_the_card(this->current_city))
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
        int color_as_index = color_to_int(color);
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
    Player &Player::treat(City city)
    {
        if (city != this->current_city)
        {
            throw logic_error("you need to treat your current city");
        }
        if (this->board[city] == 0)
        {
            throw logic_error("cant treat a healthy city");
        }
        this->board[city] = has_cure(city) ? 0 : --board[city];
        return *this;
    }
    string Player::role() { return ""; }
    Player &Player::take_card(City city)
    {
        vector<City> cards = cards_for_this_color(city);
        cards.push_back(city);

        return *this;
    }
    bool Player::have_the_card(City city)
    {

        vector<City> cards_at_this_city_color = cards_for_this_color(city);
        int current_city_as_index = city_to_int(city);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), current_city_as_index);

        return iter != cards_at_this_city_color.end();
    }
    void Player::update_research_station(City city)
    {
        int city_as_int = city_to_int(city);
        this->board.have_research_station.at(city_as_int) = true;
    }

    void Player::remove_card(City city)
    {

        vector<City> cards_at_this_city_color = cards_for_this_color(city);
        int current_city_as_index = city_to_int(city);
        vector<City>::iterator iter = find(cards_at_this_city_color.begin(), cards_at_this_city_color.end(), current_city_as_index);
        cards_at_this_city_color.erase(iter);
    }
    vector<City> Player::cards_for_this_color(City city)
    {
        int city_as_index = city_to_int(city);
        Color color_of_city = color_for_city.at(city_as_index);
        int color_index = color_to_int(color_of_city);
        vector<City> cards_at_this_city_color = this->cards_by_colors.at(color_index);
        return cards_at_this_city_color;
    }
    bool Player::has_station(City city)
    {
        int city_as_index = city_to_int(city);
        return this->board.have_research_station.at(city_as_index);
    }
    bool Player::has_cure(City city)

    {
        int city_as_index = city_to_int(city);
        Color color_of_city = color_for_city.at(city_as_index);
        int color_as_index = color_to_int(color_of_city);
        return this->board.cures_founded.at(color_as_index);
    }
    void Player::remove_cards()
    {
        for (int i = ZERO; i < NUM_OF_DISEASES; i++)
        {
            this->cards_by_colors.at(i).clear();
        }
    }
}