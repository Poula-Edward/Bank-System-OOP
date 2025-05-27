#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"


class clsFindClientScreen : protected clsScreen
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
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PFindClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter The Account Number You Want To Find it..";
        AccountNumber = clsInputValidate::ReadString();

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        while(Client.IsEmptyMode())
        {
            cout << "\nAccount Number Is Not Found Enter Another One: ";
            AccountNumber = clsInputValidate::ReadString();
            Client = clsBankClient::Find(AccountNumber);
        }

        cout << "\nClient Found Successfully\n";
        _PrintClient(Client);

    }
};