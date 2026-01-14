#include "../include/Patient.hpp"
#include <string>


std::string Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Name : " +  name +
    "\n Priority : " +  std::to_string(priority);
}

std::string ShortTerm_Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Name : " +  name +
    "\n Priority : " +  std::to_string(priority) + 
    "\n Time Assessed :" +  timeAssessed +
    "\n Perscription : " +perscription;
}

std::string LongTerm_Patient::toString() const {
    return 
    "\n Age : " + std::to_string(age) + 
    "\n Name : " +  name +
    "\n Priority : " +  std::to_string(priority) + 
    "\n Time Assessed :" +  timeAssessed +
    "\n Time Needed : " + timeNeeded +
    "\n Perscription : " + perscription;
}

std::ostream& operator<<(std::ostream& stream, const Patient& p){
    stream << p.toString();
    return stream;
}