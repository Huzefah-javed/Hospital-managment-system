#pragma once 
 
 #include <iostream>
 #include"Doctor.h"
 #include"Patient.h"
 #include"Hospital.h"
 #include<vector>
using namespace std;

 
class HospitalSystem{
    public:
    static vector<Doctor>doctors;
    static vector<Patient>patients;
     int userChoice;
    
        HospitalSystem();
     
        void addDoctor(Doctor& doc);
        void addPatient(Patient& p);
        void bookAppointment(Patient& p, Doctor& d);
        void showAllDoctors();
        void EnteringInPatientProfile();
        void EnteringInDoctorProfile();        
    };