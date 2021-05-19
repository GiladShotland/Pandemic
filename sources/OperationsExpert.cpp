#include "OperationsExpert.hpp"
using namespace std;
namespace pandemic
{
    string OperationsExpert::role()
    {
        return "OperationsExpert";
    }
    OperationsExpert &OperationsExpert::build()
    {
        this->board.update_station(this->current_city);
        return *this;
    }
}