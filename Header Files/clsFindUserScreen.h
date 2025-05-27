#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsFindUserScreen :protected clsScreen
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmptyMode())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }

};
