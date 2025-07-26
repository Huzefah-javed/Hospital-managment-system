#include<iostream>
#include"Person.h"
#include"Doctor.h"
#include<vector>

int Doctor::ID = 000;

    Doctor::Doctor():doctorID("D"){}

   void Doctor::registerDoctor(){
      ID++;
      doctorID += to_string(ID);

    }
   void  Doctor::displayInfo(){
       cout<<"Doctor '"<<name<< " registered successfully with :"<<endl;
       cout<<"ID: "<<doctorID<<endl;
       cout<<"Password: "<<password<<endl;
       cout<<"---->>>> plz remember your password and ID"<<endl;
    }