#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int,int);
int flycost;//global variable

int main()
{
	int place ;//(1/2/3/4)
	
	
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

	cout << " Choose the location you want to travel by entering this given numbers : " <<endl;
	cin >> place ;
	
	//number of people
	cout<<"\nEnter number of person"<<endl;
	cout<<"\n Adults:";
	cin>>adults;
	cout<<"\nChildren (Age 2 and below):";
	cin>>kids;
	cout<<"\nChildren (Age 3 to 12): ";
	cin>>teenage;
	cout<<"\nTotal person: ";
	
	//days of hotel stay
	cout<<"\nEnter number of days:";
	//cin>>days;
	
	flycost= double flycost(place,adults,kids,teenage);

	
	return 0;
}

double flycost(int location,int dewasa,int kids1,int kids2)//calculate flight cost
{
	switch(location)
	case 1:
	flycost=(adult*750)+(kids1*750*0.1)+(kids2*750*0.6);
	break;
	case 2:
	flycost=(adult*420)+(kids1*420*0.1)+(kids2*420*0.6);
	break;
	case 3:
	flycost=(adult*1300)+(kids1*1300*0.1)+(kids2*1300*0.6);
	break;
	case 4:
	flycost=(adult*530)+(kids1*530*0.1)+(kids2*530*0.6);
	break;
	default: 
	  cout << " Error. Please enter the given option.";
	return flycost;
}


