#pragma once
#include <iostream>
#include <vector>
#include "Board.hpp"
// #include "City.hpp"
// #include "Color.hpp"
using namespace std;
namespace pandemic
{
    const uint NUM_OF_CARDS_FOR_CURING = 5;
    class Player
    {
    private:
    protected:
        Board &board;
        City current_city;
        set<City> cards;

    public:
               Player(Board &board, City begin_at_city) : board(board), current_city(begin_at_city){};
        virtual Player &fly_direct(City destination);
        virtual Player &fly_shuttle(City destination);
        virtual Player &fly_charter(City destination);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        virtual Player &take_card(City city);
        virtual Player &drive(City city);
        virtual string role();
        int num_cards_in_color(Color c);
        void remove_n_cards(Color &c, int n);
        void remove_cards();
    };
}