#pragma once
#include <array>
#include <string>
/*
* This data type represent date which would contain day, month and year
* information for a date.
*/
using uint = unsigned int;
class Date
{
private:
	uint day, month, year;


	static bool leapYear(uint y); // it is static because it is not assocated with
	   // any specific date. In another words, it does not work on a specific date obj.

	bool endOfMonth(uint d) const;

	void helpIncrement(); //utility method used internally  for incrementign date.

	static const std::array<uint, 13> monthDays; // tells us how many days in each month
	static const std::array<std::string, 13> monthNames; // tells us how many days in each month
public:
	Date(uint d=1, uint m=1, uint y=1900);

	void setDate(uint d, uint m, uint y);  //used to set month, day and year

	uint getYear() const
	{
		return year;
	}

	Date& operator++();  // prefix increment operator
	Date operator++(int);  // postfix increment operator
	Date& operator += (uint);

	friend std::ostream& operator<<(std::ostream&, const Date&); // prints out date as "12 January 2012"
	friend std::istream& operator>>(std::istream&, Date&);  // ask user to type in date in format 12/1/2012


};
