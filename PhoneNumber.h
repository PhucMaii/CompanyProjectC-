#pragma once
#include <string>
#include <iostream>
class PhoneNumber {
private:
	std::string areaCode;  // 3-digit area code
	std::string exchange;  // 3-digit exchange
	std::string line;  // 4-digit line 

public:
	PhoneNumber(std::string a="000", std::string e="000", std::string l="0000"); 

	void setNumber(std::string a, std::string e, std::string l)
	{
		areaCode = a;
		exchange = e;
		line = l;
	};													
	friend std::ostream& operator<<(std::ostream&, const PhoneNumber&); // std::cout<<ph;  cout<<"My name is "<<" Reza" <<endl;
	friend std::istream& operator>>(std::istream&, PhoneNumber&);  // std::in >> ph; std::cin >> i;
	

};
