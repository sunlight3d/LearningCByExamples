//
//  Person.hpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
//hpp = header plus plus
#include <stdio.h>
#include <iostream>
using namespace std;
class Person {
private:
    string name, address, phoneNumber;
public:
    Person() {
        name = "";
        string address;
        phoneNumber = "";
    }
    //getter
    string getName();
    string getAddress();
    string getPhoneNumber();
    //setter
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNumber);
    //public methods
    virtual void show();
    //constructor
    Person(string name, string address, string phoneNumber);
};


#endif /* Person_hpp */
