#ifndef CABS_H
#define CABS_H
#include <iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
#include"Customers.h"
#include"Booking.h"
#include"Tourist.h"
using namespace std;
void menu();
class Cabs{
	
	public:
		int cabChoice;
		int kilometers;
		float cabCost;
		static float lastcabCost;
		
		void cabDetails();
	
	
};






#endif
