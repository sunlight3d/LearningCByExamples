//
//  Reader.hpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include <stdio.h>
#include "Person.hpp"
enum ReaderType {
    STUDENT,
    MASTER,
    TEACHER
};
//Reader is "derived class"
class Reader:Person {
private:
    ReaderType type;//“student”, “master”, “teacher”
    int libraryCode;
//How to implement auto-increment ?
public:
    static int numberOfObjects;
    //constructor
    Reader(string name, string address, string phoneNumber, ReaderType type):
        Person(name, address, phoneNumber) {
            this->numberOfObjects++;
            this->libraryCode = numberOfObjects;
            this->type = type;
    }
    //function to show detail object
    void show() override;
    //friend class
    friend class BookManagement;
};
#endif /* Reader_hpp */
