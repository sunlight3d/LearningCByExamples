//
//  Reader.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include "Reader.hpp"
int Reader::numberOfObjects = 0;
void Reader::show() {
    Person::show();
    cout<<"Library code: "<<this->libraryCode<<endl;
    cout<<"Reader type: "<<this->type<<endl;
}
void Reader::borrow(Book *book) {
    this->books.push_back(book);
}
