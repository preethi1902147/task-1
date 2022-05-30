
#include<iostream>
#include<pqxx/pqxx>
#include <string>
#include "VariadicTable.h"
#include "include\hotel.h"
#include"include/user.h"

using namespace std;
using namespace pqxx;






int main()
{
	hotel p;
	user u;
	
	string  choice;
	int LoginVariable;
	LoginVariable = u.login();
	if (LoginVariable == 0)   //guest
	{

		cout << " opened database successfully " << endl;
		cout << " ";
		cout << " ";
		cout << "--------------------------------------------------------" << endl;
		cout << "    HOTELS AVAILABLE" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << " ";
		p.display();
		do {
			
			cout << " ";
			cout << " ";
			cout << "--------------------------------------------------------" << endl;
			cout << "OPERATIONS :- " << endl;
			cout << "--------------------------------------------------------" << endl;
			
			cout << "a).book a room :\nb).search a room\nc).display list " << endl;
			cout << " ";
			cin >> choice;
			if ((choice == "a") || (choice == "A"))
			{
				
				p.displaytable();
				p.bookroom();
				cout << " ";
				cout << " ";
				cout << "do you want to continue the function:- (yes/no)" << endl;
				cin >> choice;
				cout << "   " << endl;
				system("cls");

			}

			else if ((choice == "b") || (choice == "B"))
			{
				
				p.displaytable();
				p.search();
				cout << " ";
				cout << " ";
				cout << "do you want to continue the function:- (yes/no)" << endl;
				cin >> choice;
				system("cls");
			}

		
			else if ((choice == "c") || (choice == "C"))
			{
				p.display();
				p.displaytable();
				cout << " ";
				cout << " ";
				cout << "do you want to continue the function:- (yes/no)" << endl;
				cin >> choice;
				system("cls");
			}
			else {

				cout << "wrong choice" << endl;
				cout << " ";
				cout << " ";
				cout << "do you want to continue the function:- (yes/no)" << endl;
				cin >> choice;
				system("cls");
				
			}

		} while ((choice.compare("yes") == 0) || (choice.compare("YES") == 0));

	}
	else if (LoginVariable == 2)   //receptionist
{
cout << " opened database successfully " << endl;
    system("cls");
     p.display();



    do {

	cout << " ";
	cout << " ";
	cout << "--------------------------------------------------------" << endl;
	cout << "OPERATIONS :- " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "a).book a room :\nb).search a room\nc).update the room\nd).add a room\ne).display the hotel list\nf).add a person\ng).remove a room\nh).remove a person\ni).userdetails\nj).update user details " << endl;
	cout << " ";
	cin >> choice;
	if ((choice == "a") || (choice == "A"))
	{
		p.displaytable();
		p.bookroom();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");

	}

	else if ((choice == "b") || (choice == "B"))
	{
		p.displaytable();
		p.search();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}

	else if ((choice == "c") || (choice == "C"))
	{
		p.displaytable();
		p.update();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}

	else if ((choice == "d") || (choice == "D"))
	{
		p.displaytable();
		p.add();
		
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");

	}
	else if ((choice == "e") || (choice == "E"))
	{
		p.display();
		p.displaytable();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}
	else if ((choice == "f") || (choice == "F"))
	{
		u.userdetails();
		u.addperson();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}
	else if ((choice == "g") || (choice == "G"))
	{   
		p.displaytable();
		p.deleteroom();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}
	else if ((choice == "h") || (choice == "H"))
	{
		u.userdetails();
		u.deleteuser();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}
	else if ((choice == "i") || (choice == "I"))
	{
		u.userdetails();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}
	else if ((choice == "j") || (choice == "J"))
	{
		u.userdetails();
		u.updateusers();
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}

	else {

		cout << "wrong choice" << endl;
		cout << " ";
		cout << " ";
		cout << "do you want to continue the function:- (yes/no)" << endl;
		cin >> choice;
		system("cls");
	}

} while ((choice.compare("yes") == 0) || (choice.compare("YES") == 0));
	}



	else {
		cout << "Can't open database" << endl;

	}
	return 0;
}