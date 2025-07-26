#pragma once 
 
 #include <iostream>
 #include"Doctor.h"
 #include"Patient.h"
 #include"Hospital.h"
 #include"Room.h"
 #include"Staff.h"
 #include<vector>
using namespace std;

 
class HospitalSystem{
    public:
    static vector<Doctor>doctors;
    static vector<Patient>patients;
     vector<Staff>staffs;
     vector<Room>rooms;
     int userChoice;
    
        HospitalSystem();
     
        void addDoctor(Doctor& doc);
        void addPatient(Patient& p);
        void bookAppointment(Patient& p, Doctor& d);
        void showAllDoctors();
        void EnteringInPatientProfile();
        void EnteringInDoctorProfile();        
    };