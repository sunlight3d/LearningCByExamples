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
#include "Book.hpp"
enum ReaderType {
    STUDENT = 0,
    MASTER = 1,
    TEACHER = 2
};
//Reader is "derived class"
class Reader:Person {
private:
    ReaderType type;//“student”, “master”, “teacher”
    int libraryCode;
    vector<class Book> books; //1 reader "borrow" many books
//How to implement auto-increment ?
public:
    static int numberOfObjects;
    //constructor
    Reader() {
        type = STUDENT;
    }
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
