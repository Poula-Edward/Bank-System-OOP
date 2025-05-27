#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsTotalBlancesScreen :protected clsScreen
{
public:

    static void ShowTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balance Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Clients";

        _DrawScreenHeader(Title, SubTitle);
        cout << "_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance\n";

        cout << "________________________________________________________";
        cout << "____________________________________\n\n";

        if (vClients.empty())
        {
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        }
        else
        {
            for (clsBankClient &Client : vClients)
            {
                cout << "| " << setw(15) << left << Client.GetAccountNumber();
                cout << "| " << setw(40) << left << Client.GetFullName();
                cout << "| " << setw(12) << left << Client.GetAccountBalance() << endl;
            }
        }

        cout << "_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << "\t\t\t\t\t   Total Balances = " << clsBankClient::GetTotalBalances() << endl;
    }



};