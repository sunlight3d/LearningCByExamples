#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define CURRENT_YEAR 2020
struct Student {
	char name[150];
	char province[100];
	int year_of_birth;
	//1 student has 1 mark
	struct Mark* mark;
};
struct Mark {
	float math;
	float physics;
	float chemistry;
};
void printResult(struct Student* students, int numberOfStudents) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("+----------------------------------------------------------------------------------+\n");
		printf("|Student's Name    |Province   |Year of Birth    |Math     |Physics     |Chemistry \n");
		printf("|%17s |%10s |%16d |%8.2f |%11.2f |%10.2f\n",
			currentStudent->name, currentStudent->province,
			currentStudent->year_of_birth, currentStudent->mark->math, currentStudent->mark->physics,
			currentStudent->mark->chemistry
		);
		printf("+----------------------------------------------------------------------------------+\n");
	}
}
void input(struct Student* students, int numberOfStudents) {
	//input and validations
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* currentStudent = students + i;
		printf("\nEnter student's name : "); gets(currentStudent->name);
		while (1) {
			if(gets(currentStudent->name) != NULL) break;
		}
		printf("\nEnter student's province : "); gets(currentStudent->province);		
		//validate: age must be 18->45
		do
		{
			printf("\nEnter student's year of birth : "); scanf_s("%d", &currentStudent->year_of_birth);
		} while (CURRENT_YEAR - currentStudent->year_of_birth < 18 
			|| CURRENT_YEAR - currentStudent->year_of_birth > 45);
		printf("\nEnter student's mark : \n");
		currentStudent->mark = (struct Mark*)malloc(sizeof(struct Mark)); //alloc 1 object of Mark
		do
		{
			printf("\nEnter your math's mark : "); scanf_s("%f", &currentStudent->mark->math);
		} while (currentStudent->mark->math >10 || currentStudent->mark->math < 0);
		do
		{
			printf("\nEnter your physics's mark : "); scanf_s("%f", &currentStudent->mark->physics);
		} while (currentStudent->mark->physics > 10 || currentStudent->mark->physics < 0);
		do
		{
			printf("\nEnter your chemistry's mark : "); scanf_s("%f", &currentStudent->mark->chemistry);
		} while (currentStudent->mark->chemistry > 10 || currentStudent->mark->chemistry < 0);
		
		//validate mark ?. Mark must be between 0 to 10
	}
	printResult(students, numberOfStudents);
}
void sort(struct Student* students, int numberOfStudents) {
	int i, j;
	for (i = 0; i < numberOfStudents - 1; i++) {
		for (j = i + 1; j < numberOfStudents; j++) {
			struct Student* si = students + i;
			struct Student* sj = students + j;
			float totalI = si->mark->math + si->mark->physics + si->mark->chemistry;
			float totalJ = sj->mark->math + sj->mark->physics + sj->mark->chemistry;
			if (totalI < totalJ) {
				//swap 2 students
				struct Student temp = *si;
				*si = *sj;
				*sj = temp;
			}
		}
	}
	printResult(students, numberOfStudents);
}
void analyze(struct Student* students, const int numberOfStudents) {
	//Calculate students by provinces
	//1.create an array of provinces from students array
	int i,j;
	char* provinces[100];//array of string in C
	for (i = 0; i < numberOfStudents; i++) {
		provinces[i] = malloc(sizeof(char) * 100);
		//"safe" strcpy
		strcpy_s(provinces[i], 100, (students+i)->province);
	}
	//2.Sort provinces by ascending(descending)
	for (i = 0; i < numberOfStudents - 1; i++) {
		for (j = i + 1; j < numberOfStudents; j++) {
			//bubble sort 
			if (strcmp(provinces[i], provinces[j]) > 0) {
				//swap 2 string
				char temp[100];
				strcpy_s(temp, 100, provinces[i]);
				strcpy_s(provinces[i], 100, provinces[j]);
				strcpy_s(provinces[j], 100, temp);
			}
		}
	}
	//3.Analyze students by provinces
	int count = 0;
	char selectedProvince[100];
	for (i = 0; i < numberOfStudents; i++) {
		if (i == 0) {
			strcpy_s(selectedProvince,100, provinces[i]);
			count = 1;
		} else if (strcmp(selectedProvince, provinces[i]) != 0) {
			printf("There are %d students from %s\n", count, selectedProvince);
			//update "selectedProvince"
			strcpy_s(selectedProvince, 100, provinces[i]);
			count = 1;
		} else if (strcmp(selectedProvince, provinces[i]) == 0) {
			count++;
		}
	}
	if (numberOfStudents > 0) {
		printf("There are %d students from %s\n", count, selectedProvince);
	}
}
void find(struct Student* students, int numberOfStudents) {
	char province[100];
	printf("Enter province : "); gets(province);
	while (1){
		if (gets(province) != NULL) break;
	}
	float min, max;
	printf("Enter min(marks) : "); scanf_s("%f", &min);
	printf("Enter max(marks) : "); scanf_s("%f", &max);
	//Search Result
	struct Student* result = malloc(sizeof(struct Student) * numberOfStudents);
	int i, j; j = 0;
	for (i = 0; i < numberOfStudents; i++) {
		struct Student* selectedStudent = (students + i);
		float totalMark = selectedStudent->mark->math + selectedStudent->mark->physics
			+ selectedStudent->mark->chemistry;
		if (totalMark >= min && totalMark <= max && 
			strcmp(selectedStudent->province, province) == 0) {
			*(result + i) = *selectedStudent;
			j++;//number of found students
		}
	}
	if (j == 0) {
		printf("Cannot find students");
	}
	else {
		printResult(result, j);
	}
}
void save(struct Student* students, int numberOfStudents) {
	char fileName[250] = "";
	printf("Enter file name: "); 
	gets(fileName);
	while (1){
		if (gets(fileName) != NULL) break;
	}
	//FILE* file = fopen(fileName, "wb"); //wb = write binary
	FILE* file;
	if (file = fopen(fileName, "wb") == NULL) {
		printf("Cannot open file for saving");
	}
	else {
		//save students to this file, then close
		fwrite(students, sizeof(struct Student), numberOfStudents, fileName);
		fclose(fileName);
		printf("Data is saved successfully \n");
	}
}
int main() {	
	char choice;
	int numberOfStudents;
	struct Student* students = NULL;
	do {
		//create a "console menu":
		printf("+----------------------------------------------------------------+\n");
		printf("+-----------------------STUDENT MANAGEMENT-----------------------+\n");
		printf("+----------------------------------------------------------------+\n");
		printf("|1.Input  |2.Sort  |3.Analyze  |4.Find  |5.Save  |6.Open  |7.Exit \n");
		printf("Enter your choice : ");
		fflush(stdin); 
		//remove "enter" button
		choice = getchar();
		while (choice == '\n') {
			choice = getchar();
		}		
		switch (choice) {
		case '1':
			printf("Number of students : "); scanf_s("%d", &numberOfStudents);
			fflush(stdin);
			//memory allocation
			students = (struct Student*)malloc(sizeof(struct Student) * numberOfStudents);
			input(students, numberOfStudents);
			break;
		case '2':
			//sort ascending by total mark?
			if (students != NULL && numberOfStudents > 0) {
				sort(students, numberOfStudents);
			}
			break;
		case '3':
			//How many students in Hanoi, Haiduong, ....?
			//calculate students by provinces
			if (students != NULL && numberOfStudents > 0) {
				analyze(students, numberOfStudents);
			}
			break;
		case '4':
			//find students by name and province
			find(students, numberOfStudents);
			break;
		case '5':
			//Save struct Students to a "binary" file 
			save(students, numberOfStudents);
			break;
		case '6':
			printf("You choose Open\n");
			break;
		default:
			break;
		}
		printf("Do you want to continue ?\n");
		printf("Yes, I do (press 'y' or 'Y') \n");		
		printf("No, I don't (press 'n' or 'N') \n");
		printf("Clear the screen (press 'c' or 'C') \n");
		printf("Your choice : ");
		fflush(stdin);
		//remove "enter" button
		choice = getchar();
		while (choice =='\n') {
			choice = getchar();
		}	
		if (choice == 'c' || choice == 'C') {
			system("cls"); //system("clear") in Linux/MacOS
		}
	} while (choice != 'n' && choice != 'N');
	
	
}