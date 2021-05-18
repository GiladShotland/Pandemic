#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;
namespace pandemic
{
    const int ZERO = 0;
    const int NUM_OF_DISEASES = 4;
    const int NUM_OF_CITIES = 48;
    class Board
    {

    protected:
        unordered_map<City, bool> have_research_station;
        unordered_map<Color, bool> cures_founded;
        static unordered_map<City, vector<City>> adj_list;
        static vector<Color> color_for_city;

    private:
        vector<int> levels;

    public:
        Board() : levels(NUM_OF_CITIES, ZERO)
        {

            cures_founded.insert({Blue, false});
            cures_founded.insert({Yellow, false});
            cures_founded.insert({Red, false});
            cures_founded.insert({Black, false});
            for (uint i = ZERO; i < NUM_OF_CITIES; i++)
            {
                this->have_research_station.insert({static_cast<City>(i), false});
            }
        };
        ~Board() {}
        friend class Player;

        int &operator[](uint city);
        bool is_clean();
        void remove_cures();
        friend ostream &operator<<(ostream &outstream, const Board &board);
        bool has_cure(const Color disease);
        void set_cure(const Color disease);
        bool got_station(City city);
    };

};
