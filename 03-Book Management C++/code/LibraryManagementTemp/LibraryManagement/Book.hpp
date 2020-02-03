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
public:
    static int numberOfObjects;
    string name;
    string author;
    int yearOfPublication;
    //constructor
    Book() {
        name = "";
        author = "";
    }
    Book(string name, string author, int yearOfPublication);
    //friend class
    friend class BookManagement;
    static Book* inputBook() {
        string name, author;
        int yearOfPublication;
        cout<<"Enter book's name : ";cin>>name;
        cout<<"Enter book's author : ";cin>>author;
        cout<<"Enter book's publication year : ";cin>>yearOfPublication;
        Book* newBook = new Book(name, author, yearOfPublication);
        return newBook;
    }
    void show();
};
#endif /* Book_hpp */
