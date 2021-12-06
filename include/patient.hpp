#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "person.hpp"

class patient : public person
{
public:
    enum class demand {SURGERY = 1, PILL, VISIT, CURED};        //patient states
    patient(std::string, patient::demand);                      // patient constructor

    void setDemand(patient::demand);
    patient::demand getDemand() const;

    void printState();

    void makeAbstract() { };
private:
    patient::demand patientDemand;                             //patient state
};  


#endif // PATIENT_HPP
