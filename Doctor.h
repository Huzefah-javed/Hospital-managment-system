#pragma once

#include <iostream>
#include "Person.h"
#include "Patient.h"
#include <vector>
using namespace std;

class Doctor: public Person{
    public:
   static int ID;
   string specialization;
   string doctorID = "D";
   string password;
   vector<string>availableTimeSlots;
   vector<Patient>appointedPatients;

    Doctor();
    void registerDoctor();
   void  displayInfo() override;
};