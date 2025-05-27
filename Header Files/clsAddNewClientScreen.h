#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"iomanip"

class clsAddNewClientScreen :protected clsScreen
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
    static void AddNewClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::PAddNewClients))
        {
            return;// this will exit the function and it will not continue
        }
        
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number Of The Client Do You Want To Add :";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::AddNewClientObject(AccountNumber);
        _ReadClientInformation(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        if (SaveResult == clsBankClient::enSaveResults::SaveSucceeded)
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
        }
        else if (SaveResult == clsBankClient::enSaveResults::SaveFailedEmptyObject)
        {
            cout << "\nError account was not saved because it's Empty";
        }
        else if (SaveResult == clsBankClient::enSaveResults::SaveFailedAccountNumIsExist)
        {
            cout << "\nError account was not saved because account number is used!\n";
        }
    }
};