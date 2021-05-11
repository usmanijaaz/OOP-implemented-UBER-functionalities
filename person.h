#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "date.h"
#include "trip.h"
using namespace std;

//class trip;


class user
{
private:
	
public:
	string name;	
	string email;
	string phoneno;
	string message;
	trip **t_arr;
	trip *cur_trip;        //a pointer to current trip 
	int maxtrips;
	int nooftrips;
	date dob;
	string status1;

	


	user();
	user(string n, string e, string p, date& d);
   friend ostream& operator<<(ostream& obj, const user& u);
   virtual ~user();
   virtual float getavgrating() = 0;
   virtual void sendmessage(string s) = 0;
   virtual void readmessage() = 0;
	//friend class trip;

};