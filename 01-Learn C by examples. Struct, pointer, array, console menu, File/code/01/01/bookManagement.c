
#include "bookManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;//this is a "Global Variable"
struct Book* input() {//this is a function
    printf("Enter number of books: "); scanf("%d", &N);
    struct Book *book = (struct Book *)malloc(N * sizeof(struct Book));
    int i;
    for (i = 0; i < N; i++) {
        INPUT_ONE: printf("Book number %d : \n", i+1);
        printf("Enter book's name : ");scanf("%s", (book+i)->name);
        //scanf("%s", (*(book+i)).name);
        printf("Enter book's year : "); scanf("%d", &(book+i)->year);
        //Validate input ?
        if((book+i)->year <= 2000) {
            printf("Year must be > 2000\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
        printf("Enter book's publisher :");scanf("%s", (book+i)->publisher);
        printf("Enter book's price($) :");scanf("%f", &(book+i)->price);
        if((book + i)->price < 100 || (book + i)->price > 200){
            printf("Price >= 100, price <= 200\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
    }
    return book;
}
//How to display result ?
void display(struct Book* book) {
    int i, numberOfBooks;
    printf("+----------------------------------------------+\n");
    printf("|Name       |Year       |Publisher  |Price     |\n");
    printf("+----------------------------------------------+\n");
    numberOfBooks = 0;
    for (i = 0; i < N && (book + i)->year > 0; i++) {
        printf("|%-11s", (*(book+i)).name);
        printf("|%-11d", (*(book+i)).year);
        printf("|%-11s", (*(book+i)).publisher);
        printf("|%-10.2f|\n", (*(book+i)).price);
        numberOfBooks++;
    }
    printf("+----------------------------------------------+\n");
    printf("%d book(s) found \n", numberOfBooks);
}
void sort(struct Book* book) {
    int i, j;
    for(i = 0; i < N-1; i++){
        for (j = i + 1; j < N; j++) {
            if(strcmp( (book+i)->name, (book + j)->name) > 0) {
                struct Book temp;
                //swap data between book[i] and book[j]
                temp = *(book + i);
                *(book + i) = *(book + j);
                *(book + j) = temp;
            }
        }
    }
    display(book);
}
void find(struct Book* book){
    printf("Find some books");
    struct Book *bookResults = (struct Book *)malloc(N * sizeof(struct Book));
    struct Book *ptr;
    float maxPrice, minPrice;
    char publisher[200];
    printf("Book's publisher: "); scanf("%s", publisher);
    printf("Enter min price: "); scanf("%f", &minPrice);
    printf("Enter max price: "); scanf("%f", &maxPrice);
    ptr = bookResults;
    int i = 0;
    for (i = 0; i < N; i++) {
        if(strcmp((book+i)->publisher, publisher) == 0 &&
           (book + i)->price >= minPrice && (book+i)->price <= maxPrice) {
            *ptr = *(book + i);
            ptr++;
        }
    }
    printf("Search result : \n");
    display(bookResults);
}
void analyze(struct Book* book) {
    char publishers[N][250]; //1.create an array of "publishers"
    int i,j;
    for (i = 0; i < N; i++) {
        strcpy(publishers[i], (book+i)->publisher);
    }
    //2.sort ascending(alphabet)
    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            if(strcmp(publishers[i], publishers[j]) > 0) {
                char temp[150];
                //swap publishers[i] and publishers[j]
                strcpy(temp, publishers[i]);
                strcpy(publishers[i], publishers[j]);
                strcpy(publishers[j], temp);
            }
        }
    }
    printf("Statistics Result: \n");
    char publisherName[150];
    int count = 0;
    for (i = 0; i < N; i++) {
        if(i == 0) {
            strcpy(publisherName, publishers[i]);
            count++;
        } else if(strcmp(publishers[i], publisherName) != 0){
            printf("+There are %d Book(s) published by %s\n", count, publisherName);
            strcpy(publisherName, publishers[i]);
            count = 1;
        } else if(strcmp(publishers[i], publisherName) == 0) {
            count++;
        }
    }
    if(N >0){
        printf("+There are %d Book(s) published by %s\n", count, publisherName);
    }
}
void save(struct Book* book) {
    char fileName[250];//Include detail path
    printf("Enter file name: "); scanf("%s", fileName);
    FILE* file = fopen(fileName, "wb"); //wb = write binary
    if(file == NULL){
        printf("Cannot open file %s\n", fileName);
    } else{
        fwrite(book, sizeof(struct Book *), N, file);
        fclose(file);
        printf("Data is saved successfully \n");
    }
}
void openFile(struct Book *book) {
    char fileName[250];
    printf("Enter file name to open : "); scanf("%s", fileName);
    FILE *file = fopen(fileName,"rb"); // r for read, b for binary
    if (!file) {
        printf("Cannot open file %s\n", fileName);
    } else {
        fread(book, sizeof(struct Book), N, file);
        display(book);
        fclose(file);
    }
}
