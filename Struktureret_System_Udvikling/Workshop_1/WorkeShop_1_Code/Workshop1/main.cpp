#include <iostream>
#include "include/Login.h"
#include "string.h"

using namespace std;

int main()
{
    char path[] = "path";
    char ip[] = "1.2";

    int Attempts = 0;
    int MaxAttempts = 5;
    bool LoggedIn = false;

    Login *test = new Login(path,ip);
    while(Attempts < MaxAttempts && LoggedIn == false) {

        char username[10] = "";
        char Pass[10] = "";
        cout << "What is your username?" << endl;
        cin >> username;
        cout << "What is your password?" << endl;
        cin >> Pass;

        Attempts++;

        bool res = test->CheckLogin(username,Pass);
        if (!res && Attempts >= MaxAttempts) {
            test->BlockConnection();
            cout << "You have been blocked for too many failed attempts!" << endl;
        }
        else if (res) {
            LoggedIn = true;
            cout << "You are now logged in." << endl;
                test->ShowWelcomeScreen();
       } else
         cout << "You have entered a wrong login combination. (Remaining attempts: " << MaxAttempts - Attempts << ")" << endl;
    }
    return 0;
}
