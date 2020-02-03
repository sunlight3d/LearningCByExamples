//
//  BookManagement.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include "BookManagement.hpp"
#include <fstream>
void BookManagement::inputBooks() {
    int numberOfBooks;
    cout<<"Enter number of books : ";cin>>numberOfBooks;
    for (int i = 0; i < numberOfBooks; i++) {
        Book* book = Book::inputBook();
        this->books.push_back(*book);
    }
}
void BookManagement::displayBooks() {
    // Object to read from file
    ifstream file;
    this->books.clear();//remove objects
    Book currentBook;
    file.read((char*)&currentBook, sizeof(currentBook));
    while (!file.eof()) {
        this->books.push_back(currentBook);
        file.read((char*)&currentBook, sizeof(currentBook));
    }
    for (int i = 0; i < this->books.size(); i++) {
        Book book = this->books[i];
        book.show();
    }
}
void BookManagement::saveBooks() {
    ofstream file;
    cout<<"Enter file name to save books : ";cin>>this->bookFile;
    file.open(this->bookFile, ios::app | ios:: binary);
    if(file){
        for (int i = 0; i < this->books.size(); i++) {
            Book book = this->books[i];
            file.write((char*)&book, sizeof(book));
        }
        file.close();
        cout<<"Save books successfully to file "<<this->bookFile<<endl;
    }else {
        cout<<"Cannot open file : "<<this->bookFile<<" to save"<<endl;
    }
}
/*

void BookManagement::saveBooks();
//array of Readers
void BookManagement::inputReaders();
void BookManagement::displayReaders();//read file & display array of Readers
void BookManagement::saveReaders();
//Reader borrows books
void BookManagement::sortBooksByReader();
*/
