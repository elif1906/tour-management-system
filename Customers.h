#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
#include"Cabs.h"
#include"Booking.h"
#include"Tourist.h"
using namespace std;
void menu();
class Customers{
	public:
	string name,gender,address;
	int age,mobileNo;
	static int cusID;
	char all[999];	
	void getDetails();
	void showDetails();
};







#endif
