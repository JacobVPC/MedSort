//CS12 Culminating project
// Jacob, Memphis, Cody
/*MedSort main program, this program allows hospital staff to manage
patients based on priority level and helps doctors and nurses organize their patients
into long-term and short-term patients while being able to track inventory for giving
perscriptions simpler*/

//the cycle of patients is, 
// 1. nurse adds patient to general patient vector
// 2. doctor assigns them to either short-term or long-term patients after looking through persciption menu to perscribe them.


// C++ includes
#include "include/HospitalData.hpp"
#include "include/HospitalStaff.hpp"
#include "include/Patient.hpp"
#include "include/Prescriptions.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

// ftxui includes
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/dom/linear_gradient.hpp>
#include <ftxui/dom/node.hpp>


std::vector<Prescription> prescriptionVector;

/*Rendering of normal patients*/

ftxui::Element RenderPatientTable(const std::vector<Patient*>& patients) {
    using namespace ftxui;

    std::vector<std::vector<std::string>> rows;

    // Header row
    rows.push_back({
        "Index  ",
        "Age  ",
        "Name  ",
        "Priority  ",
        "Condition  ",
    });

    // Data rows
    for (size_t i = 0; i < patients.size(); ++i) {
        Patient* p = patients[i];

        rows.push_back({
            std::to_string(i),
            std::to_string(p->getAge()),
            p->getName(),
            std::to_string(p->getPriority()),
            p->getSickness()
        });
    }

    Table table(rows);

    table.SelectAll().Border(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectRow(0).Decorate(bold);

    return table.Render();
}

/*Rendering of normal patients*/

ftxui::Element RenderPatientTable_(const std::vector<Patient*>& patients) {
    using namespace ftxui;

    std::vector<std::vector<std::string>> rows;

    // Header row
    rows.push_back({
        "Index  ",
        "Age  ",
        "Name  ",
        "Priority  ",
        "Condition  ",
    });

    // Data rows
    for (size_t i = 0; i < patients.size(); ++i) {
        Patient* p = patients[i];

        rows.push_back({
            std::to_string(i),
            std::to_string(p->getAge()),
            p->getName(),
            std::to_string(p->getPriority()),
            p->getSickness()
        });
    }

    Table table(rows);

    table.SelectAll().Border(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectRow(0).Decorate(bold);

    return table.Render();
}

/*Rendering of all patients, and checks if its short term or long term to display the correct data*/

ftxui::Element RenderPatientTable_1(const std::vector<ShortTerm_Patient*>& short_terms, const std::vector<LongTerm_Patient*>& long_terms) {
    using namespace ftxui;

    std::vector<std::vector<std::string>> rows;

    rows.push_back({
        "Index ",
        "Age ",
        "Name ",
        "Priority ",
        "Condition ",
        "Time Assessed ",
        "Time Needed ",
        "Prescription ",
        "Type "
    });

    int index = 0;

    // ---- Short Term ----
    for (auto* p : short_terms) {
        rows.push_back({
            std::to_string(index++),
            std::to_string(p->getAge()),
            p->getName(),
            std::to_string(p->getPriority()),
            p->getSickness(),
            p->getTimeAssessed(),
            "N/A",
            p->getPerscription(),
            "Short Term"
        });
    }

    // ---- Long Term ----
    for (auto* p : long_terms) {
        rows.push_back({
            std::to_string(index++),
            std::to_string(p->getAge()),
            p->getName(),
            std::to_string(p->getPriority()),
            p->getSickness(),
            p->getTimeAssessed(),
            p->getTimeNeeded(),
            p->getPerscription(),
            "Long Term"
        });
    }

    Table table(rows);

    table.SelectAll().Border(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectRow(0).Decorate(bold);

    return table.Render();
}
    

int main(){
    if(PrescriptionFileCheck() == false){
        FillPrescriptionVector(prescriptionVector);
        AllPrescriptionToFile(prescriptionVector);
    }
    if(PrescriptionFileCheck() == true){
        std::cout << "Loading prescriptions from file...\n";
        FileToPrescription(prescriptionVector);
    }

    //filler patients for testing
    Patient* p1 = new Patient(30, "John Doe", 2, "Flu");
    Patient* p2  = new Patient(45, "Jane Smith", 1, "Chest Pain");
    Patient* p3  = new Patient(18, "Alex Brown", 4, "Sprained Ankle");
    Patient* p4  = new Patient(67, "Maria Lopez", 2, "Pneumonia");
    Patient* p5  = new Patient(52, "Robert King", 3, "High Blood Pressure");
    Patient* p6  = new Patient(8,  "Emily Clark", 5, "Fever");
    Patient* p7  = new Patient(39, "David Wilson", 1, "Severe Allergic Reaction");
    Patient* p8  = new Patient(26, "Sarah Miller", 4, "Migraine");
    ShortTerm_Patient* p9  = new ShortTerm_Patient(73, "George Thompson", 2, "Shortness of Breath","11/28/2024","albuterol");
    LongTerm_Patient* p10 = new LongTerm_Patient(34, "Olivia Martin", 3, "Stomach Pain","12/01/2024","2 weeks","antacid");

    Patients.push_back(p1);
    Patients.push_back(p2);
    Patients.push_back(p3);
    Patients.push_back(p4);
    Patients.push_back(p5);
    Patients.push_back(p6);
    Patients.push_back(p7);
    Patients.push_back(p8);
    ShortTerm_Patients.push_back(p9);
    LongTerm_Patients.push_back(p10);

    Nurse nurse;
    Doctor doctor;



    // bool NurseBool = false;
    // bool DoctorBool = false;
    // std::cout << "Welcome to MedSort!\n";
    // std::string input;
    // std::cout << "password to continue (exit to leave): ";


    // //password enter loop
    // while (input != "exit" && input != "nurse" && input != "doctor") {
    
    
    //     std::getline(std::cin, input);
    //     if (input == "nurse") {
    //         NurseBool = true;
    //         std::cout << "Nurse logged in.\n";
            
    //     } else if (input == "doctor") {
    //         DoctorBool = true;
    //         std::cout << "Doctor logged in.\n";

    //     } else if (input == "exit") {
    //         std::cout << "Exiting program.\n";
    //         return 0;

    //     } else {
    //         std::cout << "incorrect password, try again: ";
    //     }
        
    // }


    // //nurse menu
    // while (NurseBool == true) {
    //     std::cout << "\nNurse Menu:\n1. Add Patient\n2. See Patients\n3. Go to persciption menu\n4. Average Priority\n5. Logout\nEnter choice: ";
    //     std::getline(std::cin, input);
    //     if (input == "1") {
    //         nurse.addPatient();

    //     } else if (input == "2") {
    //         nurse.seePatients(Patients);

    //     } else if (input == "3") {
    //         PrescriptionMenu(prescriptionVector);

    //     } else if (input == "4") {
    //         nurse.averagePriority(Patients);

    //     }else if (input == "5") {
    //         NurseBool = false;
    //         std::cout << "Nurse logged out.\n";

    //     } else {
    //         std::cout << "Invalid choice, try again.\n";
    //     }
    // }

    // //doctor menu
    // while (DoctorBool == true) {
    //     std::cout << "\ndoctor Menu:\n1. See Patients\n2. See All Patients\n3. Add Short-Term Patient\n4. Add Long-Term Patient\n5. Dismiss Short-Term Patient\n6. Dismiss Long-Term Patient\n7. Go to persciption menu\n8. Logout\nEnter choice: ";
    //     std::getline(std::cin, input);
    //     int choice;
    //     if (input == "1") {  //see general patients only
    //         doctor.seePatients(Patients);

    //     } else if (input == "2") { //see all patients
    //         doctor.seeAllPatients();

    //     } else if (input == "3") { //add short term patient
    //         //will need to pass a patient pointer here from patient vector as index
    //         std::cout << "Enter the index of the patient to assign as short-term: ";
    //         std::cin >> choice;
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
    //         doctor.addShortTerm_Patient(Patients.at(choice));

    //     } else if (input == "4") { //add long term patient
    //         //will need to pass a patient pointer here from patient vector as index
    //         std::cout << "Enter the index of the patient to assign as long-term: "; 
    //         std::cin >> choice;
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
    //         doctor.addLongTerm_Patient(Patients.at(choice));

    //     } else if (input == "5") { //dismiss short term patient
    //         //will need to pass a short term patient pointer here from short term patient vector
    //         std::cout << "Enter the index of the short-term patient to dismiss: ";
    //         std::cin >> choice;
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
    //         doctor.dismissShortTerm_Patient(ShortTerm_Patients.at(choice));

    //     } else if (input == "6") { //dismiss long term patient
    //         //will need to pass a long term patient pointer here from long term patient vector
    //         std::cout << "Enter the index of the long-term patient to dismiss: ";
    //         std::cin >> choice;
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to clear input buffer
    //         doctor.dismissLongTerm_Patient(LongTerm_Patients.at(choice));

    //     } else if (input == "7") { //persciption menu
    //         PrescriptionMenu(prescriptionVector);

    //     } else if (input == "8") { //logout
    //         DoctorBool = false;
    //         std::cout << "Doctor logged out.\n";

    //     } else {
    //         std::cout << "Invalid choice, try again.\n";
    //     }
     
    // }

    using namespace ftxui;

    /*
    Terminal commands:

    This removes previous build files for changing directory of the project file:
    Remove-Item -Recurse -Force build

    ctrl + shift + P:
    CMake: Configure
    CMake: select kit

    This builds the program using CMake and writes it to the build folder:
    cmake -S . -B build
    cmake --build build

    This runs the program from the build folder:
    .\build\main.exe

    I have set up a task that builds and runs: cmake -S . -B build, cmake --build build, .\build\main.exe all at once so you dont have to do all


    I want to die - Cody
    */



    /*
    The screen Interactive renders where its gonna go Fullscreen() will always resize if the window size changes
    iv only tested with Fullscreen() and TerminalOutput() so I think the terminal output wil just render line by line for whatever your first rendering is
    */

    auto screen = ScreenInteractive::Fullscreen();

    int depth = 0; /*This is just a tracker to tell the code what depth(menu) to render, this could be any name*/

    /*
    The ButtonOption alows for smooth button switches and you can make it have color smoothing with the color pallet your going for but be carful the Animated color system
    uses a 256 pallet system and bgcolor uses a 16 color pallet (I have not experimented to much into it but im sure theres a way to change it or somthing) 
    */

    auto button_style = ButtonOption::Animated(Color::SpringGreen2, Color::GrayDark);


    

    // Name headers
    std::string Log_in = "    Log in    ";
    int Log_go = 0;
    std::string Email;
    std::string Password;
    std::string Menu_Name = "Main menu";
    std::string Add_Patient = "Add Patient";
    std::string Long_Term = "Long Term Patients";
    std::string Short_Term = "Short Term Patients";
    std::string Patient_ = "Regular Patients";
    std::string first_name;
    std::string last_name;
    std::string age;
    std::string sick;
    int priority_index = 0;

    std::string Assign = "Assess Patients";
    std::string patient_index_input = "";
    int selected_patient = 0;
    std::vector<std::string> patient_entries;
    std::string time_assessed_input = "";
    std::string time_needed_input = "";
    int selected_prescription_index = 0;
    int assignment_type = 0;
    
    Component input_patient_index = Input(&patient_index_input, "Patient Index");

    /*
    This is for the login section, it has 2 input bars, one for the "Email" and "Password" and then the code to check if its right is inside the button in between the braces
    Then it will set the depth to the correct menu

    And then the rest is for the menus and what to render the button names kinda match but if you just like on the name it will take you to the container then the container
    name will take you to the rendering

    and then theres also dropdowns
    */

    // Log in menu Buttons -- Depth 0
    Component input_Email = Input(&Email, "Email");
    Component input_Password = Input(&Password, "Password");
    auto Log_in_ = Button("Log in", [&] 
    {
        if (Email == "Doctor123" && Password == "12345")
        {
            depth = 2;
        }
        else if (Email == "Nurse123" && Password == "12345")
        {
            depth = 1;
        }
    }, button_style);
    auto Quit = Button("Quit", screen.ExitLoopClosure(), button_style);

    std::string dismiss_patient_index = "";
    Component input_dismiss_index = Input(&dismiss_patient_index, "Patient Index");

    std::string order_quantity_input_N = "";
    int selected_rx_index_N = 0;
    Component input_order_quantity_N = Input(&order_quantity_input_N, "Quantity to Order");

    std::string order_quantity_input_D = "";
    int selected_rx_index_D = 0;
    Component input_order_quantity_D = Input(&order_quantity_input_D, "Quantity to Order");


    // Triage Buttons -- Depth 1
    auto Add_Patient_ = Button("Add Patient", [&] { depth = 3;}, button_style); // Prio, age, Name
    // Sub Buttons
    Component input_first_name = Input(&first_name, "first name");
    Component input_last_name = Input(&last_name, "last name");
    Component input_age = Input(&age, "age");
    Component input_sick = Input(&sick, "sickness");
    std::vector<std::string> entries = {
        "Level 1", "Level 2", "Level 3", "Level 4", "Level 5"
    };
    auto dropdown_1prio = Dropdown({
        .radiobox = {
            .entries = &entries,
            .selected = &priority_index,
        },
        .transform =
            [](bool open, Element checkbox, Element radiobox) {
                if (open) {
                return vbox({
                    checkbox | inverted,
                    radiobox | frame | 
                        size(HEIGHT, LESS_THAN, 10),
                    filler(),
                });
                }
                return vbox({
                    checkbox,
                    filler(),
                });
            },
    });
    auto push_it_ = Button("Add Patient to system", [&] { 
                                                            if (first_name.empty() || last_name.empty() || age.empty() || sick.empty())
                                                                return;

                                                            int age_int = std::stoi(age);
                                                            int priority = priority_index + 1;

                                                            std::string full_name = first_name + " " + last_name;

                                                            Patient* pa = new Patient(age_int,full_name,priority,sick);

                                                            Patients.push_back(pa);

                                                            // Clear inputs
                                                            first_name.clear();
                                                            last_name.clear();
                                                            age.clear();
                                                            priority_index = 0;
                                                            sick.clear();
                                                            depth = 1;
                                                        }, button_style);
    auto Back_3 = Button("Back", [&] { depth = 1;}, button_style);
    // end
    auto Back_4 = Button("Back", [&] { depth = 1;}, button_style);
    auto patient_ = Button("Ragular Patients", [&] { depth = 4; Back_4->TakeFocus();}, button_style);
    // Sub Buttons
    // end
    auto Prescribe_ = Button("Prescription Menu", [&] { depth = 5;}, button_style);
    // Sub Buttons
    auto Back_5 = Button("Back", [&] { depth = 1;}, button_style);
    // end
    auto Avg_prio_ = Button("Average Priority", [&] { depth = 6; }, button_style);
    // Sub Buttons
    auto Back_6 = Button("Back", [&] { depth = 1;}, button_style);
    // end
    auto Log_out_ = Button("Log out", [&] { depth = 0; Log_go = 0;}, button_style);
    

    // Docter Buttons -- Depth 2
    auto Back_7 = Button("Back", [&] { depth = 2;}, button_style);
    auto Reg_p_ = Button("Regular Patients", [&] { depth = 7; Back_7->TakeFocus();}, button_style);
    // Sub Buttons
    // end
    auto All_p_ = Button("All Patients", [&] { depth = 8;}, button_style);
    // Sub Buttons
    auto Back_8 = Button("Back", [&] { depth = 2;}, button_style);
    // end
    auto Assign_ = Button ("Assess Patients", [&] { patient_index_input.clear(), depth = 9; input_patient_index->TakeFocus();}, button_style);
    // Sub Buttons
    // auto assign_short_ = Button("Assign as Short-Term", [&] { assignment_type = 1; depth = 10;}, button_style);
    // auto assign_long_ = Button("Assign as Long-Term", [&] { assignment_type = 2; depth = 11;}, button_style);
    
    Component input_time_assessed_short = Input(&time_assessed_input, "Date (MM/DD/YYYY)");
    Component input_time_assessed_long = Input(&time_assessed_input, "Date (MM/DD/YYYY)");
    Component input_time_needed = Input(&time_needed_input, "Duration (e.g., 2 weeks)");

    auto assign_short_ = Button("Assign as Short-Term", [&] { 
        if (patient_index_input.empty()) return;
        try {
            selected_patient = std::stoi(patient_index_input);
            if (selected_patient >= 0 && selected_patient < (int)Patients.size()) {
                assignment_type = 1;
                depth = 10;
            }
        } catch (...) {}
        input_time_assessed_short->TakeFocus();
    }, button_style);
    
    auto assign_long_ = Button("Assign as Long-Term", [&] { 
        if (patient_index_input.empty()) return;
        try {
            selected_patient = std::stoi(patient_index_input);
            if (selected_patient >= 0 && selected_patient < (int)Patients.size()) {
                assignment_type = 2;
                depth = 11;
            }
        } catch (...) {}
        input_time_assessed_long->TakeFocus();
    }, button_style);

    // Prescription entries updated dynamically
    std::vector<std::string> prescription_entries;

    auto UpdatePrescriptionEntries = [&]() {
        prescription_entries.clear();
        for (auto& p : prescriptionVector) {
            prescription_entries.push_back(p.GetName() + " | Stock: " + std::to_string(p.Stock));
        }
        if (selected_prescription_index >= (int)prescription_entries.size()) {
            selected_prescription_index = 0;
        }
    };

    // Initialize prescription entries
    UpdatePrescriptionEntries();

    auto prescription_menu = Dropdown({
        .radiobox = {
            .entries = &prescription_entries,
            .selected = &selected_prescription_index,
        },
        .transform =
            [](bool open, Element checkbox, Element radiobox) {
                if (open) {
                    return vbox({
                        checkbox | inverted,
                        radiobox | frame | 
                            size(HEIGHT, LESS_THAN, 10),
                        filler(),
                    });
                }
                return vbox({
                    checkbox,
                    filler(),
                });
            },
    });

    auto prescription_menu_1 = Dropdown({
        .radiobox = {
            .entries = &prescription_entries,
            .selected = &selected_prescription_index,
        },
        .transform =
            [](bool open, Element checkbox, Element radiobox) {
                if (open) {
                    return vbox({
                        checkbox | inverted,
                        radiobox | frame | 
                            size(HEIGHT, LESS_THAN, 10),
                        filler(),
                    });
                }
                return vbox({
                    checkbox,
                    filler(),
                });
            },
    });


    auto confirm_short_term = Button("Add Patient", [&] {
        UpdatePrescriptionEntries(); // Make sure entries are current
        
        if (time_assessed_input.empty() || selected_prescription_index < 0 || selected_prescription_index >= prescriptionVector.size()) {
            return;
        }
        
        if (selected_patient >= 0 && selected_patient < Patients.size()) {
            Patient* base = Patients[selected_patient];
            std::string prescription_name = prescriptionVector[selected_prescription_index].GetName();
            
            ShortTerm_Patient* sp = new ShortTerm_Patient(
                base->getAge(),
                base->getName(),
                base->getPriority(),
                base->getSickness(),
                time_assessed_input,
                prescription_name
            );
            
            ShortTerm_Patients.push_back(sp);
            Patients.erase(Patients.begin() + selected_patient);
            
            // Decrement prescription stock
            prescriptionVector[selected_prescription_index].Stock--;
            AllPrescriptionToFile(prescriptionVector);
            
            // Clear inputs
            time_assessed_input.clear();
            selected_prescription_index = 0;
            assignment_type = 0;
            
            depth = 2;
        }
    }, button_style);

    auto Back_10 = Button("Back", [&] { 
        depth = 9;
        assignment_type = 0;
        time_assessed_input.clear();
        selected_prescription_index = 0;
    }, button_style);

    auto confirm_long_term = Button("Add Patient", [&] {
        UpdatePrescriptionEntries(); // Make sure entries are current
        
        if (time_assessed_input.empty() || time_needed_input.empty() || selected_prescription_index < 0 || selected_prescription_index >= prescriptionVector.size()) {
            return;
        }
        
        if (selected_patient >= 0 && selected_patient < Patients.size()) {
            Patient* base = Patients[selected_patient];
            std::string prescription_name = prescriptionVector[selected_prescription_index].GetName();
            
            // Create long-term patient
            LongTerm_Patient* lp = new LongTerm_Patient(
                base->getAge(),
                base->getName(),
                base->getPriority(),
                base->getSickness(),
                time_assessed_input,
                time_needed_input,
                prescription_name
            );
            
            LongTerm_Patients.push_back(lp);
            Patients.erase(Patients.begin() + selected_patient);
            
            // Decrement prescription stock
            prescriptionVector[selected_prescription_index].Stock--;
            AllPrescriptionToFile(prescriptionVector);
            
            // Clear inputs
            time_assessed_input.clear();
            time_needed_input.clear();
            selected_prescription_index = 0;
            assignment_type = 0;
            
            depth = 2;
        }
    }, button_style);
    auto Back_11 = Button("Back", [&] { 
        depth = 9;
        assignment_type = 0;
        time_assessed_input.clear();
        time_needed_input.clear();
        selected_prescription_index = 0;
    }, button_style);
    auto Back_9 = Button("Back", [&] { depth = 2; assignment_type = 0; patient_index_input.clear();}, button_style);
    // end
    auto Dismiss_ = Button("Dismiss Patients", [&] { dismiss_patient_index.clear(); depth = 12;}, button_style);
    // Sub Buttons
    auto confirm_dismiss = Button("Dismiss Patient", [&] {
        if (dismiss_patient_index.empty()) return;
        try {
            int index = std::stoi(dismiss_patient_index);
            
            // Check if it's a short-term patient (0 to short_terms.size()-1)
            if (index >= 0 && index < (int)ShortTerm_Patients.size()) {
                delete ShortTerm_Patients[index];
                ShortTerm_Patients.erase(ShortTerm_Patients.begin() + index);
                dismiss_patient_index.clear();
                depth = 2;
                return;
            }
            
            // Check if it's a long-term patient (short_terms.size() to short_terms.size() + long_terms.size()-1)
            int long_term_index = index - (int)ShortTerm_Patients.size();
            if (long_term_index >= 0 && long_term_index < (int)LongTerm_Patients.size()) {
                delete LongTerm_Patients[long_term_index];
                LongTerm_Patients.erase(LongTerm_Patients.begin() + long_term_index);
                dismiss_patient_index.clear();
                depth = 2;
                return;
            }
        } catch (...) {}
    }, button_style);
    
    auto Back_12 = Button("Back", [&] { depth = 2; dismiss_patient_index.clear();}, button_style);
    // end
    auto Prescribe_1 = Button("Persciption Menu", [&] { depth = 13;}, button_style);
    // Sub Buttons
    auto Back_13 = Button("Back", [&] { depth = 2;}, button_style);
    // end
    auto Log_out_1 = Button("Log out", [&] { depth = 0; Log_go = 0;}, button_style);

    // Nurse Order
    auto prescription_menu_order_N = Dropdown({
        .radiobox = {
            .entries = &prescription_entries,
            .selected = &selected_rx_index_N,
        },
        .transform =
            [](bool open, Element checkbox, Element radiobox) {
                if (open) {
                    return vbox({
                        checkbox | inverted,
                        radiobox | frame | 
                            size(HEIGHT, LESS_THAN, 10),
                        filler(),
                    });
                }
                return vbox({
                    checkbox,
                    filler(),
                });
            },
    });
    auto confirm_order_N = Button("Order Medicine", [&] {
        UpdatePrescriptionEntries();
        
        if (order_quantity_input_N.empty() || selected_rx_index_N < 0 || selected_rx_index_N >= prescriptionVector.size()) {
            return;
        }
        
        try {
            int quantity = std::stoi(order_quantity_input_N);
            if (quantity > 0) {
                prescriptionVector[selected_rx_index_N].Stock += quantity;
                AllPrescriptionToFile(prescriptionVector);
                
                // Clear inputs
                order_quantity_input_N.clear();
                selected_rx_index_N = 0;
            }
        } catch (...) {}
    }, button_style);


    // Doctor Order
    auto prescription_menu_order_D = Dropdown({
        .radiobox = {
            .entries = &prescription_entries,
            .selected = &selected_rx_index_D,
        },
        .transform =
            [](bool open, Element checkbox, Element radiobox) {
                if (open) {
                    return vbox({
                        checkbox | inverted,
                        radiobox | frame | 
                            size(HEIGHT, LESS_THAN, 10),
                        filler(),
                    });
                }
                return vbox({
                    checkbox,
                    filler(),
                });
            },
    });
    auto confirm_order_D = Button("Order Medicine", [&] {
        UpdatePrescriptionEntries();
        
        if (order_quantity_input_D.empty() || selected_rx_index_D < 0 || selected_rx_index_D >= prescriptionVector.size()) {
            return;
        }
        
        try {
            int quantity = std::stoi(order_quantity_input_D);
            if (quantity > 0) {
                prescriptionVector[selected_rx_index_D].Stock += quantity;
                AllPrescriptionToFile(prescriptionVector);
                
                // Clear inputs
                order_quantity_input_D.clear();
                selected_rx_index_D = 0;
            }
        } catch (...) {}
    }, button_style);

    /*
    1 Container hold all the buttons you need for the corespoding rendering, Containers handles all the focusing

    Containers are kinda...dumb but usefull, you cant reuse buttons (have fun with variable naming lol)

    The Containers also have perameters to align the buttons verticaly or horizontaly
    */

    // Container Tree
    auto Log = Container::Vertical({
        input_Email,
        input_Password,
        Log_in_,
        Quit,
    });

    auto Tr = Container::Vertical({
        Add_Patient_,
        patient_,
        Prescribe_,
        Avg_prio_,
        Log_out_,
    });

    auto Doc = Container::Vertical({
        Reg_p_,
        All_p_,
        Assign_,
        Dismiss_,
        Prescribe_1,
        Log_out_1,
    });

    auto Adding_ = Container::Horizontal({
        input_first_name,
        input_last_name,
        input_age,
        dropdown_1prio,
        input_sick,
        push_it_,
        Back_3,
    });

    auto Table_ = Container::Vertical({
        Back_4,
    });

    auto Table_s = Container::Vertical({
        Back_7,
    });

    auto Table_l = Container::Vertical({
        Back_8,
    });
    
    auto Pre_ = Container::Vertical({
        Back_5,
    });
    
    auto avg_ = Container::Vertical({
        Back_6,
    });

    auto AssignMenu = Container::Vertical({
        input_patient_index,
        assign_short_,
        assign_long_,
        Back_9,
    });

    auto AssignShortTermMenu = Container::Vertical({
        input_time_assessed_short,
        prescription_menu,
        confirm_short_term,
        Back_10,
    });

    auto AssignLongTermMenu = Container::Vertical({
        input_time_assessed_long,
        input_time_needed,
        prescription_menu_1,
        confirm_long_term,
        Back_11,
    });

    auto DismissMenu = Container::Vertical({
        input_dismiss_index,
        confirm_dismiss,
        Back_12,
    });

    auto PrescribeMenu_N = Container::Vertical({
        prescription_menu_order_N,
        input_order_quantity_N,
        confirm_order_N,
        Back_5,
    });

    auto PrescribeMenu_D = Container::Vertical({
        prescription_menu_order_D,
        input_order_quantity_D,
        confirm_order_D,
        Back_13,
    });
    

    /*
    This is where all the rendering happens, Its kinda like a function it gets called later when it needs to, 
    The rendering will take in: A Container(Optinal) followed by this [&] (Don't know what it is but I think you need it for the code), Then your code in braces

    The Container does not need to be taken in, you can actualy render the buttons separate but id suggest only do that if the buttons will be in different spots
    Example: Depth 9 on the doctor side and in the assess menu, the assign short and long term buttons and the back button are rendered separate and split from the
    inputs by a separatory

    in terms of vbox, hbox, and dbox, they have different uses
    vbox/vertical box will flex to fill in all the virticaly space while fitting any text or buttons horizontaly unless told not to (size() command)
    hbox/horizontal box will flex to fill in all the horizontal space while fitting any text or buttons virticaly unless told not to
    dbox will just fill all the space it can unless told not to
    you can but boxes inside of echother example: depth 0 (it renderas the background, then the ascii art, then the login menu while rendering inside a dbox in the return)

    size(WIDTH...) and size(HEIGHT...) are by line and colum not a set grid so if you want a kinda big box your width is gonna be >100
    size(..., Equal is just like operators, so: the LESS_THEN with a size of 20 will be 19. Recomended for sizeing boxes to just do equal)
    anything that comes after | (the straight line) is kinda like a modifier to the element
    */

    // Renderings for all sub menus off of Log in screen
    // depth 1 / Triage Menu rendering
    auto depth1 = Renderer(Tr, [&] {
        return vbox({
            text(Menu_Name) | bold, /*just link a print command but with modifiers*/
            separatorHeavy() | color(Color::Red), /*types: separator(), separatorHeavy(), separatorLight(), separatorDashed(), separatorDouble(), and more(C:\ftxui\src\ftxui\dom\separator.cpp)*/
            Tr->Render(), /*Render the whole container or example: depth 9, you can render one button*/
        }) | center | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 23) | bgcolor(Color::GreenLight); /*modifiers for the whole return box*/
    });

    // depth 2 / Docter Menu rendering
    auto depth2 = Renderer(Doc, [&] {
        return vbox({
            text(Menu_Name) | bold,
            separatorHeavy() | color(Color::Red), /*This uses the 16 colour pallet, The only 256 pallet iv encountered was setting the animation for the buttons*/
            Doc->Render(),
        }) | center | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 23) | bgcolor(Color::GreenLight); /*also 16 colour pallet*/
    });

    // depth 3 / Add patient
    auto depth3 = Renderer(Adding_, [&] {
        return vbox({
            text("Add Patient") | bold | center,
            separatorHeavy() | color(Color::Red),
            hbox(text("First Name: "), input_first_name->Render()),
            hbox(text("Last Name:  "), input_last_name->Render()),
            hbox(text("Age:        "), input_age->Render()),
            hbox(text("Priority:   "), dropdown_1prio->Render()),
            hbox(text("Sickness:   "), input_sick->Render()),
            separator() | color(Color::Red),
            hbox({
                push_it_->Render(),
                text("   "),
                Back_3->Render(),
            }) | center,
            text(" ") | center,
            text("Fill all fields to add patient") | bold | center,
            text("Tab to switch lines") | bold | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });
    
    auto depth4 = Renderer(Table_, [&] {
        return vbox({
            text(Patient_) | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable(Patients) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            Back_4->Render() | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth6 = Renderer(avg_, [&] {
        // Create a string to hold the average
        std::string avg_text = "Average Priority: ";
        
        if (!Patients.empty()) {
            double total = 0;
            for (const auto* p : Patients) {
                total += p->getPriority();
            }
            double average = total / Patients.size();
            avg_text += std::to_string(average).substr(0, 4); // Limit to 4 characters
        } 
        else {
            avg_text += "No patients";
        }

        return vbox({
            text(avg_text) | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable(Patients) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            Back_6->Render() | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth7 = Renderer(Table_s, [&] {
        return vbox({
            text(Patient_) | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable_(Patients) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            Back_7->Render() | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth8 = Renderer(Table_l, [&] {
        return vbox({
            text("All Patients") | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable_1(
                ShortTerm_Patients,
                LongTerm_Patients
            ) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            Back_8->Render() | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth9 = Renderer(AssignMenu, [&] {
        return vbox({
            text("Assign Patient") | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable(Patients) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            hbox(text("Select Patient Index: "), input_patient_index->Render()),
            separator() | color(Color::Red),
            hbox({
                assign_short_->Render(),
                text("   "),
                assign_long_->Render(),
                text("   "),
                Back_9->Render(),
            }) | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth10 = Renderer(AssignShortTermMenu, [&] {
        UpdatePrescriptionEntries();
        std::string patient_info = "";
        if (selected_patient >= 0 && selected_patient < Patients.size()) {
            Patient* p = Patients[selected_patient];
            patient_info = p->getName() + " (Age: " + std::to_string(p->getAge()) + ", Priority: " + std::to_string(p->getPriority()) + ")";
        }
        
        return vbox({
            text("Assign Short-Term Patient") | bold | center,
            text(patient_info) | center,
            separatorHeavy() | color(Color::Red),
            hbox(text("Time Assessed: "), input_time_assessed_short->Render()),
            hbox(text("Prescription:  "), prescription_menu->Render()),
            separator() | color(Color::Red),
            hbox({
                confirm_short_term->Render(),
                text("   "),
                Back_10->Render(),
            }) | center,
            text(" ") | center,
            text("Fill all fields to assign patient") | bold | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth11 = Renderer(AssignLongTermMenu, [&] {
        UpdatePrescriptionEntries();
        std::string patient_info = "";
        if (selected_patient >= 0 && selected_patient < Patients.size()) {
            Patient* p = Patients[selected_patient];
            patient_info = p->getName() + " (Age: " + std::to_string(p->getAge()) + ", Priority: " + std::to_string(p->getPriority()) + ")";
        }
        
        return vbox({
            text("Assign Long-Term Patient") | bold | center,
            text(patient_info) | center,
            separatorHeavy() | color(Color::Red),
            hbox(text("Time Assessed: "), input_time_assessed_long->Render()),
            hbox(text("Time Needed:   "), input_time_needed->Render()),
            hbox(text("Prescription:  "), prescription_menu_1->Render()),
            separator() | color(Color::Red),
            hbox({
                confirm_long_term->Render(),
                text("   "),
                Back_11->Render(),
            }) | center,
            text(" ") | center,
            text("Fill all fields to assign patient") | bold | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth12 = Renderer(DismissMenu, [&] {
        return vbox({
            text("Dismiss Patient") | bold | center,
            separatorHeavy() | color(Color::Red),
            RenderPatientTable_1(
                ShortTerm_Patients,
                LongTerm_Patients
            ) | center | frame | vscroll_indicator,
            separator() | color(Color::Red),
            text("Enter index from table above to dismiss") | center,
            hbox(text("Select Patient Index: "), input_dismiss_index->Render()),
            separator() | color(Color::Red),
            hbox({
                confirm_dismiss->Render(),
                text("   "),
                Back_12->Render(),
            }) | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth5 = Renderer(PrescribeMenu_N, [&] {
        UpdatePrescriptionEntries();
        return vbox({
            text("Prescription Menu") | bold | center,
            separatorHeavy() | color(Color::Red),
            text("Current Prescription Stock:") | bold | center,
            separator() | color(Color::Red),
            hbox(text("Select Medicine: "), prescription_menu_order_N->Render()),
            hbox(text("Order Quantity: "), input_order_quantity_N->Render()),
            separator() | color(Color::Red),
            hbox({
                confirm_order_N->Render(),
                text("   "),
                Back_5->Render(),
            }) | center,
            text(" ") | center,
            text("Fill all fields to order") | bold | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });

    auto depth13 = Renderer(PrescribeMenu_D, [&] {
        UpdatePrescriptionEntries();
        return vbox({
            text("Prescription Menu") | bold | center,
            separatorHeavy() | color(Color::Red),
            text("Current Prescription Stock:") | bold | center,
            separator() | color(Color::Red),
            hbox(text("Select Medicine: "), prescription_menu_order_D->Render()),
            hbox(text("Order Quantity: "), input_order_quantity_D->Render()),
            separator() | color(Color::Red),
            hbox({
                confirm_order_D->Render(),
                text("   "),
                Back_13->Render(),
            }) | center,
            text(" ") | center,
            text("Fill all fields to order") | bold | center,
        }) | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 120) | size(HEIGHT, EQUAL, 30) | bgcolor(Color::GreenLight);
    });


    /*
    You can either return just one box or like the depth 0 you just set variables for all the layers and then return them in on big box in the layer order
    */

    // depth 0 / Log in rendering
    auto depth0 = Renderer(Log, [&] {
        auto background = filler() | bgcolor(LinearGradient()
                                        .Angle(0)
                                        .Stop(Color::White)
                                        .Stop(Color::Red));
        auto ui = vbox({
            text(Log_in) | bold | center,
            separatorHeavy() | color(Color::Red),
            Log->Render(),
        }) | center | borderStyled(DOUBLE, Color::Red) | size(WIDTH, EQUAL, 30) | size(HEIGHT, EQUAL, 15) | bgcolor(Color::GreenLight);
        auto HRE = vbox({
            color(Color::GreenLight, text("                            ")),
            color(Color::GreenLight, text("  ███╗   ███╗ ███████╗ ██████╗ ")),
            color(Color::GreenLight, text("  ████╗ ████║ ██╔════╝ ██╔══██╗")),
            color(Color::GreenLight, text("  ██╔████╔██║ █████╗   ██║  ██║")),
            color(Color::GreenLight, text("  ██║╚██╔╝██║ ██╔══╝   ██║  ██║")),
            color(Color::GreenLight, text("  ██║ ╚═╝ ██║ ███████╗ ██████╔╝")),
            color(Color::GreenLight, text("  ╚═╝     ╚═╝ ╚══════╝ ╚═════╝ ")),
        });
        return dbox({
            background,
            ui | center,
            HRE
            });
    });

    /*
    This is the main container that holds all the menu renderings

    This is inportant and because of one little mistake of forgeting to fill each new depth, it didnt focus when i got to that menu and it stressed me out so much why it was not working

    also this whole menu system is an example off of this example from the ftxui github: https://arthursonzogni.github.io/FTXUI/examples/?file=component/modal_dialog_custom
    */

    auto main_container = Container::Tab(
    {
        depth0,
        depth1,
        depth2,
        depth3,
        depth4,
        depth5,
        depth6,
        depth7,
        depth8,
        depth9,
        depth10,
        depth11,
        depth12,
        depth13,
    },
    &depth);

    /*
    This is where it all comes together, This will then render the corect depth/menu when the depth tracker is changed

    clear_under is just incase you have your boxes with no background it will clear any lines and stuff thats under it, so i could go with out it but it seems to work with it so im just leaving it

    document is a Element witch is a node that provides all the basic structer for layouts and rendering (dont relly know but all i know is it was in the example and it works so i think its needed)
    it first renders depth 0/Log in screen and then when a button is pressed it renders the correct one
    */

    auto main_renderer = Renderer(main_container, [&] {
        Element document = depth0->Render();

        if (depth == 1)
        {
            document = dbox({
                document,
                depth1->Render() | clear_under | center,
            });
        }
        if (depth == 2)
        {
            document = dbox({
                document,
                depth2->Render() | clear_under | center,
            });
        }
        if (depth == 3)
        {
            document = dbox({
                document,
                depth3->Render() | clear_under | center,
            });
        }
        if (depth == 4)
        {
            document = dbox({
                document,
                depth4->Render() | clear_under | center,
            });
        }
        if (depth == 5)
        {
            document = dbox({
                document,
                depth5->Render() | clear_under | center,
            });
        }
        if (depth == 6)
        {
            document = dbox({
                document,
                depth6->Render() | clear_under | center,
            });
        }
        if (depth == 7)
        {
            document = dbox({
                document,
                depth7->Render() | clear_under | center,
            });
        }
        if (depth == 8)
        {
            document = dbox({
                document,
                depth8->Render() | clear_under | center,
            });
        }
        if (depth == 9)
        {
            document = dbox({
                document,
                depth9->Render() | clear_under | center,
            });
        }
        if (depth == 10)
        {
            document = dbox({
                document,
                depth10->Render() | clear_under | center,
            });
        }
        if (depth == 11)
        {
            document = dbox({
                document,
                depth11->Render() | clear_under | center,
            });
        }
        if (depth == 12)
        {
            document = dbox({
                document,
                depth12->Render() | clear_under | center,
            });
        }
        if (depth == 13)
        {
            document = dbox({
                document,
                depth13->Render() | clear_under | center,
            });
        }
        return document;
    });

    /*
    This screen.Loop(main_renderer); Loops everything together so that stuff renders correctly

    man if i got a dollor for every time i said render I would have $24... Ctrl + F is useful
    */

    screen.Loop(main_renderer);
    return 0;
}
