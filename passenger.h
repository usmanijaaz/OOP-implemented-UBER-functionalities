#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "payment.h"
#include "person.h"

using namespace std;

//class trip;

class passenger:public user
{
public:

	payment pm;
	passenger();
	passenger(string, date &, string , string );
	passenger(string, date&, string, string, payment&);
	passenger(const passenger *p); 
	const passenger& operator=(const passenger *p);
	void printtrips();

	trip* bookride(string, string);
	void cancelride();
	float getavgrating();

	void ratedriver(trip*, int);

	friend ostream& operator<<(ostream& obj, const passenger& u);
	
	void sendmessage(string);
	void readmessage();

};