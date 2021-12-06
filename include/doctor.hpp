#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "person.hpp"

class doctor : public person
{
public:
    enum class specialties {SURGEON, PHYSICIAN};
    
    doctor() { }
    doctor(std::string, doctor::specialties);
    ~doctor() {}            

    void setSpecialty(doctor::specialties);
    doctor::specialties getSpecialty();

    void makeAbstract() { };
private:
    doctor::specialties specialty;
};


#endif // DOCTOR_HPP
