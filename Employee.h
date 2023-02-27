#pragma once

#include "Person.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>
//1-create a class Employee which inherits from Person class. Each Employee has an employee id (int), a 
// job which is a string from the list: "hr", "engineer", "manager", "accountant".  It also contains an integer representing the salary per year.
//2-Add a method to Person class as:  void toString() const;. This method should return a string containing info about the person.
//3-Add toString() method to Employee class, similarly for Person, to return a string containing employee's info. toString() from Employee class should call base case toString() first, to use the result to construct its output string. This can be done by calling Person::toString().
//4-Create a class called "Company". This represents a company. Company must have a name, a string. It should also contain an vector of employees.
//5-Create a function in Company class, called PrintEmployees(). This function should use a for loop to visit each employee and call toString() of that employee, so it prints that employee info to screen.

// A test cpp is included, testCompany.cpp which loads data from data file company.txt and tests the above features. Any missing constructors and other methods relevant to performing the tests should be added to Employee class as needed.
// You must hand in the clean project with release build.
using namespace std;
enum Job 
{
    HR,
    Engineer,
    Manager,
    Accountant
};
class Employee : public Person
{
    int employeeID;
    Job job = Job::HR;
    int salary;

public:
    Employee(std::string name, Date dob,PhoneNumber pn, eGender g = eGender::Male, Job j = Job::Accountant, int s = 123344 ) : Person(name, dob, pn, g ), job(j), salary(s) 
    {
        cout << "\nEmployee created" << endl;
    };  

    int getEmployeeID()
    {
        return employeeID;
    };

    void setEmployeeID(int id)
    {
        employeeID = id;
    };

    Job getJob()
    {
        return job;
    };

    void setJob(Job value)
    {
        job = value;
    };

    int getSalary()
    {
        return salary;
    };

    void setSalary(int value)
    {
        salary = value;
    };

//     Job stringToJob(const std::string& str) {
//     if (str == "HR") {
//         return Job::HR;
//     } else if (str == "Engineer") {
//         return Job::Engineer;
//     } else if (str == "Manager") {
//         return Job::Manager;
//     } else if (str == "Accountant") {
//         return Job::Accountant;
//     } else {
//         throw std::invalid_argument("Invalid job string");
//     }
// }


    void toString() const
    {
        cout << "Employee Info: " << Person::toString() << "\nEmployee Job: " << static_cast<int>(job) << "\nSalary: " << salary ;
    }
     
};

class Company
{
    string name;
    vector<Employee> employeeList;

public:
    Company(string companyName = "dummyCompany") : name(companyName) 
    {
        cout << "Company created: " << name << endl;
    };

    void setCompanyName(string compName)
    {
        name = compName;
    };

    string getCompanyName()
    {
        return name;
    };

    void addEmployee(Employee employee)
    {
        employeeList.push_back(employee);
    };  

    void removeEmployee(int index)
    {
        employeeList.erase(employeeList.erase(employeeList.begin() + index));
    };

    void printEmployees() const
    {
        for(auto employee : employeeList)
        {
            employee.toString();
        }
    };

};