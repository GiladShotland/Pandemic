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
        update_research_station(current_city);
        return *this;
    }
}