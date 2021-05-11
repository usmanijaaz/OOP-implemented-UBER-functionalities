#include "date.h"
#include "driver.h"
#include "passenger.h"
#include "payment.h"
#include "trip.h"


const int SIZE = 20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip **uberTrips = new trip*[SIZE];

int n = 0;

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}

void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}

user **usersarray = new user*[SIZE];
 
int countuser(string f);
void readfile(string file);
void printusers();

user* mosthighlyrateduser()
{
	user* u = nullptr;
	float rate = -1;
	
	for (int i = 0; usersarray[i]!=nullptr; i++)
	{
		
		if (usersarray[i]->getavgrating() > rate )
		{
			rate = usersarray[i]->getavgrating();
			u = usersarray[i];
		}
	}
	return u;

}


user* mosthighlyratedpassenger()
{
	user* u = nullptr;
	float rate = -1;

	for (int i = 0; usersarray[i] != nullptr; i++)
	{

		if (usersarray[i]->getavgrating() > rate && strcmp(typeid(*usersarray[i]).name(),"class passenger")==0)
		{
			rate = usersarray[i]->getavgrating();
			u = usersarray[i];
		}
	}
	return u;

}

user* mosthighlyrateddriver()
{
	user* u = nullptr;
	float rate = -1;

	for (int i = 0; usersarray[i] != nullptr; i++)
	{

		if (usersarray[i]->getavgrating() > rate && strcmp(typeid(*usersarray[i]).name(), "class driver") == 0)
		{
			rate = usersarray[i]->getavgrating();
			u = usersarray[i];
		}
	}
	return u;

}


int main()
{
	date d(10, 10, 1990);
	payment p("111-222-333-333", "card");

	passenger * p1 = new passenger("P1",d , "ali@yahoo.com", "0334564334", p);

	driver *d1 = new driver("D1", d, "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");

	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookride("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip
	addToUberTrips(p1->bookride("C", "D"));//prints error as p1 has already booked a ride
	d1->pickride(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	d1->ratepassenger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->ratedriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endride(); //will change the status of uberTrip[0] to Complete

	d1->ratepassenger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->ratedriver(uberTrips[n - 1], 4); //error as the trip is not complete
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickride(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl;

	////////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
    addToUberTrips(p1->bookride("C", "D"));
	d1->pickride(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelride();
	p1->cancelride();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->ratepassenger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->ratedriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	//////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookride("D", "E"));
	p1->cancelride();
	d1->pickride(uberTrips[n - 1]); //error as this ride is not looking for driver
   d1->ratepassenger(uberTrips[n - 1], 5); //error as the ride was not complete
   p1->ratedriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

//	//////Test Case 4: getting avg ratings adn print trip funnction
//	////Adding some more test data
	addToUberTrips(p1->bookride("X", "Y"));
	d1->pickride(uberTrips[n - 1]);
	d1->endride();
	d1->ratepassenger(uberTrips[n - 1], 3);
	p1->ratedriver(uberTrips[n - 1], 5);
	
	addToUberTrips(p1->bookride("X", "Y"));
	 d1->pickride(uberTrips[n - 1]);
	d1->endride();
	d1->ratepassenger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	d1->ratepassenger(uberTrips[n - 1], 4);
	d1->ratepassenger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->ratedriver(uberTrips[n - 1], 1);

	p1->printtrips();
    d1->printtrips();
	
	cout << p1->getavgrating() << endl;
	cout << d1->getavgrating()<<endl;
////
	cout << "-------------------------------part b---------------------------------------\n\n\n";


	//.......................UBER PART B....................//
	for (int i = 0; i < SIZE; i++)
	{
		usersarray[i] = nullptr;
	}


	readfile("userfile.txt");
	printusers();

	/*o	Call the functions created in step 3 to read all users in usersArray
		o	Shahmeer books a ride
		o	Meher picks shahmeers ride
		o	Meher messages shahmeer “Can you please confirm the location ? ”
		o	Shahmeer reads messages
		o	Shahmeers sends message to meher “19B Faisal Town opposite 711 Store”
		o	Meher ends the drive
		o	Shahmeer rates meher 5
		o	Meher rates shahmeer 4
		o	Ibrahim books a ride
		o	Shahmeer picks ibrahims request
		o	Shahmeer ends a ride
		o	Shahmeer rate Ibrahim 3
		o	Ibrahim rates shahmeer 4
		o	Call the functions create in part 5, 6 and 7 to get the most highly rated user, passage and driver respectively.*/


    passenger* shameer = dynamic_cast<passenger*>(usersarray[0]);
	

	addToUberTrips(shameer->bookride("faisal town", "model town"));
	driver *meher = dynamic_cast<driver*>(usersarray[1]);
	meher->pickride(uberTrips[n-1]);
	meher->sendmessage("can you please confirm your location ?");
	shameer->readmessage();
	cout << endl;
	shameer->sendmessage("19 b faisal town");
	meher->readmessage();
	cout << endl;
	meher->endride();
	shameer->ratedriver(uberTrips[n - 1],5);
	meher->ratepassenger(uberTrips[n - 1], 4);
	passenger* ibrahim = dynamic_cast<passenger*>(usersarray[2]);
	addToUberTrips(ibrahim->bookride("faisal town", "model town"));
	driver *ali = dynamic_cast<driver*>(usersarray[4]);
	ali->pickride(uberTrips[n - 1]);
	ali->endride();
	ali->ratepassenger(uberTrips[n - 1], 3);
	ibrahim->ratedriver(uberTrips[n - 1], 4);

	cout << "---------------------------------------------------------\n";
	cout << "most highly rated user:  \n";


	cout << *mosthighlyrateduser();

	cout << "---------------------------------------------------------\n";
	cout << "most highly rated passenger:  \n";
	cout << *mosthighlyratedpassenger();

	cout << "---------------------------------------------------------\n";
	cout << "most highly rated driver:  \n";
	cout << *mosthighlyrateddriver();

	////.......MEMORY DEALLOCATION...........////

	
	delete[]uberTrips;

	
	delete[] usersarray;




	system("PAUSE");

	return 0;
}



int countuser(string f)
{
	char arr[100];
	int count = 0;
	ifstream fin;
	fin.open(f.c_str());
	if (fin.is_open())
	{

		while (fin.getline(arr, 100))
		{
			count++;
		}
		
	}
	return count;
}


void readfile(string file)
{
	
	int l = 0;
	char ch;
	string t;
	string name;
	int a, b, c;
	string email;
	string ph;
	int k = countuser(file);
	ifstream fin;
	fin.open(file.c_str());
	if (fin.is_open())
	{
		for (int i = 0; i <k; i++)
		{
			getline(fin, t, ',');
			
			getline(fin, name, ',');
			
			fin >> a;
			fin >> ch;
			fin >> b;
			fin >> ch;
			fin >> c;
			fin >> ch;
			
			getline(fin, email, ',');
			getline(fin, ph, '\n');

			if (t == "p")
			{
				date d(a, b, c);
				usersarray[l++] = new passenger(name, d, email, ph);
				
			}
			else 
			{
				date d(a, b, c);
				usersarray[l++] = new driver(name, d, email, ph);
				
			}
		}
	}
	
}

void printusers()
{
	for (int i = 0; usersarray[i] != nullptr; i++)
	{
		cout << *usersarray[i] << endl;

	}

}
