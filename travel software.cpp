#include <iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
#include"Customers.h"
#include"Cabs.h"
#include"Booking.h"
#include"Tourist.h"
#include<string.h>
using namespace std;
void menu();
char adminf[20]="Trip.txt";
char userf[20]="Reservation.txt";


class ManageMenu{
	protected:
		string userName;//admin name
		int password;//admin password
	public:
		ManageMenu(){
			setlocale(LC_ALL, "Turkish");
			system("color 0A");
			cout<<"                              \t\t WELCOME TO TOUR MANAGEMENT SYSTEM\n\n\n";
            cout<<"                                   \t    ELIF NUR ASLIHAN CELEPOÐLU\n\n\n";
            cout<<"                                \t Beykoz University Computer Engineering\n\n\n";
			cout<<"\n\n\n\n\n\n\n\n\n\t Enter your name to continue as an admin:";
			cin>>userName;
			cout<<"\t Password:";
			cin>>password;
			system("CLS");
			menu();
		}
		~ManageMenu(){}	
		
		
		
		
		
};
void Tourist ::ad_pack(tour r){
     fstream fp;
     fp.open(adminf,ios::out|ios::app);
     if(!fp){
		cout<<"\nCannot open file";
		exit(0);
     }
     char buff[45];
     strcpy(buff,r.ad_code);
     strcat(buff,"|");
     strcat(buff,r.ad_place);
     strcat(buff,"|");
     strcat(buff,r.ad_country);
     strcat(buff,"|");
     strcat(buff,r.ad_days);
     strcat(buff,"|");
     strcat(buff,r.ad_prices);
     strcat(buff,"|");
     for(int i=0;i<45-strlen(buff);i++)
            strcat(buff,"|");
     fp<<buff<<endl;
     fp.close();
}

tour Tourist::ad_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.ad_code[i++]=buff[j++];
	r.ad_code[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_place[i++]=buff[j++];
	r.ad_place[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_country[i++]=buff[j++];
	r.ad_country[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_days[i++]=buff[j++];
	r.ad_days[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_prices[i++]=buff[j++];
	r.ad_prices[i]='\0';
	return(r);
}

void Tourist::ad_writedata(){
    tour s;
    cout<<"Enter the Destination Code\nD-";
    cin>>s.ad_code;
    cout<<"Enter the Destination Place\n";
    cin>>s.ad_place;
    cout<<"Enter the Country of the Destination\n";
    cin>>s.ad_country;
    cout<<"Enter the Number of days of the Trip\n";
    cin>>s.ad_days;
    cout<<"Enter the Cost of the trip\n";
    cin>>s.ad_prices;
    ad_pack(s);
}


void Tourist::ad_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"-------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\t\tDEST. CODE\tPLACE\t\tCOUNTRY\t\tDAYS\t\tPRICES\n";
    cout<<"-------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=ad_unpack(buff);
        cout<<c++<<"\t\t"<<r.ad_code<<"\t\t"<<r.ad_place<<"\t\t"<<r.ad_country<<"\t\t" <<r.ad_days<<"\t\t"<<r.ad_prices<<endl;
    }
    fp.close();
    return;
}


void Tourist ::ad_modify(){
    fstream fp;
    char ad_code[15],buff[45];
    int i,j,ch;
    tour s[100];
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE DESTINATION CODE TO BE MODIFIED: ";
    cin>>ad_code;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=ad_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
       		if(strcmp(s[j].ad_code,ad_code)==0){
                    cout<<"VALUES OF THE TRIP\n";
                    cout<<"\nDestination Code: "<<s[j].ad_code;
                    cout<<"\nDestination Place: "<<s[j].ad_place;
                    cout<<"\nDestination Country: "<<s[j].ad_country;
                    cout<<"\nNo of days of Trip: "<<s[j].ad_days;
                    cout<<"\nTotal Cost of the Trip: "<<s[j].ad_prices;
                    cout<<"\nWhat you want to Update: ";
	  		cout<<"\n\n\t\tEnter 1 for changing DESTINATION PLACE\n";
	  		cout<<"\t\tEnter 2 for changing DAYS OF THE TRIP\n";
	  		cout<<"\t\tEnter 3 for changing COST OF THE TRIP\n";
	  		cout<<"\t\t\t";
	  		cin>>ch;
	  		switch(ch){
                case 1:
                    cout<<"Destination Place: ";
                    cin>>s[j].ad_place;
                    cout<<"Destination Country: ";
                    cin>>s[j].ad_country;
                    break;
                case 2:
                    cout<<"No of days of Trip: ";
                    cin>>s[j].ad_days;
                    break;
                case 3:
                    cout<<"Total Cost of the Trip: ";
                    cin>>s[j].ad_prices;
                    break;
	  		}
                    break;
            }
    }
   	if(j==i){
        cout<<"\n TRIP NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(adminf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nFile Not Found";
        exit(0);
    }
   	for(j=0;j<i;j++)
         ad_pack(s[j]);
   	fd.close();
}

void Tourist ::us_pack(tour r){
    fstream fp;
    fp.open(userf,ios::out|ios::app);
    if(!fp){
        cout<<"\nFile Not Found";
		exit(0);
    }
    char buff[45];
    strcpy(buff,r.us_name);
    strcat(buff,"|");
    strcat(buff,r.us_phone);
    strcat(buff,"|");
    strcat(buff,r.us_people);
    strcat(buff,"|");
    strcat(buff,r.us_dcode);
    strcat(buff,"|");
    strcat(buff,r.us_date);
    strcat(buff,"|");
    strcat(buff,r.us_status);
    strcat(buff,"|");
    for(int i=0;i<45-strlen(buff);i++)
     	strcat(buff,"|");
    fp<<buff<<endl;
    fp.close();
}


tour Tourist::us_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.us_name[i++]=buff[j++];
	r.us_name[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_phone[i++]=buff[j++];
	r.us_phone[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_people[i++]=buff[j++];
	r.us_people[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_dcode[i++]=buff[j++];
	r.us_dcode[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_date[i++]=buff[j++];
	r.us_date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_status[i++]=buff[j++];
	r.us_status[i]='\0';
	return(r);
}
void Tourist::us_writedata(){
    tour r;
    cout<<"ENTER YOUR NAME: ";
    cin>>r.us_name;
    cout<<"ENTER YOUR CONTACT NO.: ";
    cin>>r.us_phone;
    cout<<"ENTER NO. OF TOURIST: ";
    cin>>r.us_people;
    cout<<"ENTER THE DESTINATION CODE: D-";
    cin>>r.us_dcode;
    cout<<"ENTER DATE OF JOURNEY (DD/MM/YY): ";
    cin>>r.us_date;
    cout<<"\nENTER 'Confirm' TO CONFIRM YOUR RESERVATION: ";
    cin>>r.us_status;
    us_pack(r);
}

void Tourist::us_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tNAME\t\tCONTACT NO\t\tTOTAL PEOPLE\t\tDATE\t\tDEST. CODE\t\tSTATUS\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=us_unpack(buff);
        cout<<c++<<"\t"<<r.us_name<<"\t\t"<<r.us_phone<<"\t\t"<<r.us_people<<"\t\t\t"<<r.us_date<<"\t\t"<<r.us_dcode<<"\t\t"<<r.us_status<<endl;
    }
    fp.close();
    return;
}


void Tourist ::us_modify(){
    fstream fp;
    char us_name[15],buff[45];
    int i,j;
    tour s[100];
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nFile not Found";
		exit(0);
    }
    cout<<"\nEnter Your name to cancel  your reservation: ";
    cin>>us_name;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=us_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
        if(strcmp(s[j].us_name,us_name)==0){
	  		cout<<"\nYour Reservation Details are:\n";
	  		cout<<"\nName: "<<s[j].us_name;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nDestination: "<<s[j].us_dcode;
	  		cout<<"\nDate of Journey: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
	  		cout<<"\n\nENTER 'Cancel' TO CANCEL YOUR TICKET: \n";
	  		cin>>s[j].us_status;
	  		cout<<"\nYour Reservation has been Cancelled\n";
	  		cout<<"\n\nName: "<<s[j].us_name;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nDestination: "<<s[j].us_dcode;
	  		cout<<"\nDate of Journey: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
            break;
        }
    }
   	if(j==i){
        cout<<"\nRECORD NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(userf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nCannot open file";
        exit(0);
    }
   	for(j=0;j<i;j++)
        us_pack(s[j]);
   	fd.close();
}

void Tourist::us_search(){
 	fstream fp;
 	char us_name[15],buff[45];
 	int i,j;
 	tour s;
    fp.open(userf,ios::in);
    if(!fp){
	 	cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE NAME TO BE SEARCHED: ";
    cin>>us_name;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s=us_unpack(buff);
        if(strcmp(s.us_name,us_name)==0){
	  	 	cout<<"\n RESERVATION FOUND\n";
	  		cout<<"\nNAME: "<<s.us_name;
	  		cout<<"\nCONTACT NO.: "<<s.us_phone;
	  		cout<<"\nNO. OF PEOPLE: "<<s.us_people;
	  		cout<<"\nDATE OF JOURNEY: "<<s.us_date;
	  		cout<<"\nSTATUS: "<<s.us_status;
	  		return;
	 	}
    }
    cout<<"\nRESERVATION NOT FOUND";
    return;
}
	
void Customers::  getDetails(){
		ofstream out("old-customers.txt",ios::app);
		{
		
		cout<<"Enter Customer ID:";
		cin>>cusID;
		cout<<"Enter Name:";
		cin>>name;
		cout<<"Enter Age:";
		cin>>age;
		cout<<"Enter Mobile Number:";
		cin>>mobileNo;
		cout<<"Enter Address:";
		cin>>address;
		cout<<"Enter Gender:";
		cin>>gender;
	}
	  out<<"\nCustomer ID:"<<cusID<<"\nName:"<<name<<"\nAge:"<<age<<"\nMobile Number:"<<mobileNo<<"\nAddress:"<<address<<"\nGender:"<<gender<<endl;
	  out.close();
	  cout<<"\nSAVED  \nNOTE: We save your details record for purposes\n"<<endl;
	  
	  
	  
	  
	}
	
void Customers:: showDetails(){
		ifstream in("old-customers.txt");//customer txt file.
		{
			if(!in){
				cout<<"File Error!"<<endl;
			}
			while(!(in.eof())){
				in.getline(all,999);
				cout<<all<<endl;
			}
			in.close();
		}
		
		
		
	}



int Customers::cusID;

	

		
	void Cabs:: cabDetails(){
			cout<<"We collaborated with fastest,safest,and smartest cab service arround the country"<<endl;
			cout<<"-----------ENAC cabs -------\n"<<endl;
			cout<<"1-)Rent a standart cab-Rs.15 for 1Km"<<endl;
			cout<<"2-)Rent a luxury cab - Rs.25 for 1km"<<endl;
			
			cout<<"\nTo calculate the cost for your journey:"<<endl;
			cout<<"Enter which kind of cab you need:";
			cin>>cabChoice;
			cout<<"Enter kilometers you have to tarvel:";
			cin>>kilometers;
			 int hireCab;
			 
			 if(cabChoice==1){
			 	cabCost=kilometers*15;
			 	cout<<"\n Your tour cost"<<cabCost<<" rupess for a standard cab"<<endl;
			 	cout<<"press 1 to hire this cab: or";
			 	cout<<"press 2 to select another cab";
			 	cin>>hireCab;
			 	
			 	system("CLS");
			 	
			 if (hireCab==1){
			 	lastcabCost=cabCost;
			 	cout<<"\n You have successfully hired a standard cab"<<endl;
			 	cout<<"Goto menu and take the receipt"<<endl;
			 	
			 	
			 }
			 else if(hireCab==2){
			 	cabDetails();
			 }
			 else{
			 	cout<<"Invalid input! redirecting to previous menu\n please wait!"<<endl;
			 	Sleep(999);
			 	system("CLS");
			 	cabDetails();
			 }
			 
			 
			 
			 	
			 }
			 
			 else if(cabChoice==2){
			 	cabCost=kilometers*25;
			 	cout<<"\n Your tour cost"<<cabCost<<" rupess for a standard cab"<<endl;
			 	cout<<"Press 1 to hire this cab: or";
			 	cout<<"Press 2 to select another cab:";
			 	cin>>hireCab;
			 	
			 	system("CLS");
			 	if (hireCab==1){
			 	lastcabCost=cabCost;
			 	cout<<"\n You have successfully hired a luxury cab"<<endl;
			 	cout<<"Goto menu and take the receipt"<<endl;
			 	
			 	
			 }
			 else if(hireCab==2){
			 	cabDetails();
			 }
			 else{
			 	cout<<"Invalid input! redirecting to previous menu\n please wait!"<<endl;
			 	Sleep(1100);
			 	system("CLS");
			 	cabDetails();
			 }
			 	
			 	
			 
			 
			 
			 }
			 else {
			 	
			 cout<<"Invalid input! redirecting to main menu\n please wait!"<<endl;
			 	Sleep(1100);
			 	system("CLS");
			 	menu();
			 }
			 
			 
			 cout<<"\nPress 1 to redirect main menu:";
			 cin>>hireCab;
			 system("CLS");
			 if(hireCab==1){
			 	menu();
			 }else{
			 	menu();
			 }
			 
			 
			 
			 
			 
		}
	
	

float Cabs::lastcabCost;

 void Booking::hotels(){
			string hotelNo[] = {"Four Seasons Hotel","Hilton Hotel","Marriott Hotel","Wyndham Hotel","Interncontinental Hotels","Choice Hotels","Hyatt Hotels","Holiday Inn Hotels","Hampton by Hilton","Shangri La Hotels","Double Tree by Hilton","Mercure Hotel","Crowne Plaza Hotel","Sheraton Hotel","Ramada Hotel","Ýbis Hotel","Novotel","Ritz Carlton Hotel","Regis","W Hotel"};
	        for(int a=0;a<20;a++){
	        	cout<<(a+1)<<" "<<hotelNo[a]<<endl;
	        }
	        cout<<endl;
	        	cout<<"\nCurrently we collaborated with above hotels!"<<endl;
	        	cout<<"\nPress any key to back or\n enter number of the hotel you want to book:";
	        	cin>>choiceHotel;
	        	system("CLS");
	        	
	        	if(choiceHotel==1){
	        		cout<<"-----Welcome to Four Seasons Hotel-------\n"<<endl;
					cout<<"the garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"packages offered by Four Seasons Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack::"<<endl;
					cout<<"\tAll basic facilities you need just for: Rs.5000.00"<<endl;
					cout<<"2-)Preium pack::"<<endl;
					cout<<"\tEnjoy preium:Rs.1000000.000"<<endl;
					cout<<"3-)Luxury pack::"<<endl;
					cout<<"\tLive a luxury at Four Seasons Hotel: Rs.1500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=5000.00;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=1000000.000;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=1500000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
				
			}else if(choiceHotel==2){
				cout<<"-----Welcome to Hilton Hotel -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Hilton Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack::"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.25000.00"<<endl;
					cout<<"2-)Preium pack::"<<endl;
					cout<<"\tEnjoy preium:Rs.10000000.000"<<endl;
					cout<<"3-)Luxury pack::"<<endl;
					cout<<"\tLive a luxury at Hilton Hotel: Rs.3500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=25000.00;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=10000000.000;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=3500000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
				
		}else if(choiceHotel==3){
				
				cout<<"-----Welcome to Marriott Hotel -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Marriott Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.65000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.130000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Marriott Hotel: Rs.8500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=65000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=130000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=8500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
				
				
}else if(choiceHotel==4){
				
				cout<<"-----Welcome to Wyndham Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Wyndham Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.6000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.160000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Wyndham Hotel: Rs.9500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=6000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=160000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=9500000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
				
				
}else if(choiceHotel==5){
				
				cout<<"-----Welcome to Interncontinental Hotels  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Interncontinental Hotels:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.9000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.180000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Interncontinental Hotels: Rs.9800000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=9000.00;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=180000000.000;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=9800000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}

		}else if(choiceHotel==6){
				
				cout<<"-----Welcome to Choice Hotels -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Choice Hotels:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\tAll basic facilities you need just for: Rs.12000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.230000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Choice Hotels: Rs.10500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=12000.00;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=230000000.000;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=10500000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}
			else if(choiceHotel==7){
				
				cout<<"-----Welcome to Hyatt Hotels  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Hyatt Hotels:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.67000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.960000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Hyatt Hotels: Rs.12500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=67000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=960000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=12500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}
			else if(choiceHotel==8){
				
				cout<<"-----Welcome to Holiday Inn Hotels  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Holiday Inn Hotels:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.89000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.780000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Holiday Inn Hotels: Rs.10300000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=89000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=780000000.000;
						cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=10300000.000;
					cout<<"\nYou have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}
			else if(choiceHotel==9){
				
				cout<<"-----Welcome to Hampton by Hilton  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Hampton by Hilton:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Hampton by Hilton: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
				
				
			}else if(choiceHotel==10){
				
				cout<<"-----Welcome to Shangri La Hotels  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Shangri La Hotels:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Shangri La Hotels: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			
			
			
			}else if(choiceHotel==11){
				
				cout<<"-----Welcome to Double Tree by Hilton  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Double Tree by Hilton:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Double Tree by Hilton: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
	
         }else if(choiceHotel==12){
				
				cout<<"-----Welcome to Mercure Hotel   -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Mercure Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Mercure Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==13){
				
				cout<<"-----Welcome to Crowne Plaza Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Crowne Plaza Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Crowne Plaza Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==14){
				
				cout<<"-----Welcome to Sheraton Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Sheraton Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Sheraton Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==15){
				
				cout<<"-----Welcome to Ramada Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Ramada Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Ramada Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==16){
				
				cout<<"-----Welcome to Ýbis Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Ýbis Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Ýbis Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==17){
				
				cout<<"-----Welcome to Novotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Novotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Novotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==18){
				
				cout<<"-----Welcome to Ritz Carlton Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Ritz Carlton Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Ritz Carlton Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==19){
				
				cout<<"-----Welcome to Regis  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by Regis:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at Regis: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}else if(choiceHotel==20){
				
				cout<<"-----Welcome to W Hotel  -------\n"<<endl;
					cout<<"The garden,food and beverage.enjoy all you can drink ,stay cool and get chilled in the summer sun."<<endl;
					
					cout<<"Packages offered by W Hotel:\n "<<endl;
					
					
					cout<<"1-)Standart pack:"<<endl;
					cout<<"\t All basic facilities you need just for: Rs.17000.00"<<endl;
					cout<<"2-)Preium pack"<<endl;
					cout<<"\tEnjoy preium:Rs.760000000.000"<<endl;
					cout<<"3-)Luxury pack:"<<endl;
					cout<<"\tLive a luxury at W Hotel: Rs.14500000.000"<<endl;
								
					cout<<"\nPress another key to back or\n enter package number you want to book:";
					cin>>packChoice;
					if(packChoice==1){
						hotelCost=17000.00;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
					}
					else if (packChoice==2){
						hotelCost=760000000.000;
						cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
						cout<<"Goto menu and take the receipt"<<endl;
						
					}else if (packChoice==3){
					
					hotelCost=14500000.000;
					cout<<"\n You have succesfully booked premium pack at Four Seasons Hotel ";
					cout<<"Goto menu and take the receipt"<<endl;
				}else{
					cout<<"Invalid input! redirecting to previous menu\nplease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					hotels();
				}
				
				cout<<"\nPress 1 to redirect main menu:";
				cin>>gotomenu;
				system("CLS");
				if(gotomenu==1){
					menu();
				}else{
					menu();
				}
			}
}


float Booking::hotelCost;


class Charges : public Booking, Cabs, Customers{
	public:
		void printBill(){
			
			ofstream outfile("receipt.txt");
			{
				outfile<<"---------ENAC Travel Agency-------"<<endl;
				outfile<<"-------------Receipt-------------"<<endl;
				outfile<<"_________________________________"<<endl;
				outfile<<"Customer ID:"<<Customers::cusID<<endl;
				outfile<<"Description\t\t total"<<endl;
				outfile<<"Hotel cost:\t\t"<<fixed<<setprecision(2)<<Cabs::lastcabCost<<endl;
				outfile<<"Travel(cab) cost:\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
				outfile<<"_________________________________"<<endl;
			    outfile<<"Total caharge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost<<endl;
			    outfile<<"_________________________________"<<endl;
			    outfile<<"------------Thank You-------------"<<endl;
	}
	
	outfile.close();
			
			
	}
	
	void showBill(){
		
		
		ifstream inf("receipt.txt");
		{
			if(!inf){
				cout<<"File opening error!"<<endl;
				
			}while(!inf.eof()){
				inf.getline(all,999);
				cout<<all<<endl;
				
			}
		}
		inf.close();
	}
	
};
void menu(){
	
	int mainChoice;
	int ch1;
	int inChoice;
	int gotoMenu;
	cout<<"\t\t  ********************ENAC TRAVEL************************"<<endl;
	cout<<"----------------------------------------Main Menu-------------------------------------"<<endl;
	cout<<"\t_________________________________________"<<endl;
	cout<<"\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\tCustomer Management -> 1\t|"<<endl;
	cout<<"\t|\tCabs Management -> 2\t\t|"<<endl;
	cout<<"\t|\tBooking Management -> 3\t\t|"<<endl;
	cout<<"\t|\tCharge & Bill -> 4\t\t|"<<endl;
	cout<<"\t|\t Admin trip-> 5\t\t|"<<endl;
	cout<<"\t|\t User trip-> 6\t\t|"<<endl;
	cout<<"\t|\tExist-> 7\t\t\t|"<<endl;
	cout<<"\t|_______________________________________|"<<endl;
	
	
	cout<<"\nEnter your choice:";
	cin>>mainChoice;
	system("CLS");
	Customers a2;
	Cabs a3;
	Booking a4;
	Charges a5;
	Tourist t1;
	
	if(mainChoice==1){
		cout<<"-------------Customer----------\n"<<endl;
		cout<<"1-)Enter New Customer:"<<endl;
		cout<<"2-)See Old Customer:"<<endl;
		
		cout<<"\nEnter Choice:";
		cin>>inChoice;
		
		system("CLS");
		if(inChoice==1){
			a2.getDetails();
		}
		else if(inChoice==2){
			a2.showDetails();
		}else{
			cout<<"Invalid Input! Resirecting to Previous Menu\n Please Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		
		cout<<"\nPress 1 to Redirect main menu:";
		cin>>gotoMenu;
		system("CLS");
		if(gotoMenu==1){
			menu();
		}else{
			menu();
		}
	}
	else if(mainChoice==2){
		a3.cabDetails();
		
	}else if(mainChoice==3){
		cout<<"------> Booking  a luxury hotel using the system <--------"<<endl;
		
		a4.hotels();
	}else if(mainChoice==4){
		cout<<"----------->Get your receipt<-----------"<<endl;
		a5.printBill();
		
		cout<<"Your receipt is already printed you can get it from file path\n"<<endl;
		cout<<"To display the your receipt in the screen,Enter 1: or Enter another key to bacj main menu:";
		cin>>gotoMenu;
		if(gotoMenu==1){
			system("CLS");
			a5.showBill();
			cout<<"\n Press 1 to redirect main menu:";
			cin >>gotoMenu;
			system("CLS");
			if(gotoMenu==1){
				menu();
			}else{
				menu();
			}
		}
		else {
			system("CLS");
			menu();
			
		}
			
			
		
	}else if(mainChoice==5){
	            cout<<"Enter your option\n";
                cout<<"1. New trips\n";
                cout<<"2. Display a Trip\n";
                cout<<"3. Update Trip\n";
                cout<<"\nENTER UR CHOICE: ";
                cin>>ch1;
                system("CLS");
                    if(ch1==1){
                    	t1.ad_writedata();
                    	
					}else if(ch1==2){
						t1.ad_display();
					}else if(ch1==3){
						t1.ad_modify();
					} else{
			cout<<"Invalid Input! Resirecting to Previous Menu\n Please Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		
		cout<<"\nPress 1 to Redirect main menu:";
		cin>>gotoMenu;
		system("CLS");
		if(gotoMenu==1){
			menu();
		}else{
			menu();
		}
                           
                            
                        
                        
                       
                           
          
		
	   
	}else if(mainChoice==6){
	            cout<<"Enter your option\n";
                cout<<"1. New Reservation\n";
                cout<<"2. Search Reservation\n";
                cout<<"3. Cancel Reservation\n";
                cout<<"\nENTER UR CHOICE: ";
                cin>>ch1;
                system("CLS");
                    if(ch1==1){
                    	cout<<"-----------------------------------";
                        cout<<"\n Choose Your destination\n";
                        cout<<"-----------------------------------\n";
                    	t1.ad_display();
                    	cout<<"\n";
                    	t1.us_writedata();
                    	
					}else if(ch1==2){
						t1.us_search();
					}else if(ch1==3){
						t1.us_modify();
					} else{
			cout<<"Invalid Input! Resirecting to Previous Menu\n Please Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		
		cout<<"\nPress 1 to Redirect main menu:";
		cin>>gotoMenu;
		system("CLS");
		if(gotoMenu==1){
			menu();
		}else{
			menu();
		}
                           
                            
                        
                        
                       
                           
          
		
	   
	}else if(mainChoice==7){
		cout<<"------>GOOD BYE<-------"<<endl;
		Sleep(999);
		system("CLS");
		menu();
	}else{
		
		cout<<"Invalid Input! Resirecting to Previous Menu\n Please Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
	}
  	
	
	
}

int main(){
	 ManageMenu startObj;
	 
	 
	return 0;
}
