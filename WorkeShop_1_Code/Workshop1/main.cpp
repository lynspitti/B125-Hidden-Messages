#include <iostream>
#include <Login.h>
using namespace std;

int main()
{
    char path[] = "path";
    char ip[] = "1.2";

    Login *test = new Login(path,ip);

    char username[] = "Tester";
    char Pass[] = "Pass";

    bool res = test->CheckLogin(username,Pass);
    if (!res && test->Attempts > 5){
        test->BlockConnection();
        cout << "You have been blocked for too many attempts." << endl;
    }
    else if (res){
        cout << "You are now logged in." << endl;
        cout << "Welcome." << endl;
    }
    char Message[] = "Hello world! ";
    //char FinMessage = message + test->Attempts;
    cout << Message << endl;
    return 0;
}
