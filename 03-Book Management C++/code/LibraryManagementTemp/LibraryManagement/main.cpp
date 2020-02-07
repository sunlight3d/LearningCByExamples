//
//  main.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include <iostream>
#include "Reader.hpp"
#include "Book.hpp"
#include "BookManagement.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Create a new reader\n";
    Reader *mrHoang = new Reader("Hoang", "Bach Mai street, Hanoi, Vietnam", "+84-0944896239", TEACHER);
    Reader *mrRobinson = new Reader("Robinson", "somewhere in this world", "+86-123345668", STUDENT);
    Reader *mrCarroll   = new Reader("Carroll Tom", "Address 2", "+84-222222222", MASTER);
    Reader *mrAllen = new Reader("Allen", "Address 3", "+86-123345668", TEACHER);
    
    mrHoang->show();
    mrRobinson->show();
    //some books
    Book *bookC = new Book("C Programming Language, 2nd Edition", "Brian W. Kernighan", 1978);
    Book *bookJava = new Book("Java Software Solutions (9th Edition)", "William Loftus ", 2017);
    Book *bookCSharp = new Book("C#: Programming Basics for Absolute Beginners (Step-By-Step C#) ", "Nathan Clark", 2018);
    
    BookManagement bookManagement;
    
    bookManagement.insertBook(bookC);
    bookManagement.insertBook(bookJava);
    bookManagement.insertBook(bookCSharp);
    bookManagement.saveBooks();
    bookManagement.readBooksFromFile();
    bookManagement.displayBooks();
    //some Readers borrows books
    bookManagement.insertReader(mrHoang);
    bookManagement.insertReader(mrRobinson);
    bookManagement.insertReader(mrCarroll);
    bookManagement.insertReader(mrAllen);
    mrHoang->borrow(bookC);
    mrHoang->borrow(bookCSharp);
    
    return 0;
}
