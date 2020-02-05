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
    Reader *mrHoang = new Reader("Hoang", "Hanoi, Vietnam", "+84-0944896239", STUDENT);
    Reader *mrA = new Reader("A", "Shanghai, China", "+86-123345668", TEACHER);
    mrHoang->show();
    mrA->show();
    //some books
    Book *bookC = new Book("C Programming Language, 2nd Edition", "Brian W. Kernighan", 1978);
    Book *bookJava = new Book("Java Software Solutions (9th Edition)", "William Loftus ", 2017);
    Book *bookCSharp = new Book("C#: Programming Basics for Absolute Beginners (Step-By-Step C#) ", "Nathan Clark", 2018);
    
    BookManagement bookManagement;
    bookManagement.insertBook(*bookC);
    bookManagement.insertBook(*bookJava);
    bookManagement.insertBook(*bookCSharp);
    bookManagement.saveBooks();
    bookManagement.readBooksFromFile();
    bookManagement.displayBooks();
            
    return 0;
}
