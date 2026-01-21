#ifndef HOSPITALSTAFF_HPP
#define HOSPITALSTAFF_HPP
#include "../include/Patient.hpp"
#include <vector>


//base class
//--------------------------------------------------------------

class HospitalStaff{

public:
//all methods will pure virtual because to make base class abstract

void MedInventory() const; //file
void seePatients(std::vector<Patient*>& vec) const; //prioritization is also being done here

};



//nurse class
//--------------------------------------------------------------

class Nurse : public HospitalStaff{

public:

double sumPriorities(const std::vector<Patient*>& patients, int i) const; //i is index and it wil be 0
void averagePriority(const std::vector<Patient*>& patients) const;

void addPatient() const;

};



//doctor class
//--------------------------------------------------------------

class Doctor : public HospitalStaff{

public:

void seeAllPatients() const; //sees all patients in all vectors

void addShortTerm_Patient(Patient* p) const;
void addLongTerm_Patient(Patient* p) const;

void dismissLongTerm_Patient(LongTerm_Patient* Patient) const;
void dismissShortTerm_Patient(ShortTerm_Patient* Patient) const;
};


void PrioritizePatients(std::vector<Patient*>& vec);
#endif