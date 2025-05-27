#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << "| " << setw(12) << User.GetUserName()
             << "| " << setw(18) << User.GetFullName()
             << "| " << setw(12) << User.GetPhone()
             << "| " << setw(20) << User.GetEmail()
             << "| " << setw(10) << User.GetPassword()
             << "| " << setw(11) << User.GetPermission()
             << "|\n";
    }

public:

    static void ShowUsersList()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();

        string Title = "User List Screen";
        string SubTitle = "(" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        string line = string(89, '-');

        cout << line << "\n";

        cout << "| " << setw(12) << "UserName"
             << "| " << setw(18) << "Full Name"
             << "| " << setw(12) << "Phone"
             << "| " << setw(20) << "Email"
             << "| " << setw(10) << "Password"
             << "| " << setw(11) << "Permissions"
             << "|\n";

        cout << line << "\n";

        if (vUsers.empty())
        {
            cout << "\n\tNo Users Available In The System!\n";
        }
        else
        {
            for (clsUser User : vUsers)
            {
                _PrintUserRecordLine(User);
            }
        }

        cout << line << "\n";
    }
};
