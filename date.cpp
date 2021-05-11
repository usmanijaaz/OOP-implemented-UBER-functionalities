#include "date.h"



date::date()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	day = ltm->tm_mday;
	month = ltm->tm_mon;
	year = ltm->tm_year+1900;

	

	   
}
date::date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
date::date(const date &d)
{
	this->year = d.year, this->month = d.month, this->day = d.day;

}

const date& date::operator=(const date *d)
{
	if (this != d)
	{
		day = d->day;
		month = d->month;
		year = d->year;
	}
	return *this;
}


int date::getdate() {

	return day;
}

int date::getmonth()
{
	return month;
}

int date::getyear()
{
	return year;
}

ostream& operator<<(ostream& obj, const date& d)
{
	obj << d.day << "/" << d.month << "/" << d.year << endl;

	return obj;
}