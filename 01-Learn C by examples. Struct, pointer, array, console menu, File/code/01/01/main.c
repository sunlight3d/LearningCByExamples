
#include "bookManagement.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    struct Book* book = NULL;
    LABEL1:
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                         BOOK MANAGEMENT                                 |\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("+ 1.Input books | 2.Sort | 3.Analyze | 4.Find. | 5.Save | 6.Open | 7.Exit +\n");
    printf("+-------------------------------------------------------------------------+\n");
    char choice;
    printf("Enter your choice: "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
            book = input();
            //Now test "display" function
            display(book);
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
    //You can add multiple Labels as you like !
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
    switch (choice) {
        case 'y':
        case 'Y':
            goto LABEL1;
            break;
        case 'n':
        case 'N':
            return 0;
            break;
        case 'c':
        case 'C':
            //clear screen
            //system("cls"); //Windows
            system("clear");//Linux + MacOS
            goto LABEL1;
            break;
        default:
            goto LABEL2;
            break;
    }
    return 0;
}
