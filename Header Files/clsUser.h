#pragma once
#include<iostream>
#include"clsString.h"
#include"clsPerson.h"
#include<vector>
#include<fstream>

using namespace std;

class clsUser :public clsPerson
{
private:
    enum enMode {EmptyMode = 0, UpdateMode =1, AddNewMode=2};

    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permission;
    bool _MarkedForDelete = false;

    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);
        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]) );
    
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.GetFirstName() + Seperator;
        UserRecord += User.GetLastName() + Seperator;
        UserRecord += User.GetEmail() + Seperator;
        UserRecord += User.GetPhone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += User.GetPassword() + Seperator;
        UserRecord += to_string(User.GetPermission());

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("../Data Files/Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("../Data Files/Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U._UserName == GetUserName())
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNewInfoToFile()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("../Data Files/Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
public: 
    enum enPermissions 
    {
        eAll = 1, PListClients = 2, PAddNewClients = 3, PDeleteClient = 4, PUpdateClient = 8, PFindClient = 16, PTransaction = 32, PManageUsers = 64
    };      
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int permission) :
    clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permission = permission;

    }

    bool IsEmptyMode()
    {
        return (_Mode == enMode::EmptyMode);  //! We Will Use It Later On
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    int GetPermission()
    {
        return _Permission;
    }

    void SetPermission(int Permission)
    {
        _Permission = Permission;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("../Data Files/Users.txt", ios::in); //! READ MODE

        if(MyFile.is_open())
        {
            string Line;
            while(getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if(User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("../Data Files/Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.GetUserName()== UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

   enSaveResults Save()
    {
        if(_Mode == enMode::EmptyMode)
        {
            return enSaveResults::svFaildEmptyObject;
        }
        else if(_Mode == enMode::UpdateMode)
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        else if(_Mode == enMode::AddNewMode)
        {
            if(clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNewInfoToFile();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }

        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmptyMode());
    }

     bool Delete()
    {
        vector<clsUser>vUsers;
        vUsers = _LoadUsersDataFromFile();
        for(clsUser & U : vUsers)
        {
            if(U._UserName == _UserName)
            {
                U._MarkedForDelete = true; //!  بعلم علي العميل في الفايل انو محذوف دا عشان واحنا بنحفظ البيانات في الملف عشان اللي متعلم عليه بالحذف ميتكتبش في الملف
                _MarkedForDelete = true;   //! بعلم علي الكائن الحالي انو اتحذف
                break;
            }
        }

        if(_MarkedForDelete)
        {
            _SaveUsersDataToFile(vUsers);
            *this = _GetEmptyUserObject();

            return true;
        }

        *this = _GetEmptyUserObject();
        return false;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->GetPermission()== enPermissions::eAll)
            return true;

        if ((Permission & this->GetPermission()) == Permission)
            return true;
        else
            return false;

    }


    

};