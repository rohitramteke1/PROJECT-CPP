#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; 

void text_appearing_effect(string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
        cout << "*" ;

    for (int j = size; j > 0; j--)
        cout << "\b";

    for (int j = 0; j < size; j++)
    {
        sleep_for(microseconds(500000));
        cout << s[j];
    }
}

int main()
{
    string s = "Project maker";
    text_appearing_effect(s);
    return 0;
}