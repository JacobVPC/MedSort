//CS12 Culminating project
// MedSort main function
// Jacob, Memphis, Cody
#include "include/Patient.hpp"
#include <iostream>


int main(){
    Patient memphis(17,"memphis",3);
    ShortTerm_Patient jacob(17,"jacob",1, "12:54pm", "advil");
    LongTerm_Patient Cody(18,"Cody",1,"3:31pm","14 weeks", "melatonin");

    std::cout << memphis;
    std::cout << jacob;
    std::cout << Cody;
    

}