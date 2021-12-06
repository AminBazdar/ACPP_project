#include <string>
#include "doctor.hpp"

using namespace std;

doctor::doctor(string name, doctor::specialties specialty) : person(name)
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