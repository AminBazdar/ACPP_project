#ifndef PATIENT_HPP
#define PATIENT_HPP

class patient
{
public:
    enum class demand {SURGERY = 1, PILL, VISIT, CURED};        //patient states
    patient(patient::demand);                                   // patient constructor

    void setDemand(patient::demand);
    patient::demand getDemand() const;

    void printState();
private:
    patient::demand patientDemand;                             //patient state
};  


#endif // PATIENT_HPP
