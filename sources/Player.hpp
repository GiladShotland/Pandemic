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
    private:
        vector<vector<Color>> cards_by_colors;
        Board &board;
        City current_city;

    public:
        Player(Board &board, City begin_at_city) : board(board), current_city(begin_at_city)
        {
            vector<vector<Color>> cards;
            for (int i = ZERO; i < NUM_OF_DISEASES; i++)
            {
                vector<Color> color_array;
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
    };
}