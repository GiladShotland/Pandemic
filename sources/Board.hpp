#pragma once
#include <iostream>
#include "City.hpp"
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
    private:
        vector<uint> levels;
        vector<bool> cures_founded;
        vector<bool> have_research_station;

    public:
        Board() : levels(NUM_OF_CITIES, ZERO), cures_founded(NUM_OF_DISEASES, false), have_research_station(NUM_OF_CITIES, false){};
        friend class Player;
        uint &operator[](City city);
        bool is_clean();
        void remove_cures();
    };

};
