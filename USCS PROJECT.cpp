#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int, int,int);
double roomcost(int,int);

//global variable
int flight;
int accommodation;

int main()
{
	int place ;//(1/2/3/4)
	int kids, teenage, adults;
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
	cout<<"\n 1.Kuching \t2.Terengganu \t3.Kota Kinabalu \t4.Langkawi";

	cout << " \n Choose the location of travel by entering this given numbers : " ;
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
	
	flight= flycost(place,adults,kids,teenage);
	accommodation = roomcost(place, days);

	
	return 0;
}

double flycost(int location,int dewasa,int kids1,int kids2)//calculate flight cost
{
	switch(location){
	case 1:
	flight=(dewasa*750)+(kids1*750*0.1)+(kids2*750*0.6);
	break;
	case 2:
	flight=(dewasa*420)+(kids1*420*0.1)+(kids2*420*0.6);
	break;
	case 3:
	flight=(dewasa*1300)+(kids1*1300*0.1)+(kids2*1300*0.6);
	break;
	case 4:
	flight=(dewasa*530)+(kids1*530*0.1)+(kids2*530*0.6);
	break;
	default: 
	  cout << " Error. Please enter the given option.";
}
	return flight;
}


double roomcost ( int location, int staynight  ) //calculate room cost 
{
	
	char roomtype, more;
	int single, deluxe, suite;
	double roomprice, accommodation;
	
	switch (location)
	{
	
	 case 1 :
    
		single = 140;
		deluxe = 230;
		suite = 350; 
		break;
	
     case 2 :
		single = 150;
		deluxe = 220;
		suite = 330;
	    break ;
	    
     case 3 :
		single = 120;
		deluxe = 180;
		suite = 275;
        break ;
        
     case 4 :
	
		single = 160;
		deluxe = 240;
		suite = 350;
	    break ;
	    
	default :
		cout << " Error. Please use the given number. "<<endl;
		exit(1) ;
		
	}


do {
    cout << " \n Single (S) | Deluxe (D) | Suite (U) "<<endl;
	
	cout << " Choose the room type  : " ;
	cin >> roomtype; 

	if ( roomtype == 'S'||roomtype =='s')
	{
		roomprice = single;
	}
	else if ( roomtype == 'D'||roomtype =='d')
	{
		roomprice = deluxe ;
	}
	else if ( roomtype == 'U'||roomtype =='u')
	{
		roomprice = suite ;
	}
	else 
	{
		cout << " Error. Please use the given letter. "<<endl;
	}
	
	accommodation += (roomprice * staynight);
	
	cout << " \n Would you like to add another room? (Y/N): ";
	cin >> more;
	
    }

 	while ( more == 'Y' || more == 'y');
	
	if ( staynight > 7)
	{
		accommodation = accommodation * 0.90;
	}
	
	return accommodation ;
	
}




