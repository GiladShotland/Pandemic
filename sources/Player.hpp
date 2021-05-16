#pragma once
#include <iostream>
#include <vector>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic
{

    class Player
    {
    protected:
        bool have_the_card(City city);
        void update_research_station(City city);
        void remove_card(City city);
        bool has_station(City city);
        bool has_cure(City city);
        Board &board;
        City current_city;
        vector<vector<City>> cards_by_colors;
        vector<City> cards_for_this_color(City city);
        void update_cure(Color color);

    public:
        //need to check if its possible through the initialization list
        Player(Board &board, City begin_at_city) : board(board), current_city(begin_at_city)
        {
            vector<vector<City>> cards;
            for (int i = ZERO; i < NUM_OF_DISEASES; i++)
            {
                vector<City> color_array;
                cards.push_back(color_array);
            }
            this->cards_by_colors = cards;
        };
        virtual Player &fly_direct(City destination);
        virtual Player &fly_shuttle(City destination);
        virtual Player &fly_charter(City destination);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        virtual Player &take_card(City city);
        virtual Player &drive(City city);
        virtual string role();
        void remove_cards();
    };
}