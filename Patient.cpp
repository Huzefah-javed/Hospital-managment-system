#include<iostream>
#include"Person.h"
#include"Patient.h"
#include<vector>
using namespace std;
    
    int Patient::ID = 000;
    
    Patient::Patient():patientID("P"){}

    void Patient::registerPatient(){
        ID++;
        patientID += to_string(ID);
    }

    void Patient::bookAppointment(){};
    
    void  Patient::displayInfo(){
         cout<<"Patient '"<<name<< " registered successfully with :"<<endl;
       cout<<"ID: "<<patientID<<endl;
       cout<<"Password: "<<password<<endl;
        for(auto d: medicalHistory){
            cout<<" "<<d;
        }
        cout<<endl;
        cout<<"---->>>> plz remember your password and ID"<<endl;
    }
