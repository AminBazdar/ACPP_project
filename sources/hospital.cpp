#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "doctor.hpp"
#include "patient.hpp"
#include "hospital.hpp"

using namespace std;

hospital::hospital(string hospitalName, hospital::difficulty gameDiff)
{
    setName(hospitalName);
    this->gameDiff = gameDiff;

    switch (gameDiff)               //in different difficulty player has different doc and coin nos
    {
    case difficulty::EASY:          
        doctors.resize(5);
        this->coin = 20;
        break;
    
    case difficulty::NORMAL:
        doctors.resize(3);
        this->coin = 15;
        break;
        
    case difficulty::HARD:
        doctors.resize(2);
        this->coin = 10;
        break;
    }
}          

void hospital::setName(string hospitalName)
{
    this->hospitalName = hospitalName;
}

std::string hospital::getName() const
{
    return hospitalName;
}

hospital::difficulty hospital::getDifficulty() const
{
    return gameDiff;
}

void hospital::addDoctor(unsigned int doc)
{
    switch (getDifficulty())        //adding doctor cost is different in any difficulty
    {
    case difficulty::EASY:
        decCoin(doc*5);             // cost is 5
        break;
    
    case difficulty::NORMAL:
        decCoin(doc*10);            // cost is 10
        break;

    case difficulty::HARD:
        decCoin(doc*15);            //cost is 15
        break;
    }
    doctor temp;
    doctors.push_back(temp);
}

unsigned int hospital::getDoctor() const
{
    return doctors.size();
    
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
    bool find = false;
    for (size_t i = 0; i < doctors.size() && !find; i++)
    {
        if (!doctors[i].isBusy())
        {
            find = true;
            switch (p.getDemand())
            {
            case patient::demand::SURGERY:
                incCoin(3);                // surgery fee is 10
                p.setDemand(patient::demand::CURED);
                break;
            
            case patient::demand::VISIT:
                incCoin(2);
                p.setDemand(patient::demand::CURED);
                break;

            case patient::demand::PILL:
                incCoin(1);
                p.setDemand(patient::demand::CURED);
                break;
            
            case patient::demand::CURED:
                throw invalid_argument("Patient cured before");
                break;
            }
        }
    }
    if (!find)
    {
        throw invalid_argument("There is no Unemployed doctor");
    }
}

void hospital::print() const
{
    cout << "Name: " << getName() << endl;
    switch (getDifficulty())
    {
    case difficulty::EASY :
        cout << "Difficulty: Easy" << endl;
        break;
    
    case difficulty::NORMAL:
        cout << "Difficulty: Normal" << endl;
        break;
    
    case difficulty::HARD:
        cout << "Difficulty: Hard" << endl;
        break;
    }
    cout << "Number of docs: " << getDoctor() << endl;
    cout << "Number of coins: " << getCoin() << endl;
}