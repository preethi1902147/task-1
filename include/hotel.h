#pragma once
#include<string>
using namespace std;
class hotel
{
	
	public:
		string sql, category, input, room, floor, type, price, user_name, ps_word, email_id, name, ph_num, hotel_id, hotel_name, is_available, psw;
		string connectionC = "dbname = HOTEL user = postgres password = admin@123 hostaddr = 127.0.0.1 port = 5432";
		void display();
		void displaytable();
		void search();
		void bookroom();
		void update();
		void add();
	void deleteroom();
		
};

