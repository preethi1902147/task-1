#include "hotel.h"
#include<iostream>
#include<pqxx/pqxx>
#include <string>
#include "VariadicTable.h"

using namespace std;
using namespace pqxx;


void hotel::display()
{
	pqxx::connection C(connectionC.c_str());
	sql = "SELECT * from AVAILABLE_HOTELS ";

	/* Create a non-transactional object. */
	nontransaction N(C);
	/* Execute SQL query */
	result R(N.exec(sql));

	VariadicTable<string, string, string, string> vt({ "hotel_id", "hotel_name", "no_of_rooms", "type" });
	for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		vt.addRow(c[0].as<string>(), c[1].as<string>(), c[2].as<string>(), c[3].as<string>());
	}


	vt.print(cout);
	cout << " ";
	cout << " ";



}


void hotel::displaytable()
{
	pqxx::connection C(connectionC.c_str());
	sql = "SELECT * from ROOM";

	/* Create a non-transactional object. */
	nontransaction N(C);
	/* Execute SQL query */
	result R(N.exec(sql));
	VariadicTable<string, string, string, string, string, string> vt({ "hotel_id", "hotel_name", "room_number", "price", "floor","is_available" });
	for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		vt.addRow(c[0].as<string>(), c[1].as<string>(), c[2].as<string>(), c[3].as<string>(), c[4].as<string>(), c[5].as<string>());
	}


	vt.print(cout);

	cout << " ";


}

void hotel::search()
{
	pqxx::connection C(connectionC.c_str());
	cout << "category to search: ";
	cin >> category;
	cout << " your choice: ";
	cin >> input;
	cout << "     ";
	cout << "    ";


	sql = "SELECT * from  ROOM where " + category + " = '" + input + "' ";
	/* Create a non-transactional object. */
	nontransaction N(C);

	/* Execute SQL query */
	result R(N.exec(sql));

	VariadicTable<string, string, string, string, string, string> vt({ "hotel_id", "hotel_name", "room_number", "price", "floor", "is_available" });
	for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		vt.addRow(c[0].as<string>(), c[1].as<string>(), c[2].as<string>(), c[3].as<string>(), c[4].as<string>(), c[5].as<string>());
	}

	vt.print(cout);




}

void hotel::bookroom()
{
	pqxx::connection C(connectionC.c_str());

	cout << "enter the room number to book: ";
	cin >> room;
	cout << "    ";
	cout << "    ";

	sql = "SELECT is_available FROM ROOM WHERE ROOM_NUMBER = '" + room + "'";
	work W(C);
	pqxx::result R = W.exec(sql);

	for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		psw = c[0].as<string>();
	}
	W.commit();

	if (psw == "yes")
	{
		sql = "UPDATE ROOM set  is_available   = 'no' where room_number ='"+room+"'";

		/* Execute SQL query */
		work W(C);
		W.exec(sql);
		W.commit();
		cout << "YOUR ROOM HAS BEEN BOOKED SUCCESSFULLY\n\n";
		cout << "    ";
	}
	else
	{
		cout << "ROOM IS UNAVAILABLE\n\n";
	}

}

void hotel::deleteroom()
{
	
	pqxx::connection C(connectionC.c_str());
	cout << "which room number to remove : " << endl;
	cin >> room;
	cout << "   " << endl;
	
	/* Create  SQL DELETE statement */
	sql = "DELETE from  ROOM where ROOM_NUMBER = '" + room + "' ";
	/* Execute SQL query */
	work W(C);
	W.exec(sql);
	W.commit();
	cout << "   " << endl;
	cout << "room number :"<<room<<" removed successfully" << endl;
	cout << "   " << endl;
}

void hotel::update()
{
	pqxx::connection C(connectionC.c_str());

	cout << "enter the room number to update: ";
	cin >> room;
	cout << "enter the category to update: ";
	cin >> category;
	cout << "enter the new value to update: ";
	cin >> input;
	cout << "    ";

	/* Create a transactional object. */

	sql = "UPDATE ROOM set  "+category+"  = '"+input+"' where room_number = '"+room+"' ";

	/* Execute SQL query */
	work W(C);
	W.exec(sql);
	W.commit();


}

     
      

void hotel::add()
{
	pqxx::connection C(connectionC.c_str());

	cout << "enter the room number to add: ";
	cin >> room;
	cout << "enter the hotel id: ";
	cin >> hotel_id;
	cout << "enter the hotel name : ";
	cin >> hotel_name;
	cout << "enter the floor: ";
	cin >> floor;
	cout << "enter the price: ";
	cin >> price;
	cout << "enter the availability status: ";
	cin >> is_available;
	sql = "INSERT INTO room (hotel_id, hotel_name, room_number, price, floor, is_available) "
		"VALUES ('"+hotel_id+"','"+hotel_name+"', '"+room+"', '"+price+"','"+floor+"','"+is_available+"');";

	/* Create a transactional object. */
	work W(C);

	/* Execute SQL query */
	W.exec(sql);
	W.commit();
}