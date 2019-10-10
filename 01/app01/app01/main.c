#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char name[120];
    char publisher[150];
    int year;
    float price;
};

int N;//bien toan cuc, co tac dung ben trong main.c
struct Book *input(){
    printf("Numbers of books : ");scanf("%d", &N);
    struct Book *book = (struct Book *)malloc(N * sizeof(struct Book));
    int i;
    for (i = 0; i < N; i++){
        printf("Book number %d :\n", i+1);
        printf("Enter book's name : \n");scanf("%s", (*(book+i)).name);
        printf("Enter book's year : \n");scanf("%d", &((*(book+i)).year));
        printf("Enter book's publisher : \n");scanf("%s", (*(book+i)).publisher);
        printf("Enter book's price : \n");scanf("%f", &(*(book+i)).price);
    }
    return book;
}
void sort(struct Book *book){
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
    printf("Sort finished\n");
}
void display(struct Book *book) {
    int i;
    for(i = 0; i < N; i++){
        printf("Book's name : %s\n", (*(book+i)).name);
        printf("Book's year : %d\n", (*(book+i)).year);
        printf("Book's publisher : %s\n", (*(book+i)).publisher);
    }
}
void find(struct Book *book) {
    printf("Find some books \n");
    struct Book *bookResults = (struct Book *)malloc(sizeof(struct Book));
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
            ptr = (struct Book *)malloc(sizeof(struct Book));
            ptr++;
            j++;
        }
    }
    printf("Search result : \n");
    for(i = 0; i < j; i++){
        printf("Book's name : %s\n", (*(book+i)).name);
        printf("Book's year : %d\n", (*(book+i)).year);
        printf("Book's publisher : %s\n", (*(book+i)).publisher);
        printf("Book's price : %f\n", (*(book+i)).price);
    }
}
void save(struct Book *book){
    char fileName[100];
    char filePath[250];
    printf("Enter file name : "); scanf("%s", fileName);
    strcat(filePath, "/Users/hoangnd/Documents/tutorials/AptechPTTH/"); //MacOS+Linux
    //strcat(filePath, "D:\\");//Windows
    strcat(filePath, fileName);
    FILE *file = fopen(filePath,"wb"); // w for write, b for binary
    if (!file) {
        printf("Cannot open file %s\n", fileName);
        exit(1);
    } else {
        fwrite(book, sizeof(struct Book *), N, file);
    }
    fclose(file);
    printf("Save finished\n");
}

void openFile(struct Book *book) {
    char fileName[100];
    char filePath[250];
    printf("Enter file name to open : "); scanf("%s", fileName);
    //strcat(filePath, "/Users/hoangnd/Documents/tutorials/AptechPTTH/"); //MacOS+Linux
    strcat(filePath, "D:\\");//Windows
    strcat(filePath, fileName);
    FILE *file = fopen(filePath,"rb"); // w for write, b for binary
    
    if (!file) {
        printf("Cannot open file %s\n", fileName);
        exit(1);
    } else {
        fread(book, sizeof(struct Book), N, file);
    }
    fclose(file);
}
int main(int argc, char * argv[]) {
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                         BOOK MANAGEMENT                                 |\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("+ 1.Input books | 2.Sort | 3.Analyze | 4.Find. | 5.Save | 6.Open | 7.Exit +\n");
    printf("+-------------------------------------------------------------------------+\n");
    struct Book *book = NULL;
    char choice;
    LABEL1: printf("Enter your choice : "); choice = getchar();
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
            display(book);
            goto LABEL2;
            break;
        case '4':
            find(book);
            goto LABEL2;
            break;
        case '5':
            return 0;
            break;
        case '6':
            
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
            break;
        default:
            break;
    }
    return 0;
}

