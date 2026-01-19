//CS12 Culminating project
// Jacob, Memphis, Cody
/*MedSort main program, this program allows hospital staff to manage
patients based on priority level and helps doctors and nurses organize their patients
into long-term and short-term patients while being able to track inventory for giving
perscriptions simpler*/

//the cycle of patients is, 
// 1. nurse adds patient to general patient vector
// 2. doctor assigns them to either short-term or long-term patients


#include "include/Patient.hpp"
#include "include/HospitalData.hpp"
#include "include/HospitalStaff.hpp"
#include "include/Prescriptions.hpp"
#include <iostream>

std::vector<prescription> prescriptionVector;

int main(){
    Patients.push_back(new Patient(17,"memphis",3));
    Patients.push_back(new Patient(17,"jacob",1));
    Patients.push_back(new Patient(18,"Cody",1));

    std::cout << *Patients.at(0);
    std::cout << *Patients.at(1);
    std::cout << *Patients.at(2);
    PrioritizePatients(Patients);
    std::cout << Patients.at(0)->getPriority();
    std::cout << Patients.at(1)->getPriority();
    std::cout << Patients.at(2)->getPriority();

    std::cout << *Patients.at(0);

    // testing prescrti[tions

    // std::cout << "\n\nPrescription Code\n----------------------\n\n";
    // FillPrescriptionVector();
    // AllPrescriptionToFile(prescriptionVector);
    // AutomaticPrescription("headache", prescriptionVector);
}
