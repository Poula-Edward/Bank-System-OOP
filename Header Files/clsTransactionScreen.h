#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"


class clsTransactionScreen :protected clsScreen
{
private:
    enum enTransactionMenueOptions
    {
        eDeposite = 1, eWithDraw = 2, eShowTotalBalance = 3,eTransfer = 4, eShowMainMenue = 5
    };

    static int _ReadTransactionMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;

    }

    static void _GoBackToTransactionMenue()
    {
        cout << "\n\nPress Any Key To Go Back To Transaction Menue..";
        system("pause");
        ShowTransactionMenue();
    }

    static void _ShowDepositeScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBlancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _PerformTransactionMenueOption(enTransactionMenueOptions Option)
    {
        if(Option == enTransactionMenueOptions::eDeposite)
        {
            system("cls");
            _ShowDepositeScreen();
            _GoBackToTransactionMenue();
        }
        else if(Option == enTransactionMenueOptions::eWithDraw)
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionMenue();
        }
        else if(Option == enTransactionMenueOptions::eShowTotalBalance)
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionMenue();
        }
        else if(Option == enTransactionMenueOptions::eTransfer)
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenue();
        }
    }

public:
    static void ShowTransactionMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PTransaction))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMainMenueOption());
    }
};