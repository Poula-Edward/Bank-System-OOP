#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber; 
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLineToObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]) );
    
    }

    static clsBankClient _EmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;

        fstream Myfile;
        Myfile.open("../Data Files/Clients.txt", ios::in); //! READ MODE
        
        if(Myfile.is_open())
        {
            string Line;

            while(getline(Myfile, Line))
            {
                clsBankClient Client = _ConvertLineToObject(Line);
                vClients.push_back(Client);
            }

            Myfile.close();
        }

        return vClients;
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.GetAccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
    {
        fstream Myfile;

        Myfile.open("../Data Files/Clients.txt", ios::out);

        string DataLine;

        while(Myfile.is_open())
        {
            for(clsBankClient C : vClients)
            {
                if(C._MarkedForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    Myfile << DataLine << endl;
                }
                
            }

            Myfile.close();
        }
    }

    void _UpdateInfoInFile()
    {
        vector<clsBankClient>vClients;
        vClients = _LoadClientsDataFromFile();

        for(clsBankClient& C: vClients)
        {
            if(C._AccountNumber == GetAccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("../Data Files/Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNewInfoToFile()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, double AccountBalance)
    : clsPerson(FirstName, LastName, PhoneNumber, Email)
    {
        _Mode = Mode;
        _AccountBalance = AccountBalance;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
    }

    bool IsEmptyMode()
    {
        return (_Mode == enMode::EmptyMode);  //! We Will Use It Later On
    }

    string GetAccountNumber() //! READ ONLY
    {
        return _AccountNumber;
    }
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    static clsBankClient Find(string AccountNumber)
    {
        
        fstream MyFile;
        MyFile.open("../Data Files/Clients.txt", ios::in); //! READ MODE

        if(MyFile.is_open())
        {
            string Line;
            while(getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToObject(Line);
                if(Client.GetAccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            
            }

            MyFile.close();
        }

        return _EmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); //! READ MODE

        if(MyFile.is_open())
        {
            string Line;
            while(getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToObject(Line);
                if(Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            
            }

            MyFile.close();
        }

        return _EmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = Find(AccountNumber);
        return (!Client1.IsEmptyMode()); 
    }

    enum enSaveResults {SaveFailedEmptyObject = 0, SaveSucceeded = 1, SaveFailedAccountNumIsExist = 2};

    enSaveResults Save()
    {
        if(_Mode == enMode::EmptyMode)
        {
            return enSaveResults::SaveFailedEmptyObject;
        }
        else if(_Mode == enMode::UpdateMode)
        {
            _UpdateInfoInFile();
            return enSaveResults::SaveSucceeded;
        }
        else if(_Mode == enMode::AddNewMode)
        {
            if(clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::SaveFailedAccountNumIsExist;
            }
            else
            {
                _AddNewInfoToFile();
                _Mode = enMode::UpdateMode;
                return enSaveResults::SaveSucceeded;
            }
        }

        return enSaveResults::SaveFailedEmptyObject;
    }

    static clsBankClient AddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient>vClients;
        vClients = _LoadClientsDataFromFile();
        for(clsBankClient & C : vClients)
        {
            if(C._AccountNumber == _AccountNumber)
            {
                C._MarkedForDelete = true; //!  بعلم علي العميل في الفايل انو محذوف دا عشان واحنا بنحفظ البيانات في الملف عشان اللي متعلم عليه بالحذف ميتكتبش في الملف
                _MarkedForDelete = true;   //! بعلم علي الكائن الحالي انو اتحذف
                break;
            }
        }

        if(_MarkedForDelete)
        {
            _SaveClientsDataToFile(vClients);
            *this = _EmptyClientObject();

            return true;
        }

        *this = _EmptyClientObject();
        return false;
    }

    static vector<clsBankClient>GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient>vClients;
        vClients = _LoadClientsDataFromFile();
        double TotalBalances = 0;
        for(clsBankClient & C : vClients)
        {
            TotalBalances += C.GetAccountBalance();
        }
        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance+=Amount;
        Save();
    }

    bool WithDraw(double Amount)
    {
        if(Amount > _AccountBalance)
        {
            return false;
        }
        
        
        _AccountBalance-=Amount;
        Save();
        return true;
        
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient)
    {
        if(Amount > _AccountBalance)
        {
            return false;
        }

        WithDraw(Amount);
        DestinationClient.Deposit(Amount);
        return true;
    }
};

