#include "passenger.h"
#include "driver.h"

passenger::passenger()
{
	name = nullptr;
	email = nullptr;
	phoneno = nullptr;
	
	
	cur_trip = nullptr;
	
	
}

passenger::passenger(string n, date &d, string mail, string phno, payment &p):user(n,mail,phno,d),pm(p)
{ 
	t_arr = new trip*[maxtrips];
	status1 = "currentlynotriding";
}

passenger::passenger(string n, date &d, string mail, string phno) :user(n,mail,phno,d)
{
	t_arr = new trip*[maxtrips];
	status1 = "currentlynotriding";
	
}

passenger::passenger(const passenger *p)
{
	
	name = p->name;
	email = p->email;
	phoneno = p->phoneno;

	dob = p->dob;
	pm = p->pm;

	cur_trip = p->cur_trip;


}

const passenger& passenger::operator=(const passenger *p)
{
	if (this != p) {
		

		name = p->name;
		email = p->email;
		phoneno = p->phoneno;

		dob = p->dob;
		pm = p->pm;

		cur_trip = p->cur_trip;

	}

	return *this;
}

ostream& operator<<(ostream& obj, const passenger& u)
{
	

	obj << u.name << endl;
	cout << u.dob;
	obj << u.email << endl;
	obj << u.phoneno << endl;

	obj << "no.of trips: " << u.nooftrips << endl;


	obj << u.pm.type << "," << u.pm.cardnumber << endl;

	
		obj <<u.status1 << endl;
		

	return obj;
}


trip* passenger::bookride(string a, string b)
{
	if (cur_trip==nullptr || status1 == "currentlynotriding" || t_arr[nooftrips-1]->status == "complete" || t_arr[nooftrips-1]->status == "cancel")
	{
		this->status1 = "looking4driver";
		cur_trip = new trip();
		cur_trip->p = this;
		cur_trip->pickuploc = a;
		cur_trip->dropoffloc = b;
		cur_trip->status = "notinprogress";
		t_arr[nooftrips] = cur_trip;
		nooftrips++;

	}
	
	else
	{
		cout << "cannot book two rides at a time \n";

	}
	return t_arr[nooftrips-1];
}

void passenger::cancelride()
{
	
	if ( this->status1=="looking4driver")
	{
		cur_trip = nullptr;
		this->status1 = "currentlynotriding";
		t_arr[nooftrips-1]->status = "cancel";
		
	}
	else if(this->status1 == "currentlyriding")
	{
		cur_trip = nullptr;
		this->status1 = "currentlynotriding";
		t_arr[nooftrips - 1]->status = "cancel";
		t_arr[nooftrips - 1]->d->status1 = "currentlynotdriving";
	}
	else
	{
		cout << "there is no current ride \n";
	}
}


void passenger::ratedriver(trip* t, int a)
{
	if (t->status == "complete")
	{
		if (a > 0 && a < 6)
		{
			t->driverrating = a;
		}
		else
		{
			cout << "rating is not between 1 & 5 \n";
		}
	}
	else
	{
		cout << "error in rating \n";
	}
}

float passenger::getavgrating()
{
	if (nooftrips==0)
	{
		return 0;
	}

	else
	{


		float avg = 0;
		int count = 0;
		for (int i = 0; i <this->nooftrips; i++)
		{
			if (t_arr[i]->passengerrating == 0)
			{
				count++;
			}
			avg = avg + t_arr[i]->passengerrating;

		}
		avg = avg / (nooftrips - count);

		return avg;

	}
}

void passenger::printtrips()
{

	for (int i = 0; i < nooftrips; i++)
	{
		cout << *t_arr[i] << endl << endl;

	}
}

void passenger::sendmessage(string s)
{
	if (this->cur_trip == cur_trip->d->cur_trip)
		cur_trip->d->message = s;
	else
		cout << "your driver is not this \n";
}

void passenger::readmessage()
{
	cout << "driver's message: \n";
	cout << cur_trip->p->message<<endl;
}