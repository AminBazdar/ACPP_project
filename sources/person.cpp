#include <string>
#include "person.hpp"

using namespace std;

person::person(string name)
{
    setName(name);
}

void person::setName(std::string name)
{
    this->name = name;
}

string person::getName()
{
    return name;
}

bool person::isBusy()
{
    return busy;
}
void person::changeState()
{
    busy = !busy;
}