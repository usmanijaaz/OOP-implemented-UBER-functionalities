#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

using namespace std;

//class trip;


class driver :public user
{
	string drivinglicense;
	string vehicleno;

public:
	

	driver(string, date&, string,string, string, string);
	driver(string, date &, string, string);
	driver(const driver* d);
	const driver& operator=(const driver *p);
	void pickride(trip *);
	void ratepassenger(trip*, int);
	void endride();
	float getavgrating();
	void printtrips();
	

	friend ostream& operator<<(ostream& obj, const driver& u);
	
	void sendmessage(string);
	void readmessage();
	
	
};
