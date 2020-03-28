#include "Header.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

Employee *employee;
int countEmployee;

void init()
{
	int currentString = 0;
	int currentString2 = 0;
	string data;
	ifstream fin;
	fin.open("Employee.txt");
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
		}
		currentString2 = (currentString - 1) / 7;
		currentString = 0;
	}
	fin.close();
	countEmployee = currentString2;
	Employee *temp1 = new Employee[currentString2];
	int f = 0;
	fin.open("Employee.txt");
	bool isOpenn = fin.is_open();
	if (isOpenn == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
			for (int i = f; i < currentString2;)
			{
				if (currentString == 1)
				{
					temp1[i].name = data;
					break;
				}
				else if (currentString == 2)
				{
					temp1[i].surname = data;
					break;
				}
				else if (currentString == 3)
				{
					temp1[i].education = data;
					break;
				}
				else if (currentString == 4)
				{
					temp1[i].age = data;
					break;
				}
				else if (currentString == 5)
				{
					temp1[i].createDateOfBirth.day = data;
					break;
				}
				else if (currentString == 6)
				{
					temp1[i].createDateOfBirth.month = data;
					break;
				}
				else if (currentString == 7)
				{
					temp1[i].createDateOfBirth.year = data;
					currentString = 0;
					f++;
					break;
				}
			}
		}
		employee = temp1;
	}
	fin.close();
}

void addNewEmployee()
{
	ofstream fout;
	fout.open("Employee.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		Employee *temp = new Employee[countEmployee + 1];
		for (int i = 0; i < countEmployee; i++)
		{
			temp[i] = employee[i];
		}

		//Вносимо данні про нову вікторину
		cout << "Enter name of new employee" << endl;
		cin >> temp[countEmployee].name;
		cout << "Enter surname of new employee" << endl;
		cin >> temp[countEmployee].surname;
		cout << "Enter education of new employee" << endl;
		cin >> temp[countEmployee].education;
		cout << "Enter age of new employee" << endl;
		cin >> temp[countEmployee].age;
		cout << "Enter data of birth of new employee" << endl;
		cout << "Enter day --> ";
		cin >> temp[countEmployee].createDateOfBirth.day;
		cout << "Enter month --> ";
		cin >> temp[countEmployee].createDateOfBirth.month;
		cout << "Enter year --> ";
		cin >> temp[countEmployee].createDateOfBirth.year;

		fout << temp[countEmployee].name << endl;
		fout << temp[countEmployee].surname << endl;
		fout << temp[countEmployee].education << endl;
		fout << temp[countEmployee].age << endl;
		fout << temp[countEmployee].createDateOfBirth.day << endl;
		fout << temp[countEmployee].createDateOfBirth.month << endl;
		fout << temp[countEmployee].createDateOfBirth.year << endl;

		fout.close();
		countEmployee++;
		delete[] employee;
		employee = temp;
		cout << "Employee successfully added..." << endl;
		PAUSE
		CLEAR
	}
	else
	{
		cout << "Error" << endl;
	}
}

void listEmployee()
{
	for (int i = 0; i < countEmployee; i++)
	{
		cout << i << ") " << employee[i].name
			<< "\t" << employee[i].surname
			<< "\t" << employee[i].education
			<< "\t" << employee[i].age
			<< "\t" << employee[i].createDateOfBirth.day
			<< ":" << employee[i].createDateOfBirth.month
			<< ":" << employee[i].createDateOfBirth.year << endl;
	}
}

void EmployeeListBySurname()
{
	string surname;
	cout << "Enter surname which employee you want to find" << endl;
	cin >> surname;
	for (int i = 0; i < countEmployee; i++)
	{
		if (employee[i].surname == surname)
		{
			cout << employee[i].name
				<< "\t" << employee[i].surname
				<< "\t" << employee[i].education
				<< "\t" << employee[i].age
				<< "\t" << employee[i].createDateOfBirth.day
				<< ":" << employee[i].createDateOfBirth.month
				<< ":" << employee[i].createDateOfBirth.year << endl;
		}
	}
}

void EmployeeListByAge()
{
	string age;
	cout << "Enter age which employee you want to find" << endl;
	cin >> age;
	for (int i = 0; i < countEmployee; i++)
	{
		if (employee[i].age == age)
		{
			cout << employee[i].name
				<< "\t" << employee[i].surname
				<< "\t" << employee[i].education
				<< "\t" << employee[i].age
				<< "\t" << employee[i].createDateOfBirth.day
				<< ":" << employee[i].createDateOfBirth.month
				<< ":" << employee[i].createDateOfBirth.year << endl;
		}
	}
}

void EmployeeListByLetter()
{
	char letter;
	cout << "Enter first letter of surnafe of employee which you want to find" << endl;
	cin >> letter;
	for (int i = 0; i < countEmployee; i++)
	{
		if (employee[i].surname[0] == letter)
		{
			cout << employee[i].name
				<< "\t" << employee[i].surname
				<< "\t" << employee[i].education
				<< "\t" << employee[i].age
				<< "\t" << employee[i].createDateOfBirth.day
				<< ":" << employee[i].createDateOfBirth.month
				<< ":" << employee[i].createDateOfBirth.year << endl;
		}
	}
}

void editEmployee()
{
	int finish = 0;
	int count = 0;
	int count2 = 0;
	string edit;
	do
	{
		cout << "Edit employee" << endl;
		listEmployee();
		cout << "You want to exit? 1 - yes; 2 - no" << endl;
		cin >> finish;
		if (finish == 1)
		{
			ofstream fout;
			fout.open("Employee.txt");
			bool isOpen = fout.is_open();
			if (isOpen == false)
			{
				cout << "Error" << endl;
			}
			else
			{
				for (int i = 0; i < countEmployee; i++)
				{
					fout << employee[i].name << endl;
					fout << employee[i].surname << endl;
					fout << employee[i].education << endl;
					fout << employee[i].age << endl;
					fout << employee[i].createDateOfBirth.day << endl;
					fout << employee[i].createDateOfBirth.month << endl;
					fout << employee[i].createDateOfBirth.year << endl;
				}
			}
			fout.close();
			PAUSE
			CLEAR
			break;
		}
		else if (finish == 2)
		{
			cout << "Enter number of employee which you want to edit" << endl;
			cin >> count;
			cout << "Chose what you want to edit:" << endl;
			cout << "1 - edit name" << endl;
			cout << "2 - edit surnema" << endl;
			cout << "3 - edit education" << endl;
			cout << "4 - edit age" << endl;
			cout << "5 - edit day of birth" << endl;
			cout << "6 - edit month of birth" << endl;
			cout << "7 - edit year of birth" << endl;
			cout << "0 - exit" << endl;
			cin >> count2;
			switch (count2)
			{
			case 1:
			{
				CLEAR
					cout << "Enter the name you want to change" << endl;
				cin >> edit;
				employee[count].name = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 2:
			{
				CLEAR
					cout << "Enter the surname you want to change" << endl;
				cin >> edit;
				employee[count].surname = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 3:
			{
				CLEAR
					cout << "Enter the education you want to change" << endl;
				cin >> edit;
				employee[count].education = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 4:
			{
				CLEAR
					cout << "Enter the age you want to change" << endl;
				cin >> edit;
				employee[count].age = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 5:
			{
				CLEAR
					cout << "Enter the day of birth you want to change" << endl;
				cin >> edit;
				employee[count].createDateOfBirth.day = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 6:
			{
				CLEAR
					cout << "Enter the edit month of birth you want to change" << endl;
				cin >> edit;
				employee[count].createDateOfBirth.month = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 7:
			{
				CLEAR
					cout << "Enter the edit year of birth you want to change" << endl;
				cin >> edit;
				employee[count].createDateOfBirth.year = edit;
				cout << "Changes completed successfully" << endl;
				PAUSE
					CLEAR
			}
			break;
			case 0:
			{
				break;
			}
			break;
			default:
				break;
			}
		}
	} while (count2 != 0);
}

void deleteEmployeeByName()
{
	int count = 0;
	cout << "All employees: " << endl;
	listEmployee();
	cout << endl;
	cout << "Which employee you want to delete" << endl;
	cin >> count;
	Employee *temp2 = new Employee[countEmployee - 1];
	for (int i = 0, j = 0; i < countEmployee; i++)
	{
		if (i != count)
		{
			temp2[j] = employee[i];
			j++;
		}
	}
	countEmployee--;
	delete[]employee;
	employee = temp2;
	ofstream fout;
	fout.open("Employee.txt");
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		for (int i = 0; i < countEmployee; i++)
		{
			fout << employee[i].name << endl;
			fout << employee[i].surname << endl;
			fout << employee[i].education << endl;
			fout << employee[i].age << endl;
			fout << employee[i].createDateOfBirth.day << endl;
			fout << employee[i].createDateOfBirth.month << endl;
			fout << employee[i].createDateOfBirth.year << endl;
		}
	}
	fout.close();
	cout << "Removal successfully completed" << endl;
	PAUSE
	CLEAR
}
