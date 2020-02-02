//
//  Person.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//
#include <iostream>
#include "Person.hpp"
using namespace std;
//How to separate header file and cpp file
//getter
string Person::getName() {
    return this->name;
}
string Person::getAddress() {
    return this->address;
}
string Person::getPhoneNumber() {
    return this->phoneNumber;
}
//setter
void Person::setName(string name) {
    this->name = name;
}
void Person::setAddress(string address) {
    this->address = address;
}
void Person::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
Person::Person(string name, string address, string phoneNumber) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}
void Person::show() {
    cout<<"Person detail:"<<endl;
    cout<<"Name: "<<this->name<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Phone number: "<<this->phoneNumber<<endl;
}

