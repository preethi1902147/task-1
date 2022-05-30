#include "user.h"
#include<iostream>
#include<pqxx/pqxx>
#include <string>
#include "VariadicTable.h"

using namespace std;
using namespace pqxx;


int user::login()
{
	pqxx::connection C(connectionC.c_str());
	char option;
	int sign_up;
	cout << "a) sign in as a guest:-\t\nb) sign up as new member:-\t\nc) sign in as authorizes person:-";
	cin >> option;

	switch (option) {
	case 'a':
	case 'A':
	{

		cout << "enter the user name  :" << endl;
		cin >> user_name;
		cout << "enter the password  :" << endl;
		cin >> ps_word;
		cout << "    ";
		sql = "SELECT password FROM users WHERE username = '" + user_name + "'";
		work W(C);
		pqxx::result R = W.exec(sql);

		for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
			psw = c[0].as<string>();

		}

		W.commit();
		if (psw == ps_word)
		{
			return 0;
		}
		else
			return 1;
		break;
	}
	case'b':
	case 'B':
	{
		sign_up = signup();
		return sign_up;
		break;
	}

	case'c':
	case 'C':
	{
		cout << "enter authorized id : ";
		cin >> user_name;
		cout << "enter password : ";
		cin >> ps_word;
		sql = "SELECT password FROM users WHERE username = 'jenny.2'";
		work W(C);
		pqxx::result R = W.exec(sql);

		for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
			psw = c[0].as<string>();
		}
		W.commit();
		if (psw == ps_word)
		{
			return 2;
		}
		else
		{
			return 1;
		}
		break;
	}
	default:
		cout << "invalid option ";
		break;
	}
}



int user::signup()
{
	pqxx::connection C(connectionC.c_str());

	cout << "enter the name  :" << endl;
	cin >> name;
	cout << "enter the email id  :" << endl;
	cin >> email_id;
	cout << "enter the user name  :" << endl;
	cin >> user_name;
	cout << "enter the phone number  :" << endl;
	cin >> ph_num;
	cout << "enter the password  :" << endl;
	cin >> ps_word;
	sql = "INSERT INTO users (name,email_address,phone_number,username,password) "
		"VALUES ('" + name + "','" + email_id + "','" + ph_num + "','" + user_name + "','" + ps_word + "'); ";

	/* Create a transactional object. */
	work W(C);

	/* Execute SQL query */

	W.exec(sql);
	W.commit();
	return 0;
}


void user::deleteuser()
{

	pqxx::connection C(connectionC.c_str());
	cout << "which username to remove : " << endl;
	cin >> user_name;
	cout << "   " << endl;

	/* Create  SQL DELETE statement */
	sql = "DELETE from USERS where USERNAME ='" + user_name + "'";
	/* Execute SQL query */
	work W(C);
	W.exec(sql);
	W.commit();
	cout << "   " << endl;
	cout << "user :" << user_name << " removed successfully" << endl;
	cout << "   " << endl;
}
void user::userdetails()
{
	pqxx::connection C(connectionC.c_str());
	sql = "SELECT * from USERS";

	/* Create a non-transactional object. */
	nontransaction N(C);
	/* Execute SQL query */
	result R(N.exec(sql));
	VariadicTable<string, string, string, string, string> vt({ "name", "email-address", "phone_number", "username", "password" });
	for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		vt.addRow(c[0].as<string>(), c[1].as<string>(), c[2].as<string>(), c[3].as<string>(), c[4].as<string>());
	}


	vt.print(cout);

	cout << " ";

}

void user::updateusers()
{
	pqxx::connection C(connectionC.c_str());
	cout << "enter the username to update: ";
	cin >> user_name;
	cout << "enter the category to update: ";
	cin >> category;
	cout << "enter the new value to update: ";
	cin >> input;
	cout << "    ";

	/* Create a transactional object. */

	sql = "UPDATE users set  " + category + "  = '" + input + "' where username = '" + user_name + "' ";

	/* Execute SQL query */
	work W(C);
	W.exec(sql);
	W.commit();

}

void user::addperson()
{
	pqxx::connection C(connectionC.c_str());

	cout << "enter the name  :" << endl;
	cin >>name;
	cout << "enter the email id  :" << endl;
	cin >>email_id;
	cout << "enter the user name  :" << endl;
	cin >>user_name;
	cout << "enter the phone number  :" << endl;
	cin >>ph_num;
	cout << "enter the password  :" << endl;
	cin >>ps_word;
	sql = "INSERT INTO users (name, email_address, phone_number, username, password) "
		"VALUES ('"+name+"','"+email_id+"','"+ph_num+"','"+user_name+"','"+ps_word+"'); ";

	/* Create a transactional object. */
	work W(C);

	/* Execute SQL query */

	W.exec(sql);
	W.commit();
}


