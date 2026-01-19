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

prescription::prescription{
private:
    // Variables
    std::string Treatment;
    std::string Name;
public:
    int Stock;
    // constructor
    prescription(std::string Name, std::string Treatment, int Stock) : Name(Name) , Treatment(Treatment) , Stock(Stock){};
    // returns the amount in stock
    int prescription::GetStock()const{
        return Stock;
    }
    // Returns the Name of the poscripton
    std::string prescription::GetName()const{
        return Name;
    }
    // Returns the Treatment (diagnosis) that the Prescription can help
    std::string prescription::GetTreatment()const{
        return Treatment;
    }
    // Allows for easy printing of Prescriptiones
    std::string prescription::prescriptionToString()const{
        return "\n\n----------------------\n\n" + Name + "\n\nTeatment = " + Treatment + "\n\nStock = " + std::to_string(Stock) + "\n\n----------------------";
    }
    // Alows for easy Inputing into file
    std::string prescription::prescriptionToFile()const{
        return Name + "\n" + std::to_string(Stock) + "\n" + Treatment + "\n";
    }
};


// Overlaods the "<<" Operator for easy printing
std::ostream& operator<<(std::ostream& stream, const prescription& P) {
    stream << P.prescriptionToString();
    return stream;
};


// Prints all Prescriptions to a file with one function
void AllPrescriptionToFile(std::vector<prescription> vec){
    std::ofstream outFile;
    outFile.open("prescriptions.txt");
    for(int i=0; i<vec.size(); i=i+1){
        outFile << vec[i].prescriptionToFile();
    }
    outFile.close();
};


/// A Fuction that finds the Prescription based off only a input of the Name
prescription& NameToPrescription(std::string Name, std::vector<prescription>& vec){
    for(int i=0; i<vec.size(); i=i+1){
        if(vec[i].GetName() == Name){
            return vec[i];
        }
    }
    std::cout << "\n\nSorry, No Prescription of that name was found.";
};


// Manual prescripton finder
prescription& ManualPrescription(std::string Name,/*/Diognosis/*/ std::vector<prescription>& vec){
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
prescription& AutomaticPrescription(std::string Target,/*/Diognosis/*/ std::vector<prescription>& vec){
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


void FillPrescriptionVector() {
    prescriptionVector.push_back(prescription("aspirin", "headache", 10));
    prescriptionVector.push_back(prescription("ibuprofen", "pain", 15));
    prescriptionVector.push_back(prescription("paracetamol", "fever", 20));
    prescriptionVector.push_back(prescription("amoxicillin", "infection", 8));
    prescriptionVector.push_back(prescription("cough syrup", "cough", 12));
    prescriptionVector.push_back(prescription("loratadine", "allergy", 18));
    prescriptionVector.push_back(prescription("omeprazole", "acid reflux", 7));
    prescriptionVector.push_back(prescription("metformin", "diabetes", 9));
    prescriptionVector.push_back(prescription("atorvastatin", "cholesterol", 14));
    prescriptionVector.push_back(prescription("vitamin c", "immune support", 25));
}


int main (){
    FillPrescriptionVector();
    AllPrescriptionToFile(prescriptionVector);
    AutomaticPrescription("headache", prescriptionVector);
}
