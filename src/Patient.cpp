#include "../include/Patient.hpp"
#include <string>

//To string method for Patient class
std::string Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Patient Name : " +  name +
    "\n Priority : " +  std::to_string(priority)+"\n";
}


//to string method for short term patient class
std::string ShortTerm_Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Short Term Patient Name : " +  name +
    "\n Priority : " +  std::to_string(priority) + 
    "\n Time Assessed :" +  timeAssessed +
    "\n Perscription : " +perscription+"\n";
}


//to string method for long term patient class
std::string LongTerm_Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Long Term Patient Name : " +  name +
    "\n Priority : " +  std::to_string(priority) + 
    "\n Time Assessed :" +  timeAssessed +
    "\n Time Needed : " + timeNeeded +
    "\n Perscription : " + perscription +"\n";
}


//works with all the patient classes 
std::ostream& operator<<(std::ostream& stream, const Patient& p){
    stream << p.toString();
    return stream;
}

int Patient::getPriority() const {
    return priority;
}
