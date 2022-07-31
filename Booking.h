#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
#include"Customers.h"
#include"Cabs.h"
#include"Tourist.h"
using namespace std;
void menu();




class Booking{
	
	public:
		int choiceHotel;
		int packChoice;
		static float hotelCost;
		int gotomenu;
		string hotelNo[];
		void hotels();
};

#endif		
