#ifndef PERSON_HPP
#define PERSON_HPP

class person
{
public:
    person(std::string = "person");
    ~person() { }           

    void setName(std::string);
    std::string getName();

    bool isBusy();
    void changeState();

    virtual void makeAbstract() = 0;        // only to make the abstract class
private:
    std::string name;
    bool busy = false;
};


#endif // PERSON_HPP
