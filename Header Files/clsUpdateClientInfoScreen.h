#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientInfoScreen :protected clsScreen
{
private:
    static void _ReadClientInformation(clsBankClient &Client)
    {
        cout << "\nEnter First Name :";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name :";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email :";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone :";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode :";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance :";
        Client.SetAccountBalance(clsInputValidate::ReadDoubleNumber());
    }

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
    static void ShowUpdateClientInfoScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PUpdateClient))
        {
            return;// this will exit the function and it will not continue
        }   
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Client Number You Need To Update It\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Not Found, Please Enter Another One ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        char Answer = 'n';
        cout << "\nAre You Sure You Want To Update This Client (y/n)?..";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _ReadClientInformation(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            if(SaveResult == clsBankClient::enSaveResults::SaveSucceeded)
            {
                cout << "\nAccount Updated Successfully \n";
                _PrintClient(Client1);

            }
            else
            {
                cout << "]nError Account was not saved because it's Empty";

            }

        }
    }
};