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
        this->books.push_back(currentBook);
        file.read((char*)currentBook, sizeof(*currentBook));
    }
    file.close();
}
void BookManagement::insertBook(Book *newBook) {
    this->books.push_back(newBook);
}
void BookManagement::displayBooks() {
    for (int i = 0; i < this->books.size(); i++) {
        Book *book = this->books[i];
        book->show();
    }
    
}
void BookManagement::saveBooks() {
    ofstream file;
    cout<<"Enter file name to save books : ";cin>>this->bookFile;
    //out: for write new, app = append
    file.open(this->bookFile, ios:: binary);
    if(file){
        for (int i = 0; i < this->books.size(); i++) {
            Book *book = this->books[i];
            file.write((char*)book, sizeof(*book));
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
    file.open(this->readerFile, ios:: binary);
    this->readers.clear();//remove objects
    Reader *currentReader = new Reader();
    file.read((char*)currentReader, sizeof(*currentReader));
    while (!file.eof()) {
        this->readers.push_back(currentReader);
        file.read((char*)currentReader, sizeof(*currentReader));
    }
    file.close();
}
void BookManagement::insertReader(Reader *newReader) {
    this->readers.push_back(newReader);
}
void BookManagement::displayReaders() {
    for (int i = 0; i < this->readers.size(); i++) {
        Reader *reader = this->readers[i];
        reader->show();
    }
    
}
void BookManagement::saveReaders() {
    ofstream file;
    cout<<"Enter file name to save readers : ";cin>>this->readerFile;
    //out: for write new, app = append
    file.open(this->readerFile, ios:: binary);
    if(file){
        for (int i = 0; i < this->readers.size(); i++) {
            Reader *reader = this->readers[i];
            file.write((char*)reader, sizeof(*reader));
        }
        file.close();
        cout<<"Save readers successfully to file "<<this->readerFile<<endl;
    }else {
        cout<<"Cannot open file : "<<this->readerFile<<" to save"<<endl;
    }
}

void BookManagement::sortReadersByNames() {
    for (int i = 0; i < this->readers.size() - 1; i++) {
        for (int j = i + 1; j < this->readers.size(); i++) {            
            if(this->readers[i].name.compare(this->readers[j].name) > 0) {
                Reader temp = this->readers[i];
                this->readers[i] = this->readers[j];
                this->readers[j] = temp;
            }
        }
        Book book = this->books[i];
    }
}
void BookManagement::sortReadersByBooks() {
    for (int i = 0; i < this->readers.size() - 1; i++) {
        for (int j = i + 1; j < this->readers.size(); i++) {
            long numberOfBooksI = this->readers[i].books.size();
            long numberOfBooksJ = this->readers[j].books.size();
            if(numberOfBooksI > numberOfBooksJ) {
                Reader temp = this->readers[i];
                this->readers[i] = this->readers[j];
                this->readers[j] = temp;
            }
        }
        Book book = this->books[i];
    }
}
