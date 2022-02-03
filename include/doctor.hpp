#ifndef DOCTOR_HPP
#define DOCTOR_HPP

class doctor
{
public:
    enum class specialties {SURGEON, PHYSICIAN};

    doctor(){ }
    doctor(doctor::specialties);
    ~doctor() {}

    void setSpecialty(doctor::specialties);
    doctor::specialties getSpecialty();

    void changeState();
    bool isBusy();
private:
    doctor::specialties specialty;
    bool busy = false;
};


#endif // DOCTOR_HPP
