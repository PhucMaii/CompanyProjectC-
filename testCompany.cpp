#include <string>
#include <iostream>
#include <sstream>
#include "Employee.h"
#include "PhoneNumber.h"
#include "date.h" 

#include <fstream>
// remember you need to add date.h and date.cpp, PhoneNumber.h, and phoneNumber.cpp we developed in class to this project. 
using namespace std;
string deleteComma(string str)
{
	string newStr{};
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] != ',')
		{
			newStr += str[i];
		}
	}
	return newStr;
}


std::istream& operator>>(std::istream& in, eGender& gender)
{
	int value;
	in >> value;
	gender = static_cast<eGender>(value);
	return in;
};

std::istream& operator>>(std::istream& in, Job& job)
{
	int value = 0;
	in >> value;
	job = static_cast<Job>(value);
	return in;
};


int main()
{
	Employee employeeee("Bin Mai", Date(1, 2, 2004), PhoneNumber("123", "333", "1233"), eGender::Male, Job::Accountant, 2345565 );
	employeeee.toString();
	Company theCompany;

	// load company.txt here to setup theCompany
	ifstream fs("company.txt");
	if (fs.is_open())
	{
		for (int i = 0; i < 2; ++i)
		{
			string line;
			getline(fs,line); 
		}

		
		string firstLine{};
		string comp{};
		string companyFirstName{};
		string companyLastName{};

		int numOfEmployees{};

		getline(fs, firstLine);
		stringstream ss(firstLine);
		ss >> comp >> companyFirstName >> companyLastName >> numOfEmployees;
		theCompany.setCompanyName(companyFirstName + " " + companyLastName);

		cout << theCompany.getCompanyName();
		string aline{};
		while(getline(fs, aline))
		{
			
			std::string firstName;
			std::string lastName;
			uint dateOfBirth;
			uint dateEmployed;
			eGender gender;
			Job job;
			int salary;
			stringstream ss(aline);
			
			ss >> firstName >> lastName >> dateOfBirth >> dateEmployed >> gender >> job >> salary;
			//Employee employee(firstName, Date(dateOfBirth), Date(dateEmployed), gender, static_cast<Job>(job), salary);
			for (int i = 0; i < numOfEmployees; ++i )
			{
				
			};
		};

	}
	else {
		std::cout << "File is not opened!!!";
	}
	
	std::cout<<"Printing company info:\n";
	theCompany.printEmployees();
	std::cout<<"Avrerage Salary:\n";
	std::cout<<"\nFind and Print out all the employees who are older than 28 from current date:\n";
	

	std::cout <<"Find and print all employees who have been with company more than 5 years, so they can receive silver medal!\n";
	
	// compute average salaries of company's employees and print it.
	// cout<< "Remove first employee from the company. Then printEmployees():\n;
	// // remove first employee.
	// cout<<theCompany.printEmployees();";
	
	std::cout<<"End of assignment.\n";
	
	return 0;
}
