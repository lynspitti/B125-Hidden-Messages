#include "Login.h"
#include "string.h"
#include <iostream>
using namespace std;

int Attempts = 0;
char *Connection;


//System information....
char *_syspath;
char *_Username;
char *_Password;
char *_BlockedIP;
//...................
Login::Login(char *SysPath, char *IP)
{
    Connection = IP;
    _syspath = SysPath;
    ReadSystem(SysPath);
    if (CheckIfBlocked(IP) == true){
        //Error?
    }
}

bool Login::CheckIfBlocked(char *IP)
{
    if(&IP == &_BlockedIP){
        return true;
    }
    else{
        return false;
    }
}

bool Login::CheckLogin(char *UserName, char *PassWord)
{
    if (strcmp(UserName,_Username) == 0){
        if (strcmp(PassWord,_Password) == 0){
            return true;
        }
        else{
            return false;
        }
    }
}
void Login::BlockConnection()
{

}
Login::~Login()
{
    //dtor
}

void Login::ReadSystem(char *path)
{
    _Username = "Tester";
    _Password = "Pass";
    _BlockedIP = "1.1";
}
/*
char* Login::Read_Username(){
    return "Tester";
}
char* Login::Read_Password(){
    return "Pass";
}
char* Login::Read_BlockedIP(){
    return "1.1";
}
*/
