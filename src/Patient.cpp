#include "../include/Patient.hpp"
#include <string>


std::string Patient::toString() const {
    return "\n" + 
    std::to_string(age) + "\n" + 
    std::to_string(priority) + "\n" + 
    name;
}

std::string ShortTerm_Patient::toString() const {
    return "\n" + 
    std::to_string(age) + "\n" + 
    std::to_string(priority) + "\n" + 
    name+ "\n" +
    timeAssessed + "\n" +
    perscription;
}

std::string LongTerm_Patient::toString() const {
    return "\n" + 
    std::to_string(age) + "\n" + 
    std::to_string(priority) + "\n" + 
    name+ "\n" +
    timeAssessed + "\n" +
    std::to_string(timeNeeded)+ "\n" +
    perscription;
}

std::ostream& operator<<(std::ostream& stream, const Patient& p){
    stream << p.toString();
    return stream;
}