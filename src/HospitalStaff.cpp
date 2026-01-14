#include "../include/HospitalStaff.hpp"





//nurse class
//--------------------------------------------------------------


void Nurse::MedInventory() const {};

void Nurse::seePatients() const {};

void Nurse::addPatient(Patient*) const {};





//doctor class
//--------------------------------------------------------------

void Doctor::MedInventory() const {};

void Doctor::seePatients() const {};

void Doctor::addShortTerm_Patient(Patient*) const {};

void Doctor::addLongTerm_Patient(Patient*) const {};

void Doctor::dismissLongTerm_Patient(LongTerm_Patient*) const {};

void Doctor::dismissShortTerm_Patient(ShortTerm_Patient*) const {};