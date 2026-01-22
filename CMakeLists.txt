cmake_minimum_required(VERSION 3.16)
project(ftxui_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(ftxui)

add_executable(main 
  main.cpp
  src/HospitalData.cpp
  src/HospitalStaff.cpp
  src/Patient.cpp
  src/Prescriptions.cpp)

target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)