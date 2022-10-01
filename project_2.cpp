/************************************************************************
 * Author   : Rohit
 * Date     : 2021-10-21
 * Aim      : Password Filling Program
 * ***********************************************************************/

// we can see there is no notepad is openend in bottom section of the window
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h> // Sleep()
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h> // cls()
#include <chrono>
#include <thread>
// #include <limits.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

#define BKSP 8    // BACKSPACE
#define TAB 9     // TAB
#define ENTER 10  // ENTER
#define RETURN 13 // Carriage Return

class Password
{
    protected:
        char str[100];
        int i = 0;
        char ch = ' ';
        string line;

    // public:
    //     string password(); // Encrypt
    //     void eraseLine(string line); // for erasing the line
};
class Member_Password : public Password
{
    public:
        string password();           // Encrypt
        void password_instructions(void);           // Instructions
        void eraseLine(string line); // for erasing the line
};
void Member_Password::password_instructions()
{
    system("cls");
    system("color a"); // Black Text, white background
    cout << endl << "::::::CPP Program to demonstrate password Encrypting.:::::: " ;
    cout << endl << "---------------------------------------------------------------";
    cout << endl << ".:: Criteria for strong password is as follows : " ;
    cout << endl << ".:: At least 8 characters-the more characters, the better.  " ;
    cout << endl << ".:: A mixture of both uppercase and lowercase letters." ;
    cout << endl << ".:: A mixture of letters and numbers." ;
    cout << endl << ".:: Inclusion of at least one special character, e.g., ! @ # ? ]" ;
    cout << endl << ".:: Press any key to continue . . . " ;
    _getch() ;
}
void Member_Password::eraseLine(string line)
{
    int size = line.size() - 1;
    cout << line;
    _getch(); // Press any key . . .
    while (size > -1)
    {
        sleep_for(microseconds(1000));
        cout << "\b \b";
        size--;
    }
}

string Member_Password::password()
{
    while (ch != ENTER || ch != TAB || ch == RETURN)
    {
        ch = getch();
        if (ch == BKSP && i > 0)
        {
            cout << "\b \b";
            i--;
        }
        else if (ch == BKSP)
        {
            cout << "";
        }
        else if (ch == RETURN || ch == ENTER || ch == TAB)
        {
            if (i < 8)
            {
                string line = "Passwword is atleast longer than 8 characters.Press any key to continue . . ." ;
                eraseLine(line);
            }
            else
                break;
        }
        else
        {
            cout << "*";
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0';
    return str;
}

int main()
{
    Member_Password password_class_object; // Member_Password Object
    password_class_object.password_instructions();
    system("cls");                         // clear Screen()
    string user_name;                      // user-name
    char ch;                               // taking "yes" or "no" in 'y' or 'n' format

    fstream fout;
    fout.open("password.txt", ios::out | ios::app);

    // Taking user-name and password from the user and Encrypting the password
    cout << "User-name: ";
    cin >> user_name;
    cout << "Password:  ";
    string user_password = password_class_object.password(); // Password() call here

    // Writing the user-name and password in password.txt
    fout << "\nUser-name: " << user_name;
    fout << "\nPassword: " << user_password;

    fout.close();

    cout << "\n\nWant to see password: (y/n) \n";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        cout << "\nPassword: " << user_password;
        cout << "\nOPEN the Existing NOTE-PAD Window from bottom pannel";
        cout << "\nSee Your saved Password";

        // Opening the password.txt using system()
        string open_notepad;
        open_notepad = "notepad.exe password.txt";
        system(open_notepad.c_str());
    }
    return 0;
}