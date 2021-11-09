#ifndef DOCTOR_HPP
#define DOCTOR_HPP


class doctor
{
public:
    doctor() {}                    //default constructor
    ~doctor() {}                   // default destructor

    bool isBusy();
private:
    bool busy = false;
};


#endif // DOCTOR_HPP
