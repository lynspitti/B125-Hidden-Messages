#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>

class Login
{
    public:
        Login(char *SysPath, char *IP);
        virtual ~Login();
        bool CheckLogin(char *UserName, char *PassWord);
        bool CheckIfBlocked(char *IP);
        void BlockConnection();
        void ReadSystem();
        int Attempts;
    protected:

    private:
        char *Connection;
        void ReadSystem(char* path);
};

#endif // LOGIN_H
