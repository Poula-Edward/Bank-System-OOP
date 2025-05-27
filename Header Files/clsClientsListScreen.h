#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsClientsListScreen : protected clsScreen
{
private:
    static void _PrintClientRecord(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(15) << left << Client.GetFullName();
        cout << "| " << setw(10) << left << Client.GetPhone();
        cout << "| " << setw(18) << left << Client.GetEmail();
        cout << "| " << setw(6)  << left << Client.GetPinCode();
        cout << "| " << setw(8)  << left << Client.GetAccountBalance();
        cout << "|\n";
    }

public:
    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PListClients))
        {
            return;// this will exit the function and it will not continue
        }

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "User List Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        
        cout << setw(8) << left << "" << string(85, '_') << "\n\n";

        
        cout << setw(8) << left << "" << "| " << setw(15) << left << "Account Number";
        cout << "| " << setw(15) << left << "Full Name";
        cout << "| " << setw(10) << left << "Phone";
        cout << "| " << setw(18) << left << "Email";
        cout << "| " << setw(6)  << left << "Pin";
        cout << "| " << setw(8)  << left << "Balance";
        cout << "|\n";

        
        cout << setw(8) << left << "" << string(85, '_') << "\n";

        if (vClients.empty())
        {
            cout << "\nNo Clients Available In The System\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecord(Client);
            }
        }

       
        cout << setw(8) << left << "" << string(85, '_') << "\n";
    }
};
