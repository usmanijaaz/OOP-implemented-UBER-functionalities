#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class payment
{
public:
	string type;   //card or cash
	string cardnumber;
	
	payment();
	payment(string, string);
	payment(const payment &p);
	const payment& operator=(const payment *p);
	void setmethod(string);
	

};


