#include "Header.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>
#include <list>

using namespace std;

list<Employee> employees;
const string fileName = "Employee.txt";

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		int currentString = 0;
		string data;
		Employee oldEmployee;
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
			if (currentString == 1)
			{
				oldEmployee.name = data;
			}
			else if (currentString == 2)
			{
				oldEmployee.surname = data;
			}
			else if (currentString == 3)
			{
				oldEmployee.education = data;
			}
			else if (currentString == 4)
			{
				oldEmployee.age = data;
			}
			else if (currentString == 5)
			{
				oldEmployee.createDateOfBirth.day = data;
			}
			else if (currentString == 6)
			{
				oldEmployee.createDateOfBirth.month = data;
			}
			else if (currentString == 7)
			{
				oldEmployee.createDateOfBirth.year = data;
				currentString = 0;
				employees.push_back(oldEmployee);
				oldEmployee = Employee();
			}
		}
	}
	fin.close();
}

void addNewEmployee()
{
	Employee newEmployee;
	cout << "Name of new employee -> ";
	cin >> newEmployee.name;
	cout << "Surname of new employee -> ";
	cin >> newEmployee.surname;
	cout << "Education of new employee -> ";
	cin.ignore();
	getline(cin, newEmployee.education);
	cout << "Age of new employee -> ";
	cin >> newEmployee.age;
	cout << "Date of birth of new employee:" << endl;
	cout << "Day -> ";
	cin >> newEmployee.createDateOfBirth.day;
	cout << "Month -> ";
	cin >> newEmployee.createDateOfBirth.month;
	cout << "Yera -> ";
	cin >> newEmployee.createDateOfBirth.year;
	employees.push_back(newEmployee);

	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << "Error: Application can't connect to database file" << endl;
	}
	else
	{
		cout << "File open!" << endl;
		fout << newEmployee.name << endl;
		fout << newEmployee.surname << endl;
		fout << newEmployee.education << endl;
		fout << newEmployee.age << endl;
		fout << newEmployee.createDateOfBirth.day << endl;
		fout << newEmployee.createDateOfBirth.month << endl;
		fout << newEmployee.createDateOfBirth.year << endl;
	}
	fout.close();
	cout << "New employee seccessful added..." << endl;
	PAUSE
	CLEAR
}

void listEmployee()
{
	int i = 0;
	for (Employee item : employees)
	{
		cout << ++i << " " << item.name << "\t" << item.surname << "\t" << item.education << "\t" << item.age << "\t" << item.createDateOfBirth.day << "\t" << item.createDateOfBirth.month << "\t" << item.createDateOfBirth.year << endl;
	}
	cout << endl;
}

void EmployeeListBySurname()
{
	cout << "Enter surname" << endl;
	int i = 0;
	string surnam;
	cin >> surnam;
	for (Employee item : employees)
	{
		if(item.surname == surnam)
		cout << ++i << " " << item.name << "\t" << item.surname << "\t" << item.education << "\t" << item.age << "\t" << item.createDateOfBirth.day << "\t" << item.createDateOfBirth.month << "\t" << item.createDateOfBirth.year << endl;
	}
	cout << endl;
}

void EmployeeListByAge()
{
	cout << "Enter age" << endl;
	int i = 0;
	string age;
	cin >> age;
	for (Employee item : employees)
	{
		if (item.age == age)
			cout << ++i << " " << item.name << "\t" << item.surname << "\t" << item.education << "\t" << item.age << "\t" << item.createDateOfBirth.day << "\t" << item.createDateOfBirth.month << "\t" << item.createDateOfBirth.year << endl;
	}
	cout << endl;
}

void EmployeeListByLetter()
{
	//cout << "Enter letter" << endl;
	//char letter;
	//cin >> letter;
	//fstream fs;
	//fs.open(fileName, fstream::in | fstream::out);
	//bool isOpen = fs.is_open();
	//if (isOpen == false)
	//{
	//	cout << "Error: Application can't connect to database file" << endl;
	//}
	//else
	//{
	//	int currentString = 0;
	//	string data2;
	//	bool w = false;
	//	while (!fs.eof())
	//	{
	//		currentString++;
	//		getline(fs, data2);
	//		if (currentString == 1 && data2[0] == letter)
	//		{
	//			if (currentString == 1 && data2[0] == letter)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 2)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 3)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 4)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 5)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 6)
	//			{
	//				cout << data2 << "\t";
	//			}
	//			else if (currentString == 7)
	//			{
	//				cout << data2 << "\t";
	//				currentString = 0;
	//			}
	//		}
	//	}
	//	//cout << i << endl;
	//}
	//fs.close();

	cout << "Enter letter" << endl;
	char letter;
	cin >> letter;
	for (Employee item : employees)
	{
		if (item.surname[0] == letter)
		{
			cout << item.name << "\t" << item.surname << "\t" << item.education << "\t" << item.age << "\t" << item.createDateOfBirth.day << "\t" << item.createDateOfBirth.month << "\t" << item.createDateOfBirth.year << endl;
		}
	}
	cout << endl;
}

void deleteEmployeeByName()
{
	cout << "Enter the name wich employee you want delete" << endl;
	string name;
	cin >> name;
	for (Employee item : employees)
	{
		if (item.surname == name)
		{
			//cout << item.name << "\t" << item.surname << "\t" << item.education << "\t" << item.age << "\t" << item.createDateOfBirth.day << "\t" << item.createDateOfBirth.month << "\t" << item.createDateOfBirth.year << endl;
		}
	}
	cout << endl;

}




