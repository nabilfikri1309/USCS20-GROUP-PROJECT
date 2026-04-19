#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

double flycost(int,int,int,int);
double roomcost(int,int);
int getMostPopular(int, int, int, int);

//global variable
double totalIncome = 0;
double highestBill = 0.0;
int highestBillID = 0;
string highestBillLocation = " ";

//int VisitorsK=0, VisitorsT=0, VisitorsKK=0, VisitorsL=0;

int main()
{
	int place, roomtype ;//(1/2/3/4)
	int days,numroom;//for accomodation calculation
	int adults, teenage, kids;
	int idCounter=1;
	//double income_KK = 0.0, income_K=0.0, income_T=0.0, income_L=0.0;
	string action="yes";//to determine continue or not
	
	double incomeLoc[5] = {0,0,0,0,0};
	int visitorsLoc[5] = {0,0,0,0,0};
	string locationNames[5]= {"", "Kuching", "Terengganu", "Kota Kinabalu", "Langkawi"};
	
	
	ifstream inFile ("travel_data.txt") ;
	
	if (inFile.fail()) {
		cout<<"The file is unsuccessful to be opened. "<<endl;
	
	}
	
	else {
			inFile>>idCounter>>totalIncome >> highestBill >> highestBillID
           >> incomeLoc[1] >> incomeLoc[2] >> incomeLoc[3] >> incomeLoc[4]
           >> visitorsLoc[1] >> visitorsLoc[2] >> visitorsLoc[3] >> visitorsLoc[4];
		inFile.close() ;
		
		
	}

	

	
	
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
	
	//int visitorsTotal = adults+teenage+kids;
	
	
	cout<<"Total person: "<<adults+kids+teenage<<endl;
	
//	cout<<"Room Selection (1:Single, 2:Deluxe, 3:Suite): "; cin>>roomtype;
//	//days of hotel stay
	cout<<"Enter number of days: "; cin>>days;
	cout<<"Enter number of rooms: "; cin>>numroom;

	
	double flight=  flycost(place,adults,kids,teenage);
	double accomodation = roomcost (place,days);
	double totalCost = flight + accomodation;
	
	
//	Total Income Company
	totalIncome += totalCost;
	incomeLoc[place] += totalCost;
	visitorsLoc[place] += (adults + teenage + kids);
	
	//Highest Group Billing
	if (totalCost > highestBill) {
		highestBill = totalCost;
		highestBillID = idCounter;
		highestBillLocation = locationNames[place];
	}
	
	//Count Visitors
//	if (place == 1) {
//		VisitorsK += totalCost;
//	}
//	else if (place == 2) {
//		VisitorsT += totalCost;
//	}
//	else if (place == 3) {
//		VisitorsKK += totalCost;
//	}
//	else if (place == 4) {
//		VisitorsL += totalCost;
//	}
	
	//Total income each location
	incomeLoc[place] += totalCost;
	
//	cout<<fixed<<setprecision(2) << endl;
//	cout<< setfill ('-') << setw(30) <<"-" << endl;
//	cout<<"Billing status for ID "<<endl;
//	cout<< setfill ('-') << setw(30) <<"-" << endl;
//	cout<<setfill('0')<<setw(3);
//	cout<<" Flight total : RM "<<setw(10)<<flight<<endl;
//	cout<<" Hotel total  : RM "<<setw(10)<<accomodation<<endl;
//	cout<<" Overall total: RM "<<setw(10)<<totalCost<<endl;
//	cout<< setfill ('-') << setw(30) << "-" << endl;
	
	cout<<fixed<<setprecision(2)<<endl;
	cout<<"*============================*"<<endl;
	cout<<"    Billing status for ID     "<<endl;
	cout<<"------------------------------"<<endl;
	cout<<" Flight total : RM "<<setw(10)<<flight<<endl;
	cout<<" Hotel total  : RM "<<setw(10)<<accomodation<<endl;
	cout<<"______________________________"<<endl;
	cout<<" Overall total: RM "<<setw(10)<<totalCost<<endl;
	cout<<"______________________________"<<endl;
	
	idCounter++;
	
	cout<<"\nAdd another group entry? (yes/no): ";
	cin>>action;
	
	
	}
	int FamPlace = getMostPopular(visitorsLoc[1], visitorsLoc[2], visitorsLoc[3], visitorsLoc[4]);

	ofstream outFile("travel_memory.txt") ;
	if (outFile) {
		outFile << " ID : "      <<idCounter << " " 
				<< "REVENUE : RM" <<totalIncome << " "
				<< "HIGHEST PURCHASED: RM"<<highestBill << " "
				<< "MOST FAMOUS: "<<highestBillLocation << endl;
				
				
		outFile << "KUCHING : RM" <<incomeLoc[1] <<" "
				<< "TERENGGANU : RM"<<incomeLoc[2] <<" "
				<< "KOTA KINABALU : RM"<<incomeLoc[3] <<" "
				<< "LANGKAWI : RM"<<incomeLoc[4] <<endl;
				
		outFile<< "KUCHING : "<<visitorsLoc[1] << " "
			   << "TERENGGANU : "<<visitorsLoc[2] << " "
			   << "KOTA KINABALU : "<<visitorsLoc[3] << " " 
			   << "LANGKAWI : "<<visitorsLoc[4] <<endl;
		  
		  outFile.close();
	}
	
	    // File B: Management Report (Readable text for the manager)
    ofstream report("Management_System.txt"); 
    report << "==================================================" << endl;
    report << "     ENJOY&ENJOY TRAVEL: BUSINESS REPORT          " << endl;
    report << "==================================================" << endl;
    report << "Total Groups Processed   : " << idCounter - 1 << endl;
    report << "Total Company Revenue    : RM " << fixed << setprecision(2) << totalIncome << endl;
    report << "Most Popular Destination : " << locationNames[FamPlace]  << " (" << highestBillLocation << " visitors)" << endl;
    report << "All-Time Highest Bill    : Group " << setfill('0') << setw(3) << highestBillID 
           << " (RM " << highestBill << ")" << endl;
    report << "==================================================" << endl;
    report.close();

	//idcounter, highestPlace, totalIncome, highestBill, EachLocIncome, 
	//VisitorsK,VisitorsKK,VisitorsT,VisitorsL
	//Highest visitor

//	ofstream OutFile
}

double flycost(int location,int adult,int kids1,int kids2)//calculate flight cost
{
	
	double total;

	
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
//Most popular location
int getMostPopular(int k, int t, int kk, int l) {
	int counts[5] ={0,   k, t, kk, l};
	int maxVal = counts[1];
	int index = 1;
	
	for (int i =2; i<=4; i++) {
		if (counts[i] >maxVal) {
			maxVal = counts[i];
			index = i;
		}
	}
	return index;
}
