#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneNumber.h"

using namespace std;
PhoneNumber::PhoneNumber(std::string a, std::string e, std::string l) : areaCode(a), exchange(e), line(l)
{
    if (a.size() == 3)
    {
        areaCode = a;
    }

     if (e.size() == 3)
    {
        exchange = e;
    }

     if (l.size() == 4)
    {
        line = l;
    }

}


//overloaded stream insertion and stream extraction operators for class PhoneNumber.

std::ostream& operator<<(std::ostream& output, const PhoneNumber& number)
{
    output << "Area code: " << number.areaCode << "\nExchange: " << number.exchange << "\nLine: " << number.line << "\n"
        << "(" << number.areaCode << ") " << number.exchange << "-" << number.line << "\n";
    return output;
}

// our assumption is that the input format is fully respected. We are not prepared for any other format.
std::istream& operator>>(std::istream& input, PhoneNumber& number)  //  we expect this format: (604) 311-1103
{
    input.ignore(); // skip '('
    input >> std::setw(3) >> number.areaCode; // input area code
    input.ignore(2); // skipping ') '
    input >> std::setw(3) >> number.exchange; 
    input.ignore();  //skipping dash (-)
    input >> std::setw(4) >> number.line; 
    return input;    // this enables us to do things like std::cin >> a >> b >> c;
}
