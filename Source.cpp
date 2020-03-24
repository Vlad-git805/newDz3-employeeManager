#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;

void main()
{
	init();
	int a = 0;
	do
	{
		cout << "1 - Add new employee" << endl;
		cout << "2 - list of employee" << endl;
		cout << "3 - list employee by surname" << endl;
		cout << "4 - list employee by age" << endl;
		cout << "5 - list employee by first letter of surname" << endl;
		cout << "0 - exit" << endl;
		cin >> a;
		CLEAR
		switch (a)
		{
		case 1:
		{
			cout << "Add employee" << endl;
			addNewEmployee();
		}
		break;
		case 2:
		{
			cout << "List of employee" << endl;
			listEmployee();
		}
		break;
		case 3:
		{
			cout << "List employee by surname" << endl;
			EmployeeListBySurname();
		}
		break;
		case 4:
		{
			cout << "List employee by age" << endl;
			EmployeeListByAge();
		}
		break;
		case 5:
		{
			cout << "List employee by first letter of surname" << endl;
			EmployeeListByLetter();
		}
		break;
		case 6:
		{
			cout << "Delete employee" << endl;
			deleteEmployeeByName();
		}
		break;
		case 0:
		{
			exit(0);
		}
		break;
		default:
			break;
		}
	} while (a != 0);
	system("pause");
}
