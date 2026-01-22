#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <ostream>
#include <string>




//base class
//--------------------------------------------------------------

class Patient{

protected:
    int age;
    int priority;
    std::string name;
    std::string sickness;


public:
    //constructor
    Patient(int a, std::string n,int p, std::string s) : age(a) , priority(p) , name(n), sickness(s){}

    virtual std::string toString() const;

    int getAge() const;
    std::string getName() const;
    int getPriority() const;
    std::string getSickness() const;

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
    ShortTerm_Patient(int a, std::string n, int p, std::string s, std::string ta, std::string per) 
    : Patient(a,n,p,s),
    timeAssessed(ta),
    perscription(per){}

    std::string getTimeAssessed() const {
        return timeAssessed;
    }
    std::string getPerscription() const {
        return perscription;
    }

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
    LongTerm_Patient(int a,std::string n, int p, std::string s, std::string ta, std::string  tn, std::string per) 
    : Patient(a,n,p,s),
    timeAssessed(ta),
    timeNeeded(tn), 
    perscription(per){}

    std::string getTimeAssessed() const {
        return timeAssessed;
    }
    std::string getTimeNeeded() const {
        return timeNeeded;
    }
    std::string getPerscription() const {
        return perscription;
    }

    std::string toString() const override;

};


#endif