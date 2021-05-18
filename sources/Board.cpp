#include <iostream>
#include <vector>
#include <unordered_map>
// #include "Color.hpp"
// #include "City.hpp"
#include "Board.hpp"
using namespace std;
namespace pandemic

{

    unordered_map<City, vector<City>> Board::adj_list{
        {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing, {Shanghai, Seoul}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg, {Kinshasa, Khartoum}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
        {Milan, {Essen, Paris, Istanbul}},
        {Montreal, {Chicago, Washington, NewYork}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Karachi, Delhi, Chennai}},
        {NewYork, {Montreal, Washington, London, Madrid}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago, {Lima}},
        {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, Manila, LosAngeles}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
        {Washington, {Atlanta, NewYork, Montreal, Miami}}};

    const vector<string> cities_as_string{"Algiers",
                                          "Atlanta",
                                          "Baghdad",
                                          "Bangkok",
                                          "Beijing",
                                          "Bogota",
                                          "BuenosAires",
                                          "Cairo",
                                          "Chennai",
                                          "Chicago",
                                          "Delhi",
                                          "Essen",
                                          "HoChiMinhCity",
                                          "HongKong",
                                          "Istanbul",
                                          "Jakarta",
                                          "Johannesburg",
                                          "Karachi",
                                          "Khartoum",
                                          "Kinshasa",
                                          "Kolkata",
                                          "Lagos",
                                          "Lima",
                                          "London",
                                          "LosAngeles",
                                          "Madrid",
                                          "Manila",
                                          "MexicoCity",
                                          "Miami",
                                          "Milan",
                                          "Montreal",
                                          "Moscow",
                                          "Mumbai",
                                          "NewYork",
                                          "Osaka",
                                          "Paris",
                                          "Riyadh",
                                          "SanFrancisco",
                                          "Santiago",
                                          "SaoPaulo",
                                          "Seoul",
                                          "Shanghai",
                                          "StPetersburg",
                                          "Sydney",
                                          "Taipei",
                                          "Tehran",
                                          "Tokyo", "Washington"};

    vector<Color> Board::color_for_city = {Black, Blue, Black, Red, Red, Yellow, Yellow, Black, Black, Blue, Black, Blue, Red, Red, Black, Red, Yellow, Black, Yellow, Yellow, Black, Yellow, Yellow, Blue, Yellow, Blue, Red, Yellow, Yellow, Blue, Blue, Black, Black, Blue, Red, Blue, Black, Blue, Yellow, Yellow, Red, Red, Blue, Red, Red, Black, Red, Blue};

    int &Board::operator[](uint city)
    {
        uint index_of_city = static_cast<unsigned int>(city);
        return levels[city];
    }
    ostream &operator<<(ostream &outstream, const Board &board)
    {
        for (uint i = ZERO; i < NUM_OF_CITIES; i++)
        {

            outstream << "The level of " << cities_as_string.at(i) << " is " << board.levels.at(i) << endl;
        }
        outstream << " Cures Discovered for: " << endl;
        for (const auto &p : board.cures_founded)
        {
            const auto &key = p.first;
            const auto &val = p.second;
            if (p.second)
            {
                outstream << key << " ";
            }
        }
        outstream << endl;
        outstream << " Research Stations built at : " << endl;
        for (const auto &p : board.have_research_station)
        {
            const auto &key = p.first;
            const auto &val = p.second;
            if (p.second)
            {
                outstream << key << " ";
            }
        }

        outstream << endl;
        return outstream;
    }
    //boolean method not allowed to change anything in the object
    bool Board::is_clean()
    {
        for (uint i = ZERO; i < NUM_OF_CITIES; i++)
        {
            if (this->levels.at(i) > 0)
            {
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures()
    {
        cures_founded.clear();
        cures_founded.insert({Blue, false});
        cures_founded.insert({Yellow, false});
        cures_founded.insert({Red, false});
        cures_founded.insert({Black, false});
    }
    bool Board::has_cure(Color disease)
    {
        return this->cures_founded.at(disease);
    }
    void Board::set_cure(Color disease)
    {
        this->cures_founded.at(disease) = true;
    }
    bool Board::got_station(City city){
        return this->have_research_station.at(city);
    }

}