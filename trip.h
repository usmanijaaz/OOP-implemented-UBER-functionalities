#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "date.h"
//#include "passenger.h"
//#include "driver.h"

using namespace std;

class driver;
class passenger;



class trip
{
public:
	string status;
	string pickuploc;
	string dropoffloc;
	int driverrating;
	int passengerrating;
	date dob;
	driver *d;
	passenger *p;
	trip();
	
	void changestatus(string);
	string getstatus();

	friend ostream& operator<<(ostream& obj,const trip & t);
	~trip()
	{
		delete d;
		delete p;
	}
	
};