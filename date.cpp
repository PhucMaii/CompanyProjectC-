#include <iostream>
#include <sstream>

#include "date.h"

// initialize static data:

const std::array<uint, 13> Date::monthDays{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const std::array<std::string, 13> Date::monthNames{ "", "January", "February", "March", "April", 
                  "May", "June", "July", "August", "September", "October", "November", "December"};

// constructor
Date::Date(uint d, uint m, uint y)
{
    setDate(d, m, y);
}

// validate data before using them to set the date
void Date::setDate(uint d, uint m, uint y)
{
    if (m >= 1 && m <= 12)
        month = m;
    else
        throw std::invalid_argument("Month must be between 1 and 12. Invalid month been used.");

    if (y >= 1900 && y <= 2100)
        year = y;
    else
        throw std::invalid_argument("Year must be >= 1900 and <= 2100");

    if ((d >= 1 && d <= monthDays[m]) || (m==2 && leapYear(y) && d <= 29))
        day = d;
    else
        throw std::invalid_argument("Day is out of range for the current month and year"); 
}

// overloading prefix increment operator.
Date& Date::operator++()
{
    std::cout << "prefix increment is called\n";
    helpIncrement(); 
    return *this;
}

// overloading postfix increment operator. THis method is
// creating a copy of current date, before incrementing it, and 
// at the end returns the copy.
Date Date::operator++(int a)
{
    std::cout << "postfix increment is called\n";
    Date temp = *this;
    helpIncrement();
    return temp;
}

// overloading assignment increment operator.
Date& Date::operator+=(uint d)
{
    for (int i = 0; i < d; ++i)
        helpIncrement();
    return *this;
}

// this method check to see if year y is a leap year.
bool Date::leapYear(uint y)
{
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

bool Date::endOfMonth(uint d) const
{
    bool isEndOfMonth = false;
    if (d == monthDays[month])
        isEndOfMonth = true;

    if (month == 2 && leapYear(year) && d == 29)
        isEndOfMonth = true;

    return isEndOfMonth;
}

// increments the day and takes care of changes needed for month and year
void Date::helpIncrement()
{
    if (!endOfMonth(day))
        ++day;
    else
    {
        if (month < 12)  // means we are not in decemeber but we are at the end of month
        {
            ++month;
            day = 1;
        }
        else  // means months is 12 and day is end of the month
        {
            ++year;
            month = 1;
            day = 1;
        }
    }
}

std::ostream& operator<<(std::ostream&  os, const Date& date)
{
    os << date.day << " " << Date::monthNames[date.month] << " " << date.year;
    return os;
}

// format for input is day/month/year
std::istream& operator>>(std::istream& is, Date& date)
{
    std::cout << "Input the date in format 'day-month-year': ";
    // first read the data from user and save it in a string:
    std::string rawDate{};
    is >> rawDate; //"12/1/2013"
    std::stringstream ss(rawDate);
    std::string s{};
    std::getline(ss, s, '-');
    int day = atoi(s.c_str());
    std::getline(ss, s, '-');
    int m = atoi(s.c_str());
    std::getline(ss, s, '-');
    int y = atoi(s.c_str());

    date.day = day;
    date.month = m;
    date.year = y;

    return is;
}
