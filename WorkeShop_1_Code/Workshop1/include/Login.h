#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include "string.h"

using namespace std;

class Login
{
    public:
        Login(char *SysPath, char *IP);
        virtual ~Login();
        bool CheckLogin(char *UserName, char *PassWord);
        bool CheckIfBlocked(char *IP);
        void BlockConnection();
        void ShowWelcomeScreen();
        void ReadSystem();
    protected:

    private:
        char *Connection;
        void ReadSystem(char* path);
};

#endif // LOGIN_H
