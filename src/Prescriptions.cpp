#include <fstream> // Needed for file input/output
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include <limits>


#include "../include/Prescriptions.hpp"

/// prescription File Format
    //Name
    //Treatment
    //Stock
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
    return "\n\n" + Name + "\n\nTeatment = " + Treatment + "\n\nStock = " + std::to_string(Stock) + "";
}
// Alows for easy Inputing into file
std::string Prescription::prescriptionToFile()const{
    return Name + "\n" + Treatment + "\n" + std::to_string(Stock) + "\n";
}







//===========================================






// Overlaods the "<<" Operator for easy printing
std::ostream& operator<<(std::ostream& stream, const Prescription& P) {
    stream << P.prescriptionToString();
    return stream;
};

//----------------------------------------------------------------------------

// Prints all Prescriptions to a file with one function
void AllPrescriptionToFile(std::vector<Prescription> vec){
    std::ofstream outFile;
    outFile.open("data/prescriptions.txt");
    for(int i=0; i<vec.size(); i=i+1){
        outFile << vec[i].prescriptionToFile();
    }
    outFile.close();
};

//----------------------------------------------------------------------------

// FILE TO VECTOR
std::vector<Prescription> FileToPrescription(std::vector<Prescription>& vec){
    int temp = 0;
    std::string line;
    std::string temp_name;
    std::string temp_treatment;
    int temp_stock;
    std::ifstream inFile;
    inFile.open("data/prescriptions.txt");
    if (!inFile.is_open()) {
        std::cout << "Could not open file!\n";
    }
    else{
        while (std::getline(inFile, line)) {
            if(temp == 0){
                temp_name = line;
                temp=temp+1;
            }
            else if (temp == 1){
                temp_treatment = line;
                temp=temp+1;
            }
            else if (temp == 2){
                temp_stock = std::stoi(line);
                temp = 0;
                vec.push_back(Prescription(temp_name, temp_treatment, temp_stock));
            }
        }
    }
    inFile.close();
    return vec;
}

//----------------------------------------------------------------------------

/// If prescriptions.txt is there, save prescriptionvector from the file. If not, make it
bool PrescriptionFileCheck() {
    std::ifstream inFile;
    inFile.open("data/prescriptions.txt");
    if (!inFile.is_open()) {
        return false;
    }
    inFile.close();
    return true;
}

//----------------------------------------------------------------------------

/// A Fuction that finds the Prescription based off only a input of the Name
Prescription& NameToPrescription(std::string Name, std::vector<Prescription>& vec){
    for(int i=0; i<vec.size(); i=i+1){
        if(vec[i].GetName() == Name){
            return vec[i];
        }
    }
    std::cout << "\n\nSorry, No Prescription of that name was found.";
    return vec[0];
};

//----------------------------------------------------------------------------

// Manual prescripton finder
Prescription& ManualPrescription(std::string Name,/*/Diognosis/*/ std::vector<Prescription>& vec){
    bool check = false;
    for(int i=0; i<vec.size(); i=i+1){
        if(vec[i].GetName() == Name){
            if(vec[i].Stock <= 0){
                std::cout << "\n\nThis item is not in stock.";
                check = true;
            }
            else{
                vec[i].Stock -= 1;
                std::cout << "\n\nPrescription found : " << vec[i].GetName() << ", There is now " << vec[i].Stock << " left in stock.";
                AllPrescriptionToFile(vec);
                return vec[i];
            }
        }
    }
    if (check == false){
        std::cout << "This item does not exsist in our database";
    }
    return vec[0];
}

//----------------------------------------------------------------------------

//Automatic prescription finder
Prescription& AutomaticPrescription(std::string Target,/*/Diognosis/*/ std::vector<Prescription>& vec){
    bool check = false;
    std::string ans;
    std::string Temp_Name;
    std::string Temp_Stock;
    std::string Temp_Treatment;
    for(int i=0; i<vec.size(); i=i+1){
        if (vec[i].GetTreatment() == Target){
            if (vec[i].Stock <= 0){
                std::cout << "\n\nThe Prescription is out of stock";
                check = true;
            }
            else{
                std::cout << "\n\nPrescripton found : " << vec[i].GetName() << ". Would you like to prescribe this to the paitent? (1=yes, 2=no)\n--> ";
                std::cin >> ans;
                if(ans=="1"){
                    vec[i].Stock -= 1;
                    std::cout << "\n\nOK, there is now " << vec[i].GetStock() << " " << vec[i].GetName() << " left in stock.";
                    AllPrescriptionToFile(vec);
                    return vec[i];
                }
                if (ans == "2"){
                    std::cout << "\nOk.";
                    check = true;
                }
            }
        }
    }
    if(check == false){
        std::cout << "\n\nThere is no prescription in the database for this illness";
    }
    return vec[0];
}

//----------------------------------------------------------------------------

//Display all avaliable prescriptions
Prescription& ListAndPerscribePrescription(std::vector<Prescription>& vec){
    std::string ans;
    std::cout << "\n";
    for(int i=0; i<vec.size(); i=i+1){
        std::cout << i << ") Name : " << vec[i].GetName() << "      Treatment : " << vec[i].GetTreatment() << "        Stock : " << vec[i].GetStock() << "\n";
    }
    std::cout << "\nSelecet the number of the prescription you would like to prescribe (or -999 if you want none)\n-->";
    std::cin >> ans;

    if (ans == "-999") {
        return vec[0];
    }

    int index;
    try {
        index = std::stoi(ans);
    } catch (...) {
        std::cout << "Not a valid input.\n";
        return vec[0];
    }

    if (index < 0 || index >= vec.size()) {
        std::cout << "Not a valid input.\n";
        return vec[0];
    }

    if (vec[index].GetStock() <= 0) {
        std::cout << "\n\nThis item is not in stock.";
        return vec[0];
    }

    vec[index].Stock -= 1;
    std::cout << "\n\nOK, there is now " << vec[index].GetStock()
            << " " << vec[index].GetName() << " left in stock.\n";

    AllPrescriptionToFile(vec);
    return vec[index];
}

void FillPrescriptionVector(std::vector<Prescription> &prescriptionVector) {
    
    prescriptionVector.push_back(Prescription("NA", "NA", 2000000000));
    prescriptionVector.push_back(Prescription("aspirin", "headaches", 10));
    prescriptionVector.push_back(Prescription("ibuprofen", "inflammation", 15));
    prescriptionVector.push_back(Prescription("paracetamol", "fever", 20));
    prescriptionVector.push_back(Prescription("amoxicillin", "infection", 8));
    prescriptionVector.push_back(Prescription("cough syrup", "cough", 12));
    prescriptionVector.push_back(Prescription("loratadine", "allergies", 18));
    prescriptionVector.push_back(Prescription("omeprazole", "reflux", 7));
    prescriptionVector.push_back(Prescription("metformin", "diabetes", 9));
    prescriptionVector.push_back(Prescription("atorvastatin", "cholesterol", 14));

    
    prescriptionVector.push_back(Prescription("oseltamivir", "flu", 10));  
    prescriptionVector.push_back(Prescription("nitroglycerin", "chest pain", 5));  
    prescriptionVector.push_back(Prescription("ice pack", "sprained ankle", 30));  
    prescriptionVector.push_back(Prescription("azithromycin", "pneumonia", 7));  
    prescriptionVector.push_back(Prescription("lisinopril", "high blood pressure", 12));  
    prescriptionVector.push_back(Prescription("acetaminophen", "fever", 15)); 
    prescriptionVector.push_back(Prescription("epinephrine", "severe allergic reaction", 1));  
    prescriptionVector.push_back(Prescription("sumatriptan", "migraine", 8));  
    prescriptionVector.push_back(Prescription("albuterol", "shortness of breath", 10));  
    prescriptionVector.push_back(Prescription("antacid", "stomach pain", 20));  
}


Prescription PrescriptionMenu (std::vector<Prescription>& vec){
    std::string ans;
    int check = 0;
    Prescription temp_prescription = vec[0];
    while (check == 0){
        std::cout << "\n\nWhat would you like to do?\n\n1) prescribe automatic prescription based on illness\n2) prescribe manually with the name of the prescription\n3) List all prescriptions avalable, and prescribe form the list\n4) Return\n\nintput corisponding number -->";
        std::getline(std::cin, ans);
        if (ans == "1"){
            std::cout << "\n\nInput the name of the sickness the patient has\n-->";
            std::getline(std::cin, ans);
            temp_prescription = AutomaticPrescription(ans, vec);
            check = 1;
        }
        else if (ans == "2"){
            std::cout << "\n\nInput the name of the prescription you would like to perscribe\n-->";
            std::cin >> ans;
            temp_prescription = ManualPrescription(ans,vec);
            check = 1;
        }
        else if (ans == "3"){
            temp_prescription = ListAndPerscribePrescription(vec);
            check = 1;
        }
        else if (ans == "4"){
            check = 1;
        }
        else {
            std::cout << "\n\nInvalid input, please try again";
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return temp_prescription;
}
