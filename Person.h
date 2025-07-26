#pragma once


#include <iostream>
using namespace std;

class Person{
   public:
   string name;
   int age; 
   char gender;
   string ID;

    virtual void displayInfo() = 0;
};
