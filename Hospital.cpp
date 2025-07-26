 #include <iostream>
 #include <limits>
 #include"Doctor.h"
 #include"Patient.h"
 #include"Hospital.h"
 #include"Room.h"
 #include"Staff.h"
 #include<vector>
using namespace std;
 
 vector<Doctor>HospitalSystem::doctors;
 vector<Patient>HospitalSystem::patients;
    
    HospitalSystem::HospitalSystem(){
        while (userChoice != 5)
        {
        cout<<"Welcome to Huzefa's Hospital"<<endl;
        cout<<"1. Add Doctor"<<endl;
        cout<<"2. Add Patient"<<endl;
        cout<<"3. Enter in your Patient Profile"<<endl;
        cout<<"4. Enter in your doctor profile"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>userChoice;
        Doctor d;
        Patient pat;
        if (userChoice == 1){
           addDoctor(d);
           d.registerDoctor();
           d.displayInfo(); 
           doctors.push_back(d);
        }else if(userChoice == 2)
        {
            addPatient(pat);
            pat.registerPatient();
            pat.displayInfo();
            patients.push_back(pat);
        }
        else if(userChoice == 3)
        {
            EnteringInPatientProfile();
        }else if(userChoice == 4){
            EnteringInDoctorProfile();
        }else if(userChoice == 5){
            break;
        }
        }
        
        
    }
    
    
   void HospitalSystem::addDoctor(Doctor& doc){
            string time;
            cout<<"Enter Doctor Name: ";
            cin>>doc.name;
            cout<<"Enter Age: ";
            cin>>doc.age;
            cout<<"Enter Gender (M/F): ";
            cin>>doc.gender;
            cout<<"Enter Specialization: ";
            cin>>doc.specialization;
            cout<<"Set your password: ";
            cin>>doc.password;
            while (time != "end")
            {
                cout<<"Enter your available time (type 'end' if all avail time u have entered) : ";
                cin>>time;
                if (time != "end") doc.availableTimeSlots.push_back(time);
                
            }
            

        }
        
        void HospitalSystem::addPatient(Patient& p){
            string disease; 
            cout<<"Enter Patient Name: ";
            cin>>p.name;
            cout<<"Enter Age: ";
            cin>>p.age;
            cout<<"Enter Gender (M/F): ";
            cin>>p.gender;
            cout<<"Set your profile Password: ";
            cin>>p.password;
            cout<<"Any previous medical history? (y/n): ";
            cin>>disease;
            if (disease == "y")
            {
            while (disease != "end")
            {
                cout<<"Enter the disease name: (type 'end' if all disease covers) ";
                cin>>disease;
                if(disease != "end") p.medicalHistory.push_back(disease); 
            }
            
            }

        }
        void HospitalSystem::bookAppointment(Patient& p, Doctor& d){
            d.appointedPatients.push_back(p);
            cout<<"patient count after pushing"<<d.appointedPatients.size()<<endl;
            cout<<"Dr "<<d.name<<" "<<d.specialization<<" is available for patient: "<<p.name<<endl;
        }
        void HospitalSystem::showAllDoctors(){
            for(auto doc: doctors){
                cout<<"------------------------------"<<endl;
                cout<<doc.name<<" "<<doc.doctorID<<endl;
                cout<<doc.specialization<<endl;
                for(auto time: doc.availableTimeSlots){
                    cout<<"--> "<<time<<endl;
                }
            }
        }

        void HospitalSystem::EnteringInPatientProfile(){
            string inputPatientId;
            string inputPatientPassword;
            string patientChoosedDocId;
            Doctor * patientChoosedDoc = nullptr;
            Patient * patientProfile = nullptr;
            int patientChoice = 0;
            cout<<"Enter your patient ID: ";
            cin>>inputPatientId;
            cout<<"Enter your your password: ";
            cin>>inputPatientPassword;
            for(auto& patient: patients){
                if(patient.patientID == inputPatientId && patient.password == inputPatientPassword){
                    cout<<"Login successfully"<<endl;
                    patientProfile = &patient;
                } 
            }
            while (patientChoice != 4){
            if (patientProfile != nullptr)
            {
                    
                
                cout<<"welcome "<<patientProfile->name<<endl;
                cout<<"1. Book appointment"<<endl;
                cout<<"2. view All doctors"<<endl;
            cout<<"3. view profile detail"<<endl;
            cout<<"4. logout"<<endl;
            cout<<"Enter your choice: ";
            cin>>patientChoice;
            if (patientChoice == 1)
            {
                cout<<"enter doctor ID for appointment: ";
                cin>>patientChoosedDocId;
                for(auto& doc: doctors){
                    if(patientChoosedDocId == doc.doctorID) patientChoosedDoc = &doc;
                }
                bookAppointment(*(patientProfile), *(patientChoosedDoc));
            }else if(patientChoice == 2){
                showAllDoctors();
            }else if (patientChoice == 3){
                patientProfile->displayInfo();
            }
            else if (patientChoice == 4)
            {
                break;
            }
            
       }else{
            patientChoice = 4;
            cout<<"unable to login"<<endl;
            cout<<"plz enter correct id or password"<<endl;
        }
    }
        }

        void HospitalSystem::EnteringInDoctorProfile(){
            string inputDocId;
            string inputDocPassword;
            int doctorChoice;
            string patientIdPickByDoc;
            Patient * patientPickByDoc = nullptr;
            Doctor * doctorProfile = nullptr;
            string docNote;
            cout<<"-----------------------------------------"<<endl;
            cout<<"Enter your Doctor Id: ";
            cin>>inputDocId;
            cout<<"Enter your password: ";
            cin>>inputDocPassword;
            
            for(auto &doc: doctors){
                if (doc.doctorID == inputDocId && doc.password == inputDocPassword) 
                {
                    cout<<"Login successfully"<<endl;
                    doctorProfile = &doc;

                }
                
            }
            
            while (doctorChoice != 4)
            {
                if (doctorProfile != nullptr){
            cout<<"Welcome Dr "<<doctorProfile->name<<endl;
            cout<<"1. View All Appointed Patients"<<endl;
            cout<<"2. Write Prescription / Notes"<<endl;
            cout<<"3. view profile"<<endl;
            cout<<"4. logout"<<endl;

                
                cout<<"Enter your choice: ";
                cin>>doctorChoice;
                if (doctorChoice == 1)
                {
                    cout<<"-------------------------------"<<endl;
                for(auto appointPatient: doctorProfile->appointedPatients){
                    cout<<appointPatient.name<<"  "<<appointPatient.patientID<<endl;
                    cout<<"Age: "<<appointPatient.age<<"  Gender: "<<appointPatient.gender<<endl;
                    cout<<"Medical history: ";
                    for(auto disease: appointPatient.medicalHistory){
                        
                        cout<<"-"<<disease<<"-";
                    }
                    cout<<endl;
                }
            }else if (doctorChoice == 2){
                cout<<"Enter patient ID: ";
                cin>>patientIdPickByDoc;
                for(auto & patient: patients){
                    if(patient.patientID == patientIdPickByDoc) patientPickByDoc = &patient; 
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, docNote);

                docNote += " by Dr " + doctorProfile->name;
                patientPickByDoc->NotesByDoctors.push_back(docNote);
            }else if (doctorChoice == 3){
                doctorProfile->displayInfo();
            }else if (doctorChoice == 4)
            {
                break;
            }
            
            
        }else{
            doctorChoice = 4;
            cout<<"unable to login"<<endl;
            cout<<"plz enter correct id or password"<<endl;
        }
    }
        }