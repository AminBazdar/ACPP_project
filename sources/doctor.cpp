#include <string>
#include "include/doctor.hpp"

using namespace std;

doctor::doctor(doctor::specialties specialty)
{
    setSpecialty(specialty);
}

void doctor::setSpecialty(doctor::specialties specialty)
{
    this->specialty = specialty;
}

doctor::specialties doctor::getSpecialty()
{
    return specialty;
}

void doctor::changeState()
{
    this->busy = !busy;
}

bool doctor::isBusy()
{
    return busy;
}