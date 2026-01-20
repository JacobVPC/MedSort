#ifndef DATASTORE_HPP
#define DATASTORE_HPP

#include <vector>
#include "Patient.hpp"


extern std::vector<Patient*> Patients;
extern std::vector<ShortTerm_Patient*> ShortTerm_Patients;
extern std::vector<LongTerm_Patient*> LongTerm_Patients;


#endif