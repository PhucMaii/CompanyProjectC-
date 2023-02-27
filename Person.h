#pragma once
#include <iostream>
#include <string>
#include "date.h"
#include "phoneNumber.h"

//Add getter and setters for Person's birthdate, fn, and name, 
//Add a method to Person class as:  void toString() const;. This method should return a string containing info about the person.
enum class eGender
{
	Female,
	Male,
	Others
};
class Person
{
	std::string m_name;
	Date birthDate;
	PhoneNumber fn;
	eGender m_gender = eGender::Others;

public:

	Person(std::string name, Date dob, PhoneNumber pn, eGender g) : m_name(name), birthDate(dob), fn(pn), m_gender(g)
	{
		std::cout << "Constructor: Person " << " is created.\n";
	};

	~Person()
	{
		std::cout << "Destructor for Person is called\n";
	}
	void setName(std::string name) { m_name = name; }
	void setBirthDay(int day, int month, int year) {  }
	std::string getName() const { return m_name; }
	int getAge() const  // return age as year
	{ return 2023 - birthDate.getYear(); }
	void setGender(eGender g)
	{
		m_gender = g;
	}

	eGender getGender()
	{
		return m_gender;
	}
	
	void setPhoneNumber(std::string area, std::string exchange, std::string line)
	{
		fn.setNumber(area,exchange,line);
	}

	PhoneNumber getPhoneNumber() const
	{
		std::cout << fn;
		return fn;
	}



	// friend std::istream& operator>>(std::istream& in, eGender& gender)
	// {
    // 	int value;
    // 	in >> value;
    // 	gender = static_cast<eGender>(value);
    // 	return in;
	// }


	std::string toString() const {
        std::string info;
        info += "Name: " + m_name + "\n";
        info += "Age: " + std::to_string(getAge()) + "\n";
        // info += "Phone Number: " + fn + "\n";
        info += "Gender: ";  // + std::to_string(static_cast<int>(m_gender)) + "\n";
         switch (m_gender)
        {
        case eGender::Female:
            info += "Female\n";
            break;
        case eGender::Male:
            info += "Male\n";
            break;
        default:
            info += "Others\n";
        }
		return info;
    }
};
