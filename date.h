#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class date
{
	int day;
	int month;
	int year;
public:
	date();
	date(int, int, int);
	date(const date &d);
	int getdate();
	int getmonth();
	int getyear();
	const date& operator=(const date *d);
	friend ostream& operator<<(ostream& obj, const date& d);
	
};