#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsDeleteClientScreen :protected clsScreen
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

public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number You Want To Delete :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, Please Enter Another one :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre You Sure You Want To Delete This Client (y/n)";
        char Answer = 'y';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError Client was not Deleted";
            }
        }
    }
};