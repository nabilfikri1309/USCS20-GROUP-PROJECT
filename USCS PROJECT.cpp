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
	int place ;//(1/2/3/4)
	int days;//for accomodation calculation
	int adults, teenage, kids;
	int idUsername;
	//double income_KK = 0.0, income_K=0.0, income_T=0.0, income_L=0.0;
	string action="yes";//to determine continue or not
	
	double incomeLoc[5] = {0,0,0,0,0};
	int visitorsLoc[5] = {0,0,0,0,0};
	string locationNames[5]= {"", "Kuching", "Terengganu", "Kota Kinabalu", "Langkawi"};
	
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
	cout<<"\n|   Terengganu   |     420      |    150    |    220    |   330    |";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n| Kota Kinabalu  |    1300      |    120    |    180    |   275    |";
	cout<<"\n|----------------|--------------|-----------|-----------|----------|";
	cout<<"\n|    Langkawi    |     530      |    160    |    240    |   350    |";
	cout<<"\n|________________|______________|___________|___________|__________|";
	cout<<"\n====================================================================";
	cout<<"\n * Note: Children Age 0-2 (10% charge), Age 3-12 (40% discount)";
	cout<<"\n * Note: 10% Hotel discount applied for stays over 7 nights" ;
	cout<<"\n====================================================================";


	cout<<"\nProceed to join this new travel group? (yes/no) : ";
	cin>>action;
	
	while (action == "yes" || action == "YES") {
	cout<<"1.Kuching \t2.Terengganu \t3.Kota Kinabalu \t4.Langkawi"<<endl;
	cout <<"Choose the location of travel by entering this given numbers : "; cin >> place ;
	switch (place)
	{
	case 1 :
		break;
	
     case 2 :
	    break ;
	    
     case 3 :
        break ;
        
     case 4 :
	    break ;
	    
	default :
		cout << " Error. Please use the given number. "<<endl;
		exit(1) ;
	}

	cout<<"\nEnter travel group ID : ";cin>>idUsername;
	
	//number of people
	cout<<"\n=============================";
	cout<<"\n  Enter number of person     ";
	cout<<"\n=============================";
	cout<<"\nAdults                    :"; cin>>adults;
	cout<<"\nChildren (Age 2 and below):";cin>>kids;
	cout<<"\nChildren (Age 3 to 12)    :";cin>>teenage;
	cout<<"\nTotal person              :"<<adults+kids+teenage<<endl;
	//int visitorsTotal = adults+teenage+kids
	

//	cout<<"Room Selection (1:Single, 2:Deluxe, 3:Suite): "; cin>>roomtype;
//	//days of hotel stay
	cout<<"\n=============================";
	cout<<"\nEnter number of days : "; cin>>days;
	
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
		highestBillID = idUsername;
		highestBillLocation = locationNames[place];
	}
	
	
	cout<<fixed<<setprecision(2)<<endl;
	cout<<"*============================*"<<endl;
	cout<<"    Billing status for ID     "<<endl;
	cout<<"------------------------------"<<endl;
	cout<<" Flight total : RM "<<setw(10)<<flight<<endl;
	cout<<" Hotel total  : RM "<<setw(10)<<accomodation<<endl;
	cout<<"______________________________"<<endl;
	cout<<" Overall total: RM "<<setw(10)<<totalCost<<endl;
	cout<<"______________________________"<<endl;
	
//	ofstream history("transaction_history.txt", ios::app);
//        history << "ID:" << idUsername << " | Dest:" << locationNames[place] 
//                << " | Paid:RM" << totalCost << endl;
//        history.close();
	
	cout<<"\nAdd another group entry? (yes/no): ";
	cin>>action;
	
	
	}
	
		ifstream inFile ("travel_data.txt", ios::app) ;
	
	if (inFile.fail()) {
		cout<<"The file is unsuccessful to be opened. "<<endl;
	
	}
	
	
	 	string line;
	 	getline  (inFile, line ); {
		 
//			inFile>>idUsername>>totalIncome >> highestBill >> highestBillID
//           >> incomeLoc[1] >> incomeLoc[2] >> incomeLoc[3] >> incomeLoc[4]
//           >> visitorsLoc[1] >> visitorsLoc[2] >> visitorsLoc[3] >> visitorsLoc[4];
		
			
		cout <<setfill('=')<<setw(30)<<" "<<endl
				<< "ID               : " <<idUsername << " " << endl
				<< "REVENUE          : RM"<<totalIncome << " "<< endl
				<< "HIGHEST PURCHASED: RM"<<highestBill << " "<< endl
				<< "MOST FAMOUS      : "<<highestBillLocation << endl<< endl;
				
				
		cout    << "KUCHING          : RM" <<incomeLoc[1] <<" "<< endl
				<< "TERENGGANU       : RM"<<incomeLoc[2] <<" "<< endl
				<< "KOTA KINABALU    : RM"<<incomeLoc[3] <<" "<< endl
				<< "LANGKAWI         : RM"<<incomeLoc[4] <<endl<< endl;
				
		cout    << "KUCHING          : "<<visitorsLoc[1] << " "<< endl
			    << "TERENGGANU       : "<<visitorsLoc[2] << " "<< endl
			    << "KOTA KINABALU    : "<<visitorsLoc[3] << " " << endl
			    << "LANGKAWI         : "<<visitorsLoc[4] <<endl;
	
		
		inFile.close() ;
	}

	int FamPlace = getMostPopular(visitorsLoc[1], visitorsLoc[2], visitorsLoc[3], visitorsLoc[4]);

	ofstream outFile("travel_data.txt", ios::app) ;
	if (outFile) {
		outFile << " ID : "      <<idUsername << " " 
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
		  cout<< " The travel data receipt has ready to be view in file travel_data.txt."<<endl;
	}
	
	    // File B: Management Report (Readable text for the manager)
    ofstream report("Management_System.txt"); 
    report << "==================================================" << endl;
    report << "     ENJOY&ENJOY TRAVEL: BUSINESS REPORT          " << endl;
    report << "==================================================" << endl;
    report << "Total Groups Processed   : " << idUsername << endl;
    report << "Total Company Revenue    : RM " << fixed << setprecision(2) << totalIncome << endl;
    report << "Most Popular Destination : " << locationNames[FamPlace]  << " (" << highestBillLocation << " visitors)" << endl;
    report << "All-Time Highest Bill    : Group " << setfill('0') << setw(3) << highestBillID 
           << " (RM " << highestBill << ")" << endl;
    report << "==================================================" << endl;
    report.close();
    cout<< " The business report has ready to be view in file Management_System.txt. "<<endl;
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

double roomcost ( int location, int staynight ) //calculate room cost 
{
	char roomtype, more;
	string location_name;
	int single, deluxe, suite;
	double roomprice = 0, accomodation = 0;
	int countS = 0, countD = 0, countU = 0;
	
	switch (location)
	{
	 case 1 :
		single = 140;
		deluxe = 230;
		suite = 350; 
		location_name = " Kuching ";
		break;
	
     case 2 :
		single = 150;
		deluxe = 220;
		suite = 330;
		location_name = " Terengganu ";
	    break ;
	    
     case 3 :
		single = 120;
		deluxe = 180;
		suite = 275;
		location_name = " Kota Kinabalu ";
        break ;
        
     case 4 :
		single = 160;
		deluxe = 240;
		suite = 350;
		location_name = " Langkawi ";
	    break ;
	    
	default :
		cout << " Error. Please use the given number. "<<endl;
		exit(1) ;
	}


do 
{
    cout << " \nSingle (S) | Deluxe (D) | Suite (U) "<<endl;
	
	cout << "Choose the room type  : " ;
	cin >> roomtype; 

	if ( roomtype == 'S'||roomtype =='s')
	{
		cout << "Total rooms : ";
	    cin >> countS;
	    roomprice = single*countS;
	}
	else if ( roomtype == 'D'||roomtype =='d')
	{
		
		cout << "Total rooms : ";
	    cin >> countD;
	    roomprice = deluxe*countD ;
	}
	else if ( roomtype == 'U'||roomtype =='u')
	{
		cout << "Total rooms : ";
	    cin >> countU;
	    roomprice = suite*countU ;
	}
	else 
	{
		cout << " Error. Please use the given letter. "<<endl;
		exit(1);
	}
	
	
	accomodation += (roomprice * staynight);
	
	cout << "\nWould you like to add another room? (Y/N): ";
	cin >> more;
	
    }
    
    while ( more == 'Y' || more == 'y');
    
    
    cout << "\n------------------------------"<<endl;
    cout << "\n===============================" << endl;
    cout << "     ACCOMMODATION INFORMATION         " << endl;
    cout << "===============================" << endl;
    cout << "Location : " << location_name << endl;
    cout << "Days of stay : " << staynight << endl;
    cout << "Single Rooms : " << countS << endl;
    cout << "Deluxe Rooms : " << countD << endl;
    cout << "Suite Rooms  : " << countU << endl;
    cout << "Total Rooms  : " << (countS + countD + countU) << endl;
    cout << "===============================" << endl;
    
	if ( staynight > 7){
		accomodation = accomodation * 0.90;
	}
	
	
	return accomodation ;
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
