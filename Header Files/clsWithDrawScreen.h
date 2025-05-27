#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsWithDrawScreen :protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card: ";
        cout << "\n-------------------";
        cout << "\nFirst Name     :" << Client.GetFirstName();
        cout << "\nLast Name      :" << Client.GetLastName();
        cout << "\nFull Name      :" << Client.GetFullName();
        cout << "\nEmail          :" << Client.GetEmail();
        cout << "\nPhone          :" << Client.GetPhone();
        cout << "\nAccount Number :" << Client.GetAccountNumber();
        cout << "\nAccount Balance:" << Client.GetAccountBalance();
        cout << "\nPassword       :" << Client.GetPinCode();
        cout << "\n-------------------\n";
    }

    static string _ReadAccountNumber()
    {
        cout << "\nPlease Enter The Account Number ";
        string AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
    static void ShowWithDrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDoubleNumber();

        cout << "\nAre you sure you want to perform this transaction..(y/n)? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
           if( Client1.WithDraw(Amount))
           { 
            cout << "\nAmount Withdrew Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
           }
           else
           {
               cout << "\nCannot withdraw, Insuffecient Balance!\n";
               cout << "\nYou Want To WithDraw: " << Amount;
               cout << "\nBut Your Balance is: " << Client1.GetAccountBalance();
               
           }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};