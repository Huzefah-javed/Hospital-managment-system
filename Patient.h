 #pragma once

#include <iostream>
#include "Person.h"
#include<vector>

class Patient: public Person{
    public:
    static int ID;
    string patientID;
    string password;
    vector<string> medicalHistory;
    vector<string> appointments;
    vector<string>NotesByDoctors;
    
    Patient();

    void bookAppointment();
    void registerPatient();
    void  displayInfo() override;
};