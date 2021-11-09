#include <iostream>
#include "hospital.hpp"
#include "patient.hpp"

using namespace std;

int main()
{
    //lower coads are for testing the classes and mathods...

    hospital temp("hosp", hospital::difficulty::NORMAL);    // making a hospital object(start of game)
    temp.print();                                           // print is temporary function for printing hospital details 
    cout << "-------------------------------------" << endl;
    temp.addDoctor(1);                                      // add doctor: it acts like buying doctor from store: compelete in next phases 
    temp.print();                                           // for checking buying function 
    cout << "-------------------------------------" << endl;

    patient firstPatient(patient::demand::SURGERY);         // maikng a patint object
    firstPatient.printState();                              // printing state before treatnent
    cout << "-------------------------------------" << endl;
    temp.treat(firstPatient);                               // treating the patinet
    firstPatient.printState();                              // printing state after treatment
    cout << "-------------------------------------" << endl;
    temp.print();                                           // hospital details after treating a patinet

    return 0;
}