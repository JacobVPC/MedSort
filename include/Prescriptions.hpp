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

class prescription{
private:
    // Variables
    std::string Treatment;
    std::string Name;
public:
    int Stock;
    // constructor
    prescription(std::string Name, std::string Treatment, int Stock);

    int GetStock()const;

    std::string GetName()const;

    std::string GetTreatment()const;

    std::string prescriptionToString()const;

    std::string prescriptionToFile()const;
};


std::ostream& operator<<(std::ostream& stream, const prescription& P);


void AllPrescriptionToFile(std::vector<prescription> vec);

prescription& NameToPrescription(std::string Name, std::vector<prescription>& vec);

prescription& ManualPrescription(std::string Name,/*/Diognosis/*/ std::vector<prescription>& vec);

//Automatic prescription finder
prescription& AutomaticPrescription(std::string Target,/*/Diognosis/*/ std::vector<prescription>& vec);

void FillPrescriptionVector();
