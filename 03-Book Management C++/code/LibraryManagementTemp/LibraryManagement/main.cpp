//
//  main.cpp
//  LibraryManagement
//
//  Created by Nguyen Duc Hoang on 2/2/20.
//  Copyright © 2020 Nguyen Duc Hoang. All rights reserved.
//

#include <iostream>
#include "Reader.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Create a new reader\n";
    Reader *mrHoang = new Reader("Hoang", "Hanoi, Vietnam", "+84-0944896239", STUDENT);
    Reader *mrA = new Reader("A", "Shanghai, China", "+86-123345668", TEACHER);
    mrHoang->show();
    mrA->show();
    return 0;
}
