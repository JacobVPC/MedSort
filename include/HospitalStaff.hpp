#include "../include/Patient.hpp"


//base class
//--------------------------------------------------------------

class HospitalStaff{

public:
//all methods will pure virtual because to make base class abstract

virtual void MedInventory() const = 0; 
virtual void seePatients() const = 0;

};



//nurse class
//--------------------------------------------------------------

class Nurse : public HospitalStaff{

public:

void MedInventory() const override;

void seePatients() const override;

void addPatient(Patient*) const;

};



//doctor class
//--------------------------------------------------------------

class Doctor : public HospitalStaff{

public:

void MedInventory() const override;

void seePatients() const override;

void addShortTerm_Patient(Patient*) const;
void addLongTerm_Patient(Patient*) const;

void dismissLongTerm_Patient(LongTerm_Patient*) const;
void dismissShortTerm_Patient(ShortTerm_Patient*) const;

};


