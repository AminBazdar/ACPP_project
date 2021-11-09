#include <iostream>
#include "patient.hpp"

using namespace std;

patient::patient(patient::demand demand)
{
    setDemand(demand);
}

void patient::setDemand(patient::demand demand)
{
    patientDemand = demand;
}
patient::demand patient::getDemand() const
{
    return patientDemand;
}

void patient::printState()
{
    switch (getDemand())
    {
    case patient::demand::SURGERY:
        cout << "surgery" << endl;
        break;
    
    case patient::demand::PILL:
        cout << "pill" << endl;
        break;

    case patient::demand::VISIT :
        cout << "visit" << endl;
        break;

    case patient::demand::CURED :
        cout << "cured" << endl;
        break;
    }
}
