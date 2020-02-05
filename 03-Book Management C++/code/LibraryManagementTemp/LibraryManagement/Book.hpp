//
//  Book.hpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp
#include <iostream>
#include <stdio.h>
#include "BookManagement.hpp"

using namespace std;
enum BookSubject {
    NATURAL_SCIENCE,
    LITERARY,
    INFORMATION_TECHNOLOGY
};
class Book {
private:
    int code;//auto increment
    string name;
    string author;
    int yearOfPublication;
public:
    static int numberOfObjects;
    //constructor
    Book() {
        name = "";
        author = "";
    }
    Book(string name, string author, int yearOfPublication);
    //friend class
    friend class BookManagement;    
    void show();
};
#endif /* Book_hpp */
