#include <string>

class Patient{

private:
int age;
int priority;
std::string name;

public:
//constructor
Patient(int a, int p, std::string n) : age(a) , priority(p) , name(n){}

};




class ShortTerm_Patient{

private:

int age;
std::string name;
std::string timeAssessed;
int time_needed;
std::string perscription;

public:
//constructor
ShortTerm_Patient(int a, std::string n, std::string ta, int tn, std::string per) 
: age(a) , name(n), timeAssessed(ta), time_needed(tn), perscription(per){}

};




class LongTerm_Patient{
    
private:

int age;
std::string name;
std::string timeAssessed;
int time_needed;
std::string perscription;

public:
//constructor
LongTerm_Patient(int a, std::string n, std::string ta, int tn, std::string per) 
: age(a) , name(n), timeAssessed(ta), time_needed(tn), perscription(per){}

};




class HospitalStaff{};




class Nurse{};




class Doctor{};


