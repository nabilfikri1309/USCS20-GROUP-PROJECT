#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int,int);
double roomcost(int,int,int,int);

//global variable
int flight;
int accomodation;

int main()
{
	int place ;//(1/2/3/4)
	int days,numroom;//for accomodation calculation
	int idcounter=1;
	string action="yes";//to determine continue or not
	
	//table of prices
	cout<<"Welcome to Enjoy&Enjoy Travels Agency."<<endl;
	cout << "This is the table for our travel services options based on the location, flight price and hotel price per night."<<endl;
	cout<<"\n====================================================================";
	cout<<"\n                        ENJOY&ENJOY TRAVELS";
	cout<<"\n====================================================================";
	cout<<"\n|    Location    | Flight Price |       Price for night (RM)       |";
	cout<<"\n|                | (RM)/person  |----------------------------------|";
	cout<<"\n|                |              |Single Room|Deluxe Room|Suite Room|";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n|     Kuching    |     750      |    140    |    230    |   350    |";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n|   Terengganu   |     750      |    150    |    220    |   330    |";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n| Kota Kinabalu  |     750      |    120    |    180    |   275    |";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n|    Langkawi    |     750      |    160    |    240    |   350    |";
	cout<<"\n|________________|______________|___________|___________|__________|";
	cout<<"\n";
	cout<<"1.Kuching \t2.Terengganu \t3.Kota Kinabalu \t4.Langkawi";

	cout << " Choose the location of travel by entering this given numbers : " <<endl;
	cin >> place ;
	
	//number of people
	cout<<"\nEnter number of person"<<endl;
	cout<<"\n Adults:";
	cin>>adults;
	cout<<"\nChildren (Age 2 and below):";
	cin>>kids;
	cout<<"\nChildren (Age 3 to 12): ";
	cin>>teenage;
	cout<<"\nTotal person: "<<adults+kids+teenage;
	
	//days of hotel stay
	cout<<"\nEnter number of days:";
	//cin>>days;
	
	flight= double flycost(place,adults,kids,teenage);
	accomodation = double roomcost(place,roomtype,days,numroom);

	
	return 0;
}

double flycost(int location,int dewasa,int kids1,int kids2)//calculate flight cost
{
	switch(location)
	case 1:
	flight=(adult*750)+(kids1*750*0.1)+(kids2*750*0.6);
	break;
	case 2:
	flight=(adult*420)+(kids1*420*0.1)+(kids2*420*0.6);
	break;
	case 3:
	flight=(adult*1300)+(kids1*1300*0.1)+(kids2*1300*0.6);
	break;
	case 4:
	flight=(adult*530)+(kids1*530*0.1)+(kids2*530*0.6);
	break;
	default: 
	  cout << " Error. Please enter the given option.";
	return flight;
}

double roomcost(int location, int type, int night, int rooms)
{
	double price;
if(location==1)
{
if(type==1)
	price=140;
else if (type==2)
	price=230;
else
	price=350;
}
else if(location==2)
{
if(type==1)
	price=;
else if(type==2)
	price=;
else
	price=;
}
else if(location==3)
{
if(type==1)
	price=;
else if(type==2)
	price=;
else
	price=;
}
else
{
if(type==1)
	price=;
else if(type==2)
	price=;
else
	price=;
}

double totalroom = price*night*rooms;

if(night>7)
{
totalroom=totalroom*0.9;
}

return totalroom;
}



