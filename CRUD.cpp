// CRUD.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include <string>
#include <stdlib.h>
using namespace std;
struct student
{
	char ID[20];
	char Fname[20];
	char Lname[20];
	char Phone[20];
	char Year;
	float GradeAVG;
	struct student* Next;
};

student *createnew(char ID[], char Fname[], char Lname[], char Phone[], char Year, float GradeAVG)
{
	struct student *Nstudent = new student;
	strcpy_s(Nstudent->ID, ID);
	strcpy_s(Nstudent->Fname, Fname);
	strcpy_s(Nstudent->Lname, Lname);
	strcpy_s(Nstudent->Phone, Phone);
	Nstudent->Year = Year;
	Nstudent->GradeAVG = GradeAVG;
	Nstudent->Next = NULL;
	return Nstudent;
}

student* insertnew(student *head, char ID[], char Fname[], char Lname[], char Phone[], char Year, float GradeAVG) {
	if (!head)
		return  createnew(ID, Fname, Lname, Phone, Year, GradeAVG);
	if (!head->Next) {
		head->Next = createnew(ID, Fname, Lname, Phone, Year, GradeAVG);
		return head->Next;
	}
	insertnew(head->Next, ID, Fname, Lname, Phone, Year, GradeAVG);

}
void printclass(student *head) {
	if (!head)
		return;
	printf("ID=>%s\nFname=>%s\nLname=>%s\nPhone=>%s\nYear=>%c\n Average Grade=>%.1f\n--------------------------------------------------\n",
		head->ID,
		head->Fname,
		head->Lname,
		head->Phone,
		head->Year,
		head->GradeAVG);
	printclass(head->Next);
}
void printstudent(student *head) {
	printf("ID=>%s\nFname=>%s\nLname=>%s\nPhone=>%s\nYear=>%c\n Average Grade=>%.1f\n--------------------------------------------------\n",
		head->ID,
		head->Fname,
		head->Lname,
		head->Phone,
		head->Year,
		head->GradeAVG);
}
void readclass(student *head, char ID[])
{
	if (!head) {
		printf("NotFound!!!!\n");
		return;
	}
	if (!strcmp(ID, head->ID)) {
		printstudent(head);
		return;
	}
	readclass(head->Next, ID);
}
int main()
{
	student *BootCamp = NULL;
	BootCamp = insertnew(BootCamp, "204419477\0", "Mahmoud\0", "Weshah\0", "0585633467\0", 'A', 55.5);
	insertnew(BootCamp, "204419477\0", "hello\0", "Weshah\0", "0585633467\0", 'A', 55.5);
	insertnew(BootCamp, "204419477\0", "a\0", "Weshah\0", "0585633467\0", 'A', 55.5);
	insertnew(BootCamp, "204419477\0", "b\0", "Weshah\0", "0585633467\0", 'A', 55.5);
	insertnew(BootCamp, "5\0", "c\0", "Weshah\0", "0585633467\0", 'A', 55.5);
	readclass(BootCamp, "4");//Looks for a specific ID for a student while the string is the ID and the bootcamp is the class list
	printclass(BootCamp);//Prints the whole class as in all the students in the class
	return 0;
}

