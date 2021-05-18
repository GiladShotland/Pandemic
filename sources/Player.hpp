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
        set<City>::iterator find_the_card(City city);
        bool check_the_card(City city);
        bool has_card(City city);
        void update_research_station(City city);
        void remove_card(City city);
        bool has_station(City city);
        bool has_cure(City city);
        bool have_road(City city);
        bool find_n_and_erase(Color color, int n);
        Board &board;
        City current_city;
        set<City> cards;

        void update_cure(Color color);

    public:
        //need to check if its possible through the initialization list
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
        void remove_cards();
    };
}