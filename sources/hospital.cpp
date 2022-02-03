#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "include/doctor.hpp"
#include "include/patient.hpp"
#include "include/hospital.hpp"

using namespace std;

hospital::hospital(string gameDiff)
{
    if (gameDiff == "easy")
    {
        this->gameDiff = hospital::difficulty::EASY;
        incCoin(20);
        doctor temp(doctor::specialties::SURGEON);
        doctor temp2(doctor::specialties::PHYSICIAN);
        physicianDoc.push_back(temp);
        physicianDoc.push_back(temp);
        physicianDoc.push_back(temp2);
        surgeonDoc.push_back(temp2);
        surgeonDoc.push_back(temp2);
    }
    else if (gameDiff == "medium")
    {
        this->gameDiff = hospital::difficulty::NORMAL;
        incCoin(15);
        doctor temp(doctor::specialties::SURGEON);
        doctor temp2(doctor::specialties::PHYSICIAN);
        physicianDoc.push_back(temp);
        physicianDoc.push_back(temp);
        surgeonDoc.push_back(temp2);
        surgeonDoc.push_back(temp2);
    }
    else if (gameDiff == "hard")
    {
        this->gameDiff = hospital::difficulty::HARD;
        incCoin(10);
        doctor temp(doctor::specialties::SURGEON);
        doctor temp2(doctor::specialties::PHYSICIAN);
        physicianDoc.push_back(temp);
        surgeonDoc.push_back(temp2);
    }
    
    
}          

hospital::difficulty hospital::getDifficulty() const
{
    return gameDiff;
}

// void hospital::addDoctor(doctor doc)
// {
//     switch (getDifficulty())        //adding doctor cost is different in any difficulty
//     {
//     case difficulty::EASY:
//         decCoin(doc*5);             // cost is 5
//         break;
    
//     case difficulty::NORMAL:
//         decCoin(doc*10);            // cost is 10
//         break;

//     case difficulty::HARD:
//         decCoin(doc*15);            //cost is 15
//         break;
//     }
    
//     if (doc.getSpecialty() == doctor::specialties::SURGEON)
//     {
//         surgeonDoc.push_back(doc);
//     }
//     else if (doc.getSpecialty() == doctor::specialties::PHYSICIAN)
//     {
//         physicianDoc.push_back(doc);
//     }
// }

// unsigned int hospital::getDoctor() const
// {
//     return doctors.size();
    
// }

int hospital::getPhysician()
{
  return physicianDoc.size();
}

int hospital::getSurgeon()
{
  return surgeonDoc.size();
}

void hospital::incCoin(unsigned int coin)
{
    this->coin += coin;
}

void hospital::decCoin(unsigned int coin)
{
    if (this->coin < coin )
    {
        throw invalid_argument("Not enough coin");
    }
    this->coin -= coin;
}

unsigned int hospital::getCoin() const
{
    return coin;
}

void hospital::treat(patient& p)
{
    if (p.getDemand() == patient::demand::SURGERY)
    {
        if (surgeonDoc.size() == 0)
        {
            throw invalid_argument("There is no surgeon in hospital");
        }
        for (size_t i = 0; i < surgeonDoc.size(); i++)
        {
            if (!(surgeonDoc[i].isBusy()))
            {
                surgeonDoc[i].changeState();
                incCoin(5);
                p.setDemand(patient::demand::CURED);
                return;
            }
        }
        throw invalid_argument("All of surgeons are busy !!!");

    }
    else
    {
        for (size_t i = 0; i < physicianDoc.size(); i++)
        {
            if (!(physicianDoc[i].isBusy()))
            {
                surgeonDoc[i].changeState();
                if (p.getDemand() == patient::demand::PILL)
                {
                    incCoin(2);
                }
                else if (p.getDemand() == patient::demand::VISIT)
                {
                    incCoin(1);
                }
                p.setDemand(patient::demand::CURED);

                return;
            }
        }
        throw invalid_argument("All of physicians are busy !!!");
    }
}
