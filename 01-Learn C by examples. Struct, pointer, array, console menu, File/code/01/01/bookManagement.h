#define bookManagement_h

#include <stdio.h>
//You can use DevC/C++ in Windows!
struct Book {
    char name[220];//fields = properties
    char publisher[250];
    int year;
    float price;
};
struct Book* input(void);
void display(struct Book* book);
void sort(struct Book* book);
void find(struct Book* book);
void analyze(struct Book* book);
void save(struct Book* book);
void openFile(struct Book *book);

