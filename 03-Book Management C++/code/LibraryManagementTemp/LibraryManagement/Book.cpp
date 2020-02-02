//
//  Book.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include "Book.hpp"
int Book::numberOfObjects = 0;
Book::Book(string name, string author, int yearOfPublication) {
    numberOfObjects++;
    this->code = numberOfObjects;
    this->name = name;
    this->author = author;
    this->yearOfPublication = yearOfPublication;
};

