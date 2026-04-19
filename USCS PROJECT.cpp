#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int,int,int);
double roomcost(int,int);

//global variable
double totalIncome = 0;
double highestBill = 0.0;
int highestBillID = 0;


int VisitorsK=0, VisitorsT=0, VisitorsKK=0, VisitorsL=0;

int main()
{
	int place, roomtype ;//(1/2/3/4)
	int days,numroom;//for accomodation calculation
	int adults, teenage, kids;
	int idcounter=1;
	string action="yes";//to determine continue or not

	ifstream inFile

	
	//table of prices
	cout<<"Welcome to Enjoy&Enjoy Travels Agency."<<endl;
	cout<< "This is the table for our travel services options based on the location, flight price and hotel price per night."<<endl;
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
	cout<<"\n====================================================================";
	cout<<"\n * Note: Children 0-2 (10% charge), 3-12 (40% discount)";
	cout<<"\n * Note: 10% Hotel discount applied for stays over 7 nights" ;
	cout<<"\n====================================================================";


	cout<<"\nProceed to join this new travel group? (yes/no) "<<endl;
	cin>>action;
	
	while (action != "no") {
	cout <<"Choose the location of travel by entering this given numbers : " <<endl;
	cout<<"1.Kuching \t2.Terengganu \t3.Kota Kinabalu \t4.Langkawi"<<endl;
	cin >> place ;
	
	//number of people
	cout<<"Enter number of person"<<endl;
	cout<<"Adults: "; cin>>adults;
	cout<<"Children (Age 2 and below): ";cin>>kids;
	cout<<"Children (Age 3 to 12): ";cin>>teenage;
	
	int visitorsTotal = adults+teenage+kids;
	
	cout<<"Total person: "<<visitorsTotal<<endl;
	
	cout<<"Room Selection (1:Single, 2:Deluxe, 3:Suite): "; cin>>roomtype;
	//days of hotel stay
	cout<<"Enter number of days: "; cin>>days;
	cout<<"Enter number of rooms: "; cin>>numroom;

	
	double flight=  flycost(place,adults,kids,teenage);
	double accommodation = roomcost (place,days);
	double totalCost = flight + accomodation;
	
	totalIncome += totalCost;
	
	
	//Highest Group Billing
	if (totalCost > highestBill) {
		highestBill = totalCost;
		highestBillID = idcounter;
	}
	
	//Count Visitors
	if (place == 1) {
		VisitorsK += visitorsTotal;
	}
	else if (place == 2) {
		VisitorsT += visitorsTotal;
	}
	else if (place == 3) {
		VisitorsKK += visitorsTotal;
	}
	else if (place == 4) {
		VisitorsL += visitorsTotal;
	}
	
	cout<<fixed<<setprecision(2) << endl;
	cout<< setfill ('-') << setw(30) << endl;
	cout<<"Billing status for ID "<<setfill('0')<<setw(3)<<endl;
	setfill(' ');
	cout<<" Flight total : RM "<<setw(10)<<flight<<endl;
	cout<<" Hotel total  : RM "<<setw(10)<<accomodation<<endl;
	cout<<" Overall total : RM "<<setw(10)<<totalCost<<endl;
	cout<< setfill ('-') << setw(30) << endl;
	
	idcounter++;
	
	cout<<"\nAdd another group entry? (yes/no): ";
	cin>>action;
	
	return 0;
	}


double flycost(int location,int dewasa,int kids1,int kids2)//calculate flight cost
{
	
	double total;
	int adult;
	
	switch(location) {
	
	case 1:
	total=(adult*750)+(kids1*750*0.1)+(kids2*750*0.6);
	break;
	case 2:
	total=(adult*420)+(kids1*420*0.1)+(kids2*420*0.6);
	break;
	case 3:
	total=(adult*1300)+(kids1*1300*0.1)+(kids2*1300*0.6);
	break;
	case 4:
	total=(adult*530)+(kids1*530*0.1)+(kids2*530*0.6);
	break;
	default: 
	cout << " Error. Please enter the given option.";
	}
	return total; 
	
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




