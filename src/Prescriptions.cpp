#include <fstream> // Needed for file input/output
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../include/Prescriptions.hpp"

/// prescription File Format
    //Name
    //Stock
    //Treatmnt
/// IMPORTANT NOTICE
    //


// constructor
Prescription::Prescription(std::string Name, std::string Treatment, int Stock) : Name(Name) , Treatment(Treatment) , Stock(Stock){};
// returns the amount in stock
int Prescription::GetStock()const{
    return Stock;
}
// Returns the Name of the poscripton
std::string Prescription::GetName()const{
    return Name;
}
// Returns the Treatment (diagnosis) that the Prescription can help
std::string Prescription::GetTreatment()const{
    return Treatment;
}
// Allows for easy printing of Prescriptiones
std::string Prescription::prescriptionToString()const{
    return "\n\n----------------------\n\n" + Name + "\n\nTeatment = " + Treatment + "\n\nStock = " + std::to_string(Stock) + "\n\n----------------------";
}
// Alows for easy Inputing into file
std::string Prescription::prescriptionToFile()const{
    return Name + "\n" + std::to_string(Stock) + "\n" + Treatment + "\n";
}


// Overlaods the "<<" Operator for easy printing
std::ostream& operator<<(std::ostream& stream, const Prescription& P) {
    stream << P.prescriptionToString();
    return stream;
};


// Prints all Prescriptions to a file with one function
void AllPrescriptionToFile(std::vector<Prescription> vec){
    std::ofstream outFile;
    outFile.open("prescriptions.txt");
    for(int i=0; i<vec.size(); i=i+1){
        outFile << vec[i].prescriptionToFile();
    }
    outFile.close();
};


/// A Fuction that finds the Prescription based off only a input of the Name
Prescription& NameToPrescription(std::string Name, std::vector<Prescription>& vec){
    for(int i=0; i<vec.size(); i=i+1){
        if(vec[i].GetName() == Name){
            return vec[i];
        }
    }
    std::cout << "\n\nSorry, No Prescription of that name was found.";
};


// Manual prescripton finder
Prescription& ManualPrescription(std::string Name,/*/Diognosis/*/ std::vector<Prescription>& vec){
    bool check = false;
    std::cout << "\n\n----------------------";
    for(int i=0; i<vec.size(); i=i+1){
        if(vec[i].GetName() == Name){
            if(vec[i].Stock <= 0){
                std::cout << "\n\nThis item is not in stock.";
                check = true;
            }
            else{
                vec[i].Stock -= 1;
                AllPrescriptionToFile(vec);
                std::cout << "\n\nPrescription found : " << vec[i].GetName() << ", There is now " << vec[i].Stock << " left in stock.\n\n----------------------";
                return vec[i];
            }
        }
    }
    if (check == false){
        std::cout << "This item does not exsist in our database\n\n----------------------";
    }
}

//Automatic prescription finder
Prescription& AutomaticPrescription(std::string Target,/*/Diognosis/*/ std::vector<Prescription>& vec){
    bool check = false;
    std::string ans;
    std::string Temp_Name;
    std::string Temp_Stock;
    std::string Temp_Treatment;
    std::cout << "\n\n----------------------";
    for(int i=0; i<vec.size(); i=i+1){
        if (vec[i].GetTreatment() == Target){
            if (vec[i].Stock <= 0){
                std::cout << "The Prescription is out of stock\n\n----------------------";
                check = true;
            }
            else{
                std::cout << "\n\nPrescripton found : " << vec[i].GetName() << ". Would you like to prescribe this to the paitent? (1=yes, 2=no)\n--> ";
                std::cin >> ans;
                if(ans=="1"){
                    vec[i].Stock -= 1;
                    AllPrescriptionToFile(vec);
                    std::cout << "\n\nOK, there is now " << vec[i].GetStock() << " " << vec[i].GetName() << " left in stock.\n\n----------------------";
                    return vec[i];
                }
                if (ans == "2"){
                    std::cout << "\nOk.\n\n----------------------";
                    check = true;
                }
            }
        }
    }
    if(check == false){
        std::cout << "\n\nThere is no prescription in the database for this illness\n\n----------------------";
    }
}


void FillPrescriptionVector(std::vector<Prescription> &prescriptionVector) {
    
    prescriptionVector.push_back(Prescription("aspirin", "headache", 10));
    prescriptionVector.push_back(Prescription("ibuprofen", "pain", 15));
    prescriptionVector.push_back(Prescription("paracetamol", "fever", 20));
    prescriptionVector.push_back(Prescription("amoxicillin", "infection", 8));
    prescriptionVector.push_back(Prescription("cough syrup", "cough", 12));
    prescriptionVector.push_back(Prescription("loratadine", "allergy", 18));
    prescriptionVector.push_back(Prescription("omeprazole", "acid reflux", 7));
    prescriptionVector.push_back(Prescription("metformin", "diabetes", 9));
    prescriptionVector.push_back(Prescription("atorvastatin", "cholesterol", 14));
    prescriptionVector.push_back(Prescription("vitamin c", "immune support", 25));
}


// int main (){
//     FillPrescriptionVector();
//     AllPrescriptionToFile(prescriptionVector);
//     AutomaticPrescription("headache", prescriptionVector);
// }
