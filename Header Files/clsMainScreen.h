#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientInfoScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eExit = 8
    };

    static int _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static void _GoBackToMainMenueOption()
    {
        cout << "\nPress any Key To Go Back To Main Menue....\n";
        system("pause>0");
        ShowMainScreen();
    }

    static void _ShowAllClientScreen()
    {
        clsClientsListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientInfoScreen()
    {
        clsUpdateClientInfoScreen::ShowUpdateClientInfoScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionMenue()
    {
        clsTransactionScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersScreen()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _LogOut()
    {
        CurrentUser = clsUser::Find("","");
    }

    static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
    {   
        if(MainMenueOption == enMainMenueOptions::eListClients)
        {
            system("cls");
            _ShowAllClientScreen();
            _GoBackToMainMenueOption();   
        }
        else if(MainMenueOption == enMainMenueOptions::eAddNewClient)
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eDeleteClient)
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eUpdateClient)
        {
            system("cls");
            _ShowUpdateClientInfoScreen();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eFindClient)
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eShowTransactionsMenue)
        {
            system("cls");
            _ShowTransactionMenue();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eManageUsers)
        {
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenueOption();
        }
        else if(MainMenueOption == enMainMenueOptions::eExit)
        {
            system("cls");
            _LogOut();
        }

        
    }

public:

    static void ShowMainScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }



};

