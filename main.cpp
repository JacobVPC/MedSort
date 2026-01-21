//CS12 Culminating project
// Jacob, Memphis, Cody
/*MedSort main program, this program allows hospital staff to manage
patients based on priority level and helps doctors and nurses organize their patients
into long-term and short-term patients while being able to track inventory for giving
perscriptions simpler*/

//the cycle of patients is, 
// 1. nurse adds patient to general patient vector
// 2. doctor assigns them to either short-term or long-term patients after looking through persciption menu to perscribe them.



#include "include/HospitalData.hpp"
#include "include/HospitalStaff.hpp"
#include "include/Patient.hpp"
#include "include/Prescriptions.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <limits>


std::vector<Prescription> prescriptionVector;

int main(){
    if(PrescriptionFileCheck() == false){
        FillPrescriptionVector(prescriptionVector);
        AllPrescriptionToFile(prescriptionVector);
    }
    if(PrescriptionFileCheck() == true){
        std::cout << "Loading prescriptions from file...\n";
        FileToPrescription(prescriptionVector);
    }

    //filler patients for testing
    Patient* p1 = new Patient(30, "John Doe", 2, "Flu");
    Patient* p2  = new Patient(45, "Jane Smith", 1, "Chest Pain");
    Patient* p3  = new Patient(18, "Alex Brown", 4, "Sprained Ankle");
    Patient* p4  = new Patient(67, "Maria Lopez", 2, "Pneumonia");
    Patient* p5  = new Patient(52, "Robert King", 3, "High Blood Pressure");
    Patient* p6  = new Patient(8,  "Emily Clark", 5, "Fever");
    Patient* p7  = new Patient(39, "David Wilson", 1, "Severe Allergic Reaction");
    Patient* p8  = new Patient(26, "Sarah Miller", 4, "Migraine");
    ShortTerm_Patient* p9  = new ShortTerm_Patient(73, "George Thompson", 2, "Shortness of Breath","11/28/2024","albuterol");
    LongTerm_Patient* p10 = new LongTerm_Patient(34, "Olivia Martin", 3, "Stomach Pain","12/01/2024","2 weeks","antacid");

    Patients.push_back(p1);
    Patients.push_back(p2);
    Patients.push_back(p3);
    Patients.push_back(p4);
    Patients.push_back(p5);
    Patients.push_back(p6);
    Patients.push_back(p7);
    Patients.push_back(p8);
    ShortTerm_Patients.push_back(p9);
    LongTerm_Patients.push_back(p10);





    bool NurseBool = false;
    bool DoctorBool = false;
    std::cout << "Welcome to MedSort!\n";
    std::string input;
    std::cout << "password to continue (exit to leave): ";


    //password enter loop
    while (input != "exit" && input != "nurse" && input != "doctor") {
    
    
        std::getline(std::cin, input);
        if (input == "nurse") {
            Nurse nurse;
            NurseBool = true;
            std::cout << "Nurse logged in.\n";
            
        } else if (input == "doctor") {
            Doctor doctor;
            DoctorBool = true;
            std::cout << "Doctor logged in.\n";

        } else if (input == "exit") {
            std::cout << "Exiting program.\n";
            return 0;

        } else {
            std::cout << "incorrect password, try again: ";
        }
        
    }

    //nurse menu
    while (NurseBool == true) {
        std::cout << "\nNurse Menu:\n1. Add Patient\n2. See Patients\n3. Go to persciption menu\n4. Logout\nEnter choice: ";
        std::getline(std::cin, input);
        if (input == "1") {
            Nurse nurse;
            nurse.addPatient();
        } else if (input == "2") {
            Nurse nurse;
            nurse.seePatients(Patients);
        } else if (input == "3") {
            PrescriptionMenu(prescriptionVector);
        }else if (input == "4") {
            NurseBool = false;
            std::cout << "Nurse logged out.\n";
        } else {
            std::cout << "Invalid choice, try again.\n";
        }
    }

    //doctor menu
    while (DoctorBool == true) {
        std::cout << "\ndoctor Menu:\n1. See Patients\n2. See All Patients\n3. Add Short-Term Patient\n4. Add Long-Term Patient\n5. Dismiss Short-Term Patient\n6. Dismiss Long-Term Patient\n7. Go to persciption menu\n8. Logout\nEnter choice: ";
        std::getline(std::cin, input);
        int choice;
        if (input == "1") {  //see general patients only
            Doctor doctor;
            doctor.seePatients(Patients);

        } else if (input == "2") { //see all patients
            Doctor doctor;
            doctor.seeAllPatients();

        } else if (input == "3") { //add short term patient
            Doctor doctor;
            //will need to pass a patient pointer here from patient vector as index
            std::cout << "Enter the index of the patient to assign as short-term: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
            doctor.addShortTerm_Patient(Patients.at(choice));

        } else if (input == "4") { //add long term patient
            Doctor doctor;
            //will need to pass a patient pointer here from patient vector as index
            std::cout << "Enter the index of the patient to assign as long-term: "; 
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
            doctor.addLongTerm_Patient(Patients.at(choice));

        } else if (input == "5") { //dismiss short term patient
            Doctor doctor;
            //will need to pass a short term patient pointer here from short term patient vector
            std::cout << "Enter the index of the short-term patient to dismiss: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
            doctor.dismissShortTerm_Patient(ShortTerm_Patients.at(choice));

        } else if (input == "6") { //dismiss long term patient
            Doctor doctor;
            //will need to pass a long term patient pointer here from long term patient vector
            std::cout << "Enter the index of the long-term patient to dismiss: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
            doctor.dismissLongTerm_Patient(LongTerm_Patients.at(choice));

        } else if (input == "7") { //persciption menu
            PrescriptionMenu(prescriptionVector);

        } else if (input == "8") { //logout
            DoctorBool = false;
            std::cout << "Doctor logged out.\n";

        } else {
            std::cout << "Invalid choice, try again.\n";
        }
     
    }
    return 0;
}
