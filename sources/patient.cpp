#include <iostream>
#include "include/patient.hpp"

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