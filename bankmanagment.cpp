#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<random>
#include<ctime>
using namespace std;


class bank{
public:
    int accno;
    string name;
    string email;
    float amount;
    int searchacc;
    int newamount;
     fstream currdata , newdata , gettingdata; ;
public:
    void creatingaccount(){

         
    mt19937 gen(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<> dist(1000 ,9999);
    accno = dist(gen);


    cout<<"ENTER YOUR NAME :- ";
    cin>>name;
    cout<<endl;

    cout<<"ENTER YOUR E-MAIL ADDRESS :- ";
    cin>>email;
    cout<<endl;

    cout<<"ENTER YOUR AMOUUNT :- ";
    cin>>amount;
    cout<<endl;
    
    cout<<"YOUR NEW ACCOUNT HAS BEEN SUCCESSFULLY CREATED"<<endl;
    cout<<"YOUR ACCOUNT NUMBER IS ::"<<accno<<endl;


    fstream writingdata;
    writingdata.open("data.txt" , ios::out | ios::app);
   
    writingdata<<accno<<"\t"<<name<<"\t"<<email<<"\t"<<amount<<endl;
    writingdata.close();

    }

    void deposit(){
        cout<<"ENTER AMOUNT YOU WANNA DEPOSIT:- ";
    cin>>newamount;


    fstream currdata , newdata;
    currdata.open("data.txt" , ios::in);
    newdata.open("newdata.txt" , ios::out | ios::app);
    currdata>>accno>>name>>email>>amount;

    while(!currdata.eof()){
        if(searchacc == accno){
            cout<<"YOUR PREVIOUS AMOUNT:- "<<amount<<endl;
            amount = amount + newamount;
            cout<<"YOUR UPDATED AMOUNT:- "<<amount<<endl;
            newdata<<accno<<"\t"<<name<<"\t"<<email<<"\t"<<amount<<endl; 
        }
        else{
            newdata<<accno<<"\t"<<name<<"\t"<<email<<"\t"<<amount<<endl;
        }
        currdata>>accno>>name>>email>>amount;
    }
    currdata.close();
    newdata.close();

    remove("data.txt");
    rename("newdata.txt" ,"data.txt");
    }

   void withdraw(){
     cout<<"ENTER AMOUNT YOU WANNA WITHDRAW:- ";
    cin>>newamount;


    fstream currdata , newdata;
    currdata.open("data.txt" , ios::in);
    newdata.open("newdata.txt" , ios::out | ios::app);
    currdata>>accno>>name>>email>>amount;

    while(!currdata.eof()){
        if(searchacc == accno){
            cout<<"YOUR PREVIOUS AMOUNT:- "<<amount<<endl;
            amount = amount - newamount;
            cout<<"YOUR UPDATED AMOUNT:- "<<amount<<endl;
            newdata<<accno<<"\t"<<name<<"\t"<<email<<"\t"<<amount<<endl;  
        }
        else{
            newdata<<accno<<"\t"<<name<<"\t"<<email<<"\t"<<amount<<endl;
        }
        currdata>>accno>>name>>email>>amount;
    }
    currdata.close();
    newdata.close();

    remove("data.txt");
    rename("newdata.txt" ,"data.txt");
   } 

   void checkinfo(){
    fstream gettingdata;
	gettingdata.open("data.txt",ios::in);
	if(!gettingdata){
		cout<<"File opening error !";
	}

	gettingdata>>accno>>name>>email>>amount;

	while(!gettingdata.eof()){
		if(accno==searchacc){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: account Number ::: ";
            cout<<"\t   "<<accno<<endl;
            cout<<"\t::: User Name      ::: ";
            cout<<"\t   "<<name<<"\n";
            cout<<"\t::: Email          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";
		
	    }
		gettingdata>>accno>>name>>email>>amount;
	}
	
	gettingdata.close();
   }
};

int main(){
      
    bank bank1;
    int choice;
    cout<<"\n\t\t\t.:::::::::::::.";
    cout<<"\n\t\t......:::Aatish's Bank:::.....";
    cout<<"\n\t\t..............................";
	cout<<"\n\t\t:: press 1 to Login  Account ::";
	cout<<"\n\t\t:: press 2 to Create Account ::";
	cout<<"\n\t\t:: press 0 to Exit           ::";
	cout<<"\n\t\t:: ......................... ::\t\t";
    cout<<"\n\t:::::::::: ......................... ::::::::::\n\t\t";
    cout<<"YOUR CHOICE:-";
	cin>>choice;
    
    switch(choice){
        case 1:
            cout<<"Enter your account no :: ";
	        cin>>bank1.searchacc;
        while(1){

            cout<<"\n\n\t\t.......:::Aatish's Bank:::.......";
            cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: press 3 to Check    Info    ::";
            cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n";
            cout<<"\t\t:: ........................... ::\n\t\t";
            cout<<"YOUR CHOICE:- ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                bank1.deposit();
            break;
            case 2:
                bank1.withdraw();
            break;
            case 3:
                bank1.checkinfo();
            break;
            case 0:
                return 0;
            break;
            default:
                cout<<"Invalid Choice...! 0_o";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case 2:
            bank1.creatingaccount();
        break;
        case 0:
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice...! 0_o ";
        break;
    }
    return 0;
}
