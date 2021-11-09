#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <vector>
#include "doctor.hpp"
#include "patient.hpp"

class hospital
{
public:
    enum class difficulty {EASY = 1, NORMAL, HARD};        //game difficulty
    
    hospital(std::string, hospital::difficulty);           //constructor: name and game difficulty
    ~hospital(){ }                                         // default deatructor

    std::string getName() const;

    hospital::difficulty getDifficulty() const;

    void addDoctor(unsigned int);                        //adding doctor to hospital
    unsigned int getDoctor() const;                      // returns number of doctors

    unsigned int getCoin() const;                        // returns coin numbers

    void treat(patient&);

    void print() const;                                  

private:
    std::string hospitalName;
    void setName(std::string);      

    hospital::difficulty gameDiff;                      //game difficulty
    std::vector<doctor> doctors;                        // hospital docs

    void incCoin(unsigned int);                         // increase player coins
    void decCoin(unsigned int);                         // decrease player coins
    unsigned int coin = 0;
};


#endif // HOSPITAL_HPP