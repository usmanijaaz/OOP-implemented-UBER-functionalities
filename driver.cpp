#include "passenger.h"
#include "driver.h"




driver::driver(string n, date &d, string mail, string phno, string lic, string vno):user(n,mail,phno,d)
{
	status1 = "currentlynotdriving";
	t_arr = new trip*[maxtrips];
	drivinglicense = lic;
	vehicleno = vno;

}
driver::driver(string n, date &d, string mail, string phno) :user(n, mail, phno, d)
{
	t_arr = new trip*[maxtrips];
	status1 = "currentlynotriding";

}

driver::driver(const driver *p)
{
	name = p->name;
	

	email = p->email;
	

	phoneno = p->phoneno;
	

	

	dob = p->dob;
	

	cur_trip = p->cur_trip;

	drivinglicense = p->drivinglicense;
	

	vehicleno = p->vehicleno;
	
}

const driver& driver::operator=(const driver *p)
{
	if (this != p)
	{

		name = p->name;


		email = p->email;


		phoneno = p->phoneno;




		dob = p->dob;


		cur_trip = p->cur_trip;

		drivinglicense = p->drivinglicense;


		vehicleno = p->vehicleno;
	}
	return *this;
}

ostream& operator<<(ostream& obj, const driver& u)
{
	
	obj << u.name << endl;
	cout << u.dob;
	obj << u.email << endl;
	obj << u.phoneno << endl;
	obj << "no.of trips: " << u.nooftrips << endl;

	obj << u.drivinglicense << "," << u.vehicleno << endl;

	obj << u.status1 << endl;


	return obj;
}


void driver::pickride(trip * a)
{
	if (a->status == "complete" || a->status=="cancel")
	{
		cout << "ride cant be picked \n";
	}

	else if (this->status1 == "currentlynotdriving" || a->status == "notinprogress" )
	{
		cur_trip = a;
		a->d = this;
		t_arr[nooftrips] = cur_trip;
		a->changestatus("inprogress");		
		status1 = "currentlydriving";
		t_arr[nooftrips]->p->status1 = "currentlyriding";
		//nooftrips++;
	
	}
	
	else
	{
		cout << "ride cant be picked up \n";
	}

}

void driver::ratepassenger(trip *t, int a)
{
	if (t->status == "complete" )
	{
		if (a > 0 && a < 6)
		{
			t->passengerrating = a;
		}
		else
		{
			cout << "rating is not between 1 & 5 \n";
		}
	
	}
	else
	{
		cout<<"error in rating \n";
	}
}

void driver::endride()
{
	if (t_arr[nooftrips]->status == "inprogress")
	{

		this->status1 = "currentlynotdriving";

		t_arr[nooftrips]->status = "complete";

		cur_trip = nullptr;
		nooftrips++;
		t_arr[nooftrips - 1]->p->status1 = "currently not riding";

	}
	else
	{
		cout << "cant end the cancelled ride \n";
	}
	
}

float driver::getavgrating()
{
	if (nooftrips==0) 
	{
		return 0;
	}
	else
	{
		float avg = 0;
		int count = 0;
		for (int i = 0; i < this->nooftrips; i++)
		{
			if (t_arr[i]->driverrating == 0)
			{
				count++;
			}
			avg = avg + t_arr[i]->driverrating;
		}

		avg = avg / (nooftrips - count);

		return avg;
	}

}

void driver::printtrips()
{
	
	for (int i = 0; i < nooftrips; i++)
	{
		cout <<  *t_arr[i]<< endl << endl;
		
	}
}

void driver::readmessage()
{
	cout << "passenger's message  \n";
	cout << cur_trip->d->message << endl;
}

void driver::sendmessage(string s)
{
	if (this->cur_trip == cur_trip->p->cur_trip)
		cur_trip->p->message = s;
	else
		cout << "your passenger is not this \n";
}