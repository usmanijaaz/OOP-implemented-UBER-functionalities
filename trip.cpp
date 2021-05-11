#include "passenger.h"
#include "trip.h"
#include "driver.h"

trip::trip()
{
	status = "";
	pickuploc = " ";
	dropoffloc = " ";
	driverrating = 0;
	passengerrating = 0;
	d = nullptr;
		p = nullptr;
}

void trip::changestatus(string s)
{
	status = s;
	
	
}

string trip::getstatus()
{
	return status;
}



ostream& operator<<(ostream& obj, const trip & t)
{
	obj << "-----------------------------------------------------\n\n";

	obj << t.status << endl;
	cout << t.dob;
	obj << t.pickuploc << endl;
	obj << t.dropoffloc << endl;
	if (t.p != nullptr)
	{
		obj << (t.p)->name << endl;
	}
	if (t.d != nullptr) 
	{
		obj << (t.d)->name << endl;
	}
	
   
	if (t.status == "complete")
	{
		obj << "passenger's rating: " << t.passengerrating << endl;
		obj << "driver's rating: " << t.driverrating << endl;
	}

	
	return obj;


}

