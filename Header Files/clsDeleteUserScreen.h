#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card: ";
        cout << "\n-------------------";
        cout << "\nFirst Name     : " << User.GetFirstName();
        cout << "\nLast Name      : " << User.GetLastName();
        cout << "\nFull Name      : " << User.GetFullName();
        cout << "\nEmail          : " << User.GetEmail();
        cout << "\nPhone          : " << User.GetPhone();
        cout << "\nPassword       : " << User.GetPassword();
        cout << "\nPermission     : " << User.GetPermission();
        cout << "\n-------------------\n";
    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";   

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }

    }
};