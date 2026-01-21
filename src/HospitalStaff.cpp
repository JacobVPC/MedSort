#include "../include/HospitalStaff.hpp"
#include "../include/HospitalData.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>



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


//HospitalStaff base class
void HospitalStaff::seePatients(std::vector<Patient*>& vec) const { //based of prioritization function
    std::cout<< "Showing patients in order of priority: \n";
    PrioritizePatients(vec);
    for (int i = 0; i < vec.size(); i++) {
        std::cout <<"\n index:" << i << "." <<*vec.at(i);
    }


};  



void HospitalStaff::MedInventory() const {
    //memphis will fill this in later with file code
};

//nurse class
//--------------------------------------------------------------

//also has see patients from base class 
//also has med inventory from base class

void Nurse::addPatient() const {
    std::string name;
    int age;
    int priority;
    std::string sickness;

    std::cout << "Enter patient name: ";
    std::getline(std::cin, name);

    std::cout << "Enter patient age: ";
    std::cin >> age;

    std::cout << "Enter patient priority (1-5): ";
    std::cin >> priority;
    

    std::cout << "Enter patient sickness: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //to ignroe newlnine
    std::getline(std::cin, sickness);

    // Create a new patient and add it to the vector
    Patient* newPatient = new Patient(age, name, priority,sickness);
    Patients.push_back(newPatient);
    std::cout << "Patient added: " << *newPatient << "\n";

};





//doctor class
//--------------------------------------------------------------

//also has see patients from base class 
//also has med inventory from base class
void Doctor::seeAllPatients() const {
    std::cout << "\nGeneral Patients:\n";
    seePatients(Patients);
    
    std::cout << "\nShort-Term Patients:\n";
    for (int i = 0; i < ShortTerm_Patients.size(); i++) {
        std::cout <<"\n index:" << i << "." << *ShortTerm_Patients.at(i);
    }
    std::cout << "\nLong-Term Patients:\n";
    for (int i = 0; i < LongTerm_Patients.size(); i++) {
        std::cout <<"\n index:" << i << "." << *LongTerm_Patients.at(i);
    }

};

void Doctor::addShortTerm_Patient(Patient* p) const {
    //adds a short term patient from patient vector

    std::string timeAssessed;
    std::string perscription;
    std::cout << "Enter time assessed: ";
    std::getline(std::cin, timeAssessed);
    std::cout << "Enter perscription: ";
    std::getline(std::cin, perscription);


    // Create a new short term patient and add it to the vector and remove from patient vector
    ShortTerm_Patient* newShortTermPatient = new ShortTerm_Patient(p->getAge(), p->getName(), p->getPriority(), p->getSickness(), timeAssessed, perscription);
    ShortTerm_Patients.push_back(newShortTermPatient);

    // Remove from general Patients vector
    auto it = std::find(Patients.begin(), Patients.end(), p);
    if (it != Patients.end()) {
        Patients.erase(it);
    }
};



void Doctor::addLongTerm_Patient(Patient* p) const {
    //adds a long term patient from patient vector
    std::string timeAssessed;
    std::string TimeNeeded;
    std::string perscription;

    std::cout << "Enter time assessed: ";
    std::getline(std::cin, timeAssessed);

    std::cout << "Enter time needed: ";
    std::getline(std::cin, TimeNeeded);

    std::cout << "Enter perscription: ";
    std::getline(std::cin, perscription);


    // makes a new longterm patient to add to new vector
    LongTerm_Patient* newLongTermPatient = new LongTerm_Patient(p->getAge(), p->getName(), p->getPriority(), p->getSickness(), timeAssessed, TimeNeeded, perscription);
    LongTerm_Patients.push_back(newLongTermPatient);

    // Remove from Patients vector
    auto it = std::find(Patients.begin(), Patients.end(), p);
    if (it != Patients.end()) {
        Patients.erase(it);
    }
};



void Doctor::dismissLongTerm_Patient(LongTerm_Patient* Patient) const {
    //removes a long term patient from long term vector

    auto it = std::find(LongTerm_Patients.begin(), LongTerm_Patients.end(), Patient);
    if (it != LongTerm_Patients.end()) {
        LongTerm_Patients.erase(it);
    }
};



void Doctor::dismissShortTerm_Patient(ShortTerm_Patient* Patient) const {
    //removes a short term patient from short term vector

    auto it = std::find(ShortTerm_Patients.begin(), ShortTerm_Patients.end(), Patient);
    if (it != ShortTerm_Patients.end()) {
        ShortTerm_Patients.erase(it);
    }
};