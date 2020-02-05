//
//  BookManagement.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include "BookManagement.hpp"
#include <fstream>

void BookManagement::readBooksFromFile() {
    // Object to read from file
    ifstream file;
    file.open(this->bookFile, ios:: binary);
    this->books.clear();//remove objects
    Book *currentBook = new Book();
    file.read((char*)currentBook, sizeof(*currentBook));
    while (!file.eof()) {
        this->books.push_back(*currentBook);
        file.read((char*)currentBook, sizeof(*currentBook));
    }
    file.close();
}
void BookManagement::insertBook(Book newBook) {
    this->books.push_back(newBook);
}
void BookManagement::displayBooks() {
    for (int i = 0; i < this->books.size(); i++) {
        Book book = this->books[i];
        book.show();
    }
    
}
void BookManagement::saveBooks() {
    ofstream file;
    cout<<"Enter file name to save books : ";cin>>this->bookFile;
    //out: for write new, app = append
    file.open(this->bookFile, ios:: binary);
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

void BookManagement::readReadersFromFile() {
    // Object to read from file
    ifstream file;
    this->readers.clear();//remove objects
    Reader currentReader;
    file.read((char*)&currentReader, sizeof(currentReader));
    while (!file.eof()) {
        this->readers.push_back(currentReader);
        file.read((char*)&currentReader, sizeof(currentReader));
    }
}

void BookManagement::displayReaders() {
    for (int i = 0; i < this->readers.size(); i++) {
        Reader reader = this->readers[i];
        reader.show();
    }
    
}
void BookManagement::saveReaders() {
    ofstream file;
    cout<<"Enter file name to save readers : ";cin>>this->readerFile;
    file.open(this->readerFile, ios::app | ios:: binary);
    if(file){
        for (int i = 0; i < this->readers.size(); i++) {
            Reader reader = this->readers[i];
            file.write((char*)&reader, sizeof(reader));
        }
        file.close();
        cout<<"Save readers successfully to file "<<this->readerFile<<endl;
    }else {
        cout<<"Cannot open file : "<<this->readerFile<<" to save"<<endl;
    }
}
