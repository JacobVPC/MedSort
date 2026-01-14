#include <ostream>
#include <string>
#include <vector>



//base class
//--------------------------------------------------------------

class Patient{

protected:
    int age;
    int priority;
    std::string name;

public:
    //constructor
    Patient(int a, std::string n,int p) : age(a) , priority(p) , name(n){}

    virtual std::string toString() const;

};
std::ostream& operator<<(std::ostream&, const Patient&);



//short term patient
//--------------------------------------------------------------

class ShortTerm_Patient : public Patient{

private:
    std::string timeAssessed;
    std::string perscription;

public:
    //constructor
    ShortTerm_Patient(int a, std::string n, int p, std::string ta, std::string per) 
    : Patient(a,n,p),
    timeAssessed(ta),
    perscription(per){}

    std::string toString() const override;

};



//long term patient
//--------------------------------------------------------------

class LongTerm_Patient : public Patient{
    
private:

    std::string timeAssessed;
    std::string timeNeeded;
    std::string perscription;

public:
    //constructor
    LongTerm_Patient(int a,std::string n, int p, std::string ta, std::string  tn, std::string per) 
    : Patient(a,n,p),
    timeAssessed(ta),
    timeNeeded(tn), 
    perscription(per){}

    std::string toString() const override;

};


//vectors to store patients

extern std::vector<Patient*> Patients;
extern std::vector<ShortTerm_Patient*> ShortTerm_Patients;
extern std::vector<LongTerm_Patient*> LongTerm_Patients;