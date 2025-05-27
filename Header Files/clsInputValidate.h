#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

class clsInputValidate
{
public:
    static bool IsNumberBetween(int Number, int From, int To)
    {
        if(Number <= To && Number >= From)
            return true;
        else 
            return false;
    }
    static bool IsNumberBetween(double Number, double From, double To)
    {
        if(Number <= To && Number >= From)
            return true;
        else  
            return false;
    }
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        if((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
        && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        if(clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To) 
        && clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
        {
            return true;
        }   
        return false;
    }
    static int ReadIntNumber(string ErrorMsg = "Invalid Number, Enter Again\n")
    {
        int Number;
        while(!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMsg;
        }
        return Number;
    }
    static double ReadDoubleNumber(string ErrorMsg = "Invalid Number, Enter Again\n")
    {
        double Number;
        while(!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMsg;
        }
        return Number;
    }
    static int ReadIntNumberBetween(int From, int To, string ErrorMsg = "Invalid Number, Enter Again\n")
    {
        int Number = ReadIntNumber();
        while(!(IsNumberBetween(Number,From, To)))
        {
            cout << ErrorMsg;
            Number = ReadIntNumber();
        }

        return Number;
    }
    static double ReadDoubleNumberBetween(double From, double To, string ErrorMsg = "Invalid Number, Enter Again\n")
    {
        double Number = ReadDoubleNumber();
        while(!IsNumberBetween(Number,From, To))
        {
            cout << ErrorMsg;
            Number = ReadDoubleNumber();
        }
        return Number;
    }

    static bool IsValidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string S;
        getline(cin >> ws, S);
        return S;
    }
};