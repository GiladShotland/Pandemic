#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
namespace pandemic
{
    const int ZERO = 0;
    const int NUM_OF_DISEASES = 4;
    const int NUM_OF_CITIES = 48;
    class Board
    {

    protected:
        set<City> have_research_station;
        unordered_map<Color, bool> cures_founded;
        static unordered_map<City, set<City>> adj_list;
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
        };
        ~Board() {}
        friend class Player;

        int &operator[](uint city);
        bool is_clean();
        void remove_cures();
        static bool areNeighbors(const City c1, const City c2)
        {
            if (c1 == c2)
            {
                return false;
            }
            return (adj_list[c1].count(c2) != ZERO);
        }

        friend ostream &operator<<(ostream &outstream, const Board &board);
        bool has_cure(const Color disease);
        void set_cure(const Color disease);
        bool got_station(City city);

        void update_station(City city)
        {

            have_research_station.insert(city);
        }
        Color get_color_for_city(City city)
        {
            return color_for_city.at(static_cast<uint>(city));
        }
    };
};
