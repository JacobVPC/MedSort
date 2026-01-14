#include <string>




class Patient{

protected:
int age;
int priority;
std::string name;

public:
//constructor
Patient(int a, int p, std::string n) : age(a) , priority(p) , name(n){}

};




class ShortTerm_Patient : public Patient{

private:

std::string timeAssessed;
int time_needed;
std::string perscription;

public:
//constructor
ShortTerm_Patient(int a, std::string n, int p, std::string ta, int tn, std::string per) 
: Patient(a,p,n),
timeAssessed(ta),
time_needed(tn),
perscription(per){}

};




class LongTerm_Patient : public Patient{
    
private:

std::string timeAssessed;
int time_needed;
std::string perscription;

public:
//constructor
LongTerm_Patient(int a,int p, std::string n, std::string ta, int tn, std::string per) 
: Patient(a,p,n),
timeAssessed(ta),
time_needed(tn), 
perscription(per){}

};




class HospitalStaff{};




class Nurse{};




class Doctor{};


