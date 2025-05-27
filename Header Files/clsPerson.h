#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;

public:

    clsPerson(string FirstName, string LastName, string Phone, string Email) //! constructor
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Phone = Phone;
        _Email = Email;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    string GetLastName()
    {
        return _LastName;
    }
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    string GetEmail()
    {
        return _Email;
    }
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    string GetPhone()
    {
        return _Phone;
    }
    string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }
};
