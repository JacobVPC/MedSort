#include "../include/HospitalStaff.hpp"



void PrioritizePatients(std::vector<Patient*>& vec){
    //bubble sort to sort patients by 1-5 severity, 1 being most severe 5 being least (real hospital stuff ;) )

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec.at(j)->getPriority() > vec.at(j + 1)->getPriority()) {
                //swap
                Patient* temp = vec.at(j);
                vec.at(j) = vec.at(j + 1);
                vec.at(j + 1) = temp;
            
            }
        }
    }
}

//nurse class
//--------------------------------------------------------------


void Nurse::MedInventory() const {};

void Nurse::seePatients() const {}; //based of prioritization function

void Nurse::addPatient(Patient*) const {};





//doctor class
//--------------------------------------------------------------

void Doctor::MedInventory() const {};

void Doctor::seePatients() const {};  //based of prioritization function

void Doctor::addShortTerm_Patient(Patient*) const {};

void Doctor::addLongTerm_Patient(Patient*) const {};

void Doctor::dismissLongTerm_Patient(LongTerm_Patient*) const {};

void Doctor::dismissShortTerm_Patient(ShortTerm_Patient*) const {};