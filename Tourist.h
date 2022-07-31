#ifndef TOURIST_H
#define TOURIST_H
#include <iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
#include"Cabs.h"
#include"Booking.h"
#include"Customers.h"
using namespace std;
void menu();

struct tour{
 	char ad_place[20],ad_code[20],ad_country[20],ad_days[20],ad_prices[20];
 	char us_phone[20],us_name[20],us_people[20],us_date[20],us_status[20],us_dcode[20];
};
class Tourist{
             public:
                void ad_pack(tour r);
	            tour ad_unpack(char a[]);
	            void ad_writedata();
	            void ad_display();
	            void ad_modify();
	            void us_pack(tour r);
	            tour us_unpack(char a[]);
	            void us_writedata();
	            void us_display();
	            void us_search();
	            void us_modify();
	            
};

#endif
