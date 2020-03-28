#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

struct DateOfBirth
{
	string day;
	string month;
	string year;
};

struct Employee
{
	string name;
	string surname;
	string education;
	string age;
	DateOfBirth createDateOfBirth;
};

void init();
void addNewEmployee();
void listEmployee();
void EmployeeListBySurname();
void EmployeeListByAge();
void EmployeeListByLetter();
void editEmployee();
void deleteEmployeeByName();


