#include <fstream> // Needed for file input/output
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/// prescription File Format
    //Name
    //Stock
    //Treatmnt
/// IMPORTANT NOTICE
    //

class Prescription {
private:
    // Variables
    std::string Treatment;
    std::string Name;
public:
    int Stock;
    // constructor
    Prescription(std::string Name, std::string Treatment, int Stock);

    int GetStock()const;

    std::string GetName()const;

    std::string GetTreatment()const;

    std::string prescriptionToString()const;

    std::string prescriptionToFile()const;
};


std::ostream& operator<<(std::ostream& stream, const Prescription& P);


void AllPrescriptionToFile(std::vector<Prescription> vec);

Prescription& NameToPrescription(std::string Name, std::vector<Prescription>& vec);

Prescription& ManualPrescription(std::string Name,/*/Diognosis/*/ std::vector<Prescription>& vec);

//Automatic Prescription finder
Prescription& AutomaticPrescription(std::string Target,/*/Diognosis/*/ std::vector<Prescription>& vec);

void FillPrescriptionVector(std::vector<Prescription>&);
