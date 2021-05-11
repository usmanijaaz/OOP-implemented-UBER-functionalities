#include "person.h"


user::user()
{
	name = "";
	email = "";
	phoneno = "";
	t_arr = nullptr;
	cur_trip = nullptr;
	nooftrips = 0;
}


user::user(string n, string e, string p, date& d) :dob(d)
{
	name = n;
	email = e;
	phoneno = p;
	maxtrips = 20;
	t_arr = nullptr;
	cur_trip = nullptr;
	nooftrips = 0;
}


ostream& operator<<(ostream& obj, const user& u)
{
	obj << u.name << endl;
	cout << u.dob ;
	obj << u.email << endl;
	obj << u.phoneno << endl;
	obj << "no.of trips: " << u.nooftrips << endl;


	return obj;
}

user::~user()
{
	for (int i = 0; i < nooftrips; i++)
	{
		delete t_arr[i];
	}
	delete[] t_arr;
	delete cur_trip;
}

