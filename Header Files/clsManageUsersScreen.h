#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUpdateUserScreen.h"


class clsManageUsersScreen :protected clsScreen
{
private:
    enum enManageUsersScreenOptions
    {
        eListUsers=1, eAddNewUser=2, eDeleteUsers=3, eUpdateUser=4, eFindUser=5, eMainMenue=5
    };

    static int _ReadManageUserMenueOption()
    {
        int MenueOption = 0;
        MenueOption = clsInputValidate::ReadIntNumberBetween(1,6,"Please Enter Number Between 1 To 6 ");
        return MenueOption;
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddUsersScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUsersScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }  

    static void _ShowUpdateUsersScreen()
    {
       clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUsersScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _GoBackToManageUsersScreen()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _PerformManageUserMenueOption(enManageUsersScreenOptions Option)
    {
        if(Option == enManageUsersScreenOptions::eListUsers)
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersScreen();
        }
        else if(Option == enManageUsersScreenOptions::eAddNewUser)
        {
            system("cls");
            _ShowAddUsersScreen();
            _GoBackToManageUsersScreen();   
        }
        else if(Option == enManageUsersScreenOptions::eDeleteUsers)
        {
            system("cls");
            _ShowDeleteUsersScreen();
            _GoBackToManageUsersScreen();
        }
        else if(Option == enManageUsersScreenOptions::eUpdateUser)
        {
            system("cls");
            _ShowUpdateUsersScreen();
            _GoBackToManageUsersScreen();
        }
        else if(Option == enManageUsersScreenOptions::eFindUser)
        {
            system("cls");
            _ShowFindUsersScreen();
            _GoBackToManageUsersScreen();
        }
    }


public:
    
    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::PManageUsers))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUserMenueOption((enManageUsersScreenOptions)_ReadManageUserMenueOption());
    }
    
};