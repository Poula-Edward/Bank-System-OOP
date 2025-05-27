#pragma once
#include"clsUser.h"
#include<iomanip>
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"Global.h"

class clsLoginScreen :protected clsScreen
{
private:
    static void _Login()
    {
        bool LoginFaild = false;

        string UserName, Password;

        do
        {

            if(LoginFaild)
            {
                cout << "\nInvalid UserName/Password!\n\n";
            }
            
            cout << "Enter UserName ";
            cin >> UserName;

            cout << "Enter Password ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFaild = CurrentUser.IsEmptyMode();

        } while (LoginFaild);
        
        clsMainScreen::ShowMainScreen();
    }

public:
    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }
};



