#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char name[220];
    char publisher[250];
    int year;
    float price;
};

int N;//bien toan cuc, co tac dung ben trong main.c
struct Book* input(){
    printf("Numbers of books : ");scanf("%d", &N);
    struct Book *book = (struct Book *)malloc(N * sizeof(struct Book));
    int i;
    for (i = 0; i < N; i++){
        INPUT_ONE: printf("Book number %d :\n", i+1);
        printf("Enter book's name : ");scanf("%s", (*(book+i)).name);
        printf("Enter book's year : ");scanf("%d", &((*(book+i)).year));
        if((*(book+i)).year <= 2000)  {
            printf("Year must be > 2000\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
        printf("Enter book's publisher :");scanf("%s", (*(book+i)).publisher);
        printf("Enter book's price($) :");scanf("%f", &(*(book+i)).price);
        if((*(book+i)).price < 100 ||
            (*(book+i)).price > 200 ) {
            printf("Price >= 100, price <= 200\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
    }
    return book;
}

void display(struct Book *book) {
    int i, numberOfBooks;
    numberOfBooks = 0;
    printf("+----------------------------------------------+\n");
    printf("|Name       |Year       |Publisher  |Price     |\n");
    printf("+----------------------------------------------+\n");
    for(i = 0; i < N && strcmp((book+i)->name, "") != 0; i++){
        printf("|%-11s", (*(book+i)).name);
        //printf("|%12s", book->name);
        printf("|%-11d", (*(book+i)).year);
        printf("|%-11s", (*(book+i)).publisher);
        printf("|%-10.2f|\n", (*(book+i)).price);
        numberOfBooks++;
    }
    printf("+----------------------------------------------+\n");
    printf("%d book(s) found\n", numberOfBooks);
}
void sort(struct Book* book){
    int i, j;
    struct Book *ptr = book;
    for(i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            if(strcmp((*(ptr+i)).name, (*(ptr+j)).name) > 0) {
                struct Book temp;
                temp = *(ptr +i);
                *(ptr +i) = *(ptr +j);
                *(ptr +j) = temp;
            }
        }
    }
    display(book);
}
void analyze(struct Book *book){
    int i, j;
    char publishers[N][150];//Create an array which contains "publishers"
    for (i = 0; i < N; i++) {
        strcpy(publishers[i], (*(book+i)).publisher);
    }
    //sort ascending
    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            if(strcmp(publishers[i], publishers[j]) > 0) {
                char temp[150];
                strcpy(temp, publishers[i]);
                strcpy(publishers[i], publishers[j]);
                strcpy(publishers[j], temp);
            }
        }
    }
    printf("Statistics Result:\n");
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
    if(N > 0) {
        printf("+There are %d Book(s) published by %s\n", count, publisherName);
    }
}
void find(struct Book *book) {
    printf("Find some books \n");
    struct Book *bookResults = (struct Book *)malloc(N * sizeof(struct Book));
    struct Book *ptr;
    int i = 0;
    float maxPrice, minPrice;
    char publisher[200];
    
    printf("Book's publisher: "); scanf("%s", publisher);
    printf("Enter min price: "); scanf("%f", &minPrice);
    printf("Enter max price: "); scanf("%f", &maxPrice);
    ptr = bookResults;
    int j = 0; //Tong so ket qua
    for(i = 0; i < N; i++){
        if(strcmp((*(book+i)).publisher, publisher) == 0 &&
           (*(book+i)).price >= minPrice && (*(book+i)).price <= maxPrice ){
            *ptr = *(book+i);
            ptr++;
            j++;
        }
    }
    printf("Search result : \n");
    display(bookResults);
}
void save(struct Book *book){
    char fileName[250];
    printf("Enter file name : "); scanf("%s", fileName);
    FILE *file = fopen(fileName,"wb"); // w for write, b for binary
    if (!file) {
        printf("Cannot open file %s\n", fileName);
        exit(1);
    } else {
        fwrite(book, sizeof(struct Book *), N, file);
        fclose(file);
        printf("Data is saved successfully \n");
    }
}

void openFile(struct Book *book) {
    char fileName[250];
    printf("Enter file name to open : "); scanf("%s", fileName);
    FILE *file = fopen(fileName,"rb"); // w for write, b for binary
    if (!file) {
        printf("Cannot open file %s\n", fileName);
    } else {
        fread(book, sizeof(struct Book), N, file);
        display(book);
        fclose(file);
    }
}
int main(int argc, char * argv[]) {
    struct Book *book = NULL;
    char choice;
    
    LABEL1:
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                         BOOK MANAGEMENT                                 |\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("+ 1.Input books | 2.Sort | 3.Analyze | 4.Find. | 5.Save | 6.Open | 7.Exit +\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("Enter your choice : "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
            book = input();
            goto LABEL2;
            break;
        case '2':
            sort(book);
            goto LABEL2;
            break;
        case '3':
            analyze(book);
            goto LABEL2;
            break;
        case '4':
            find(book);
            goto LABEL2;
            break;
        case '5':
            save(book);
            goto LABEL2;
            break;
        case '6':
            openFile(book);
            goto LABEL2;
            break;
        case '7':
            return 0;
            break;
        default:
            goto LABEL2;
            break;
    }
    LABEL2:
    printf("Do you want to continue ?\n");
    printf("- Yes, I do. (press ‘y’, ‘Y’)\n");
    printf("- No, I don’t. (press ‘n’, ‘N’)\n");
    printf("- Clear the screen ! (press ‘c’, ‘C’)\n");
    printf("Your choice: ");
    choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch(choice) {
        case 'y':
        case 'Y':
            goto LABEL1;
            break;
        case 'n':
        case 'N':
            break;
        case 'c':
        case 'C':
            //clear screen
            system("clear");//Linux+MacOS
            //system("cls");//Windows
            goto LABEL1;
            break;
        default:
            goto LABEL2;
            break;
    }
    return 0;
}

