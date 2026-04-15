#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int,int);

int main()
{
	string tempat;
	
	
	//table of prices
	cout<<"Welcome to Enjoy&Enjoy Travels Agency."<<endl;
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
	
	//number of people
	cout<<"\nEnter number of person"<<endl;
	cout<<"\nAdult:";
	cin>>adult;
	cout<<"\nChildren (Age 2 and below):";
	cin>>kids;
	cout<<"\nChildren (Age 3 to 12): ";
	cin>>teenage;
	cout<<"\nTotal person: ";
	
	//days of hotel stay
	cout<<"\nEnter number of days:";
	//cin>>days;
	
//	double flycost(location)
	
	return 0;
}

/*double flycost(int tempat,int flycost,int totalfly)
{
	cout<<"\nEnter location:";
	cin>>tempat;
	
	switch(tempat)
	case 1
	flycost=(adult*750)+(kids*750*0.1)+(teenage*750*0.6);
	break;
	case 2
	flycost=(adult*420)+(kids*420*0.1)+(teenage*420*0.6);
	break;
	case 3
	flycost=(adult*1300)+(kids*1300*0.1)+(teenage*1300*0.6);
	break;
	case 4
	flycost=(adult*530)+(kids*530*0.1)+(teenage*530*0.6);
	break;
	
}*/


