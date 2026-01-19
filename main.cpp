//CS12 Culminating project
// MedSort main function
// Jacob, Memphis, Cody
#include "include/Patient.hpp"
#include "include/HospitalData.hpp"
#include "include/HospitalStaff.hpp"
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
