//
//  BookManagement.hpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#ifndef BookManagement_hpp
#define BookManagement_hpp
#include <vector>
#include <stdio.h> 
#include "Book.hpp"
#include "Reader.hpp"

using namespace std;
class BookManagement{
private:
    vector<class Book> books;
    vector<class Reader> readers;
    string bookFile, readerFile, readerBookfile;
public:
    void insertBook(Book newBook);
    void readBooksFromFile();
    void displayBooks(); //read file & display array of Books
    void saveBooks();
    //array of Readers
    void displayReaders();//read file & display array of Readers
    void readReadersFromFile();
    void saveReaders();
    //Reader borrows books
    void sortBooksByReader();
};

#endif /* BookManagement_hpp */
