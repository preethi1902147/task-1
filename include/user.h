#pragma once
#include "hotel.h"
#include <string>


using namespace std;

using namespace std;

class user :
    public hotel
{
  public:
    string sql;
    int login();
    int signup();
    void addperson();
    void deleteuser();
    void userdetails();
    void updateusers();

};

