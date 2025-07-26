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
       cout<<"Medical history: ";
       if (medicalHistory.size() != 0)
       {
               
        for(auto d: medicalHistory){
            cout<<" "<<d;
        }
        cout<<endl;
    }else{
        cout<<"Nil"<<endl;
    }
    cout<<"Ant notes by doctor: "<<endl;
    if (NotesByDoctors.size() != 0)
    {   
        for(auto note: NotesByDoctors){
            cout<<note<<endl;
        }
        cout<<"---->>>> plz remember your password and ID"<<endl;
    }else cout<<"Nill"<<endl;
    }
