#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <vector>
#include "include/doctor.hpp"
#include "include/patient.hpp"

class hospital
{
public:
    enum class difficulty {EASY = 1, NORMAL, HARD};        //game difficulty
    
    hospital(std::string);                        //constructor:game difficulty
    ~hospital(){ }                                         // default deatructor


    hospital::difficulty getDifficulty() const;

    //void addDoctor(doctor);                              //adding doctor to hospital
    //unsigned int getDoctor() const;                      // returns number of doctors

    unsigned int getCoin() const;                        // returns coin numbers

    void treat(patient&);

    int getPhysician();
    int getSurgeon();

private:
    hospital::difficulty gameDiff;                      //game difficulty

    std::vector<doctor> physicianDoc;
    std::vector<doctor> surgeonDoc;                     // hospital docs

    void incCoin(unsigned int);                         // increase player coins
    void decCoin(unsigned int);                         // decrease player coins
    unsigned int coin = 0;
};


#endif // HOSPITAL_HPP
