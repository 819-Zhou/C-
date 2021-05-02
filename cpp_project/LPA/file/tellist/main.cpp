#include "TelList.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

inline void cls()
{
    printf("\033[2J");
}

inline void wait()
{
    cout << "\nContinue with <enter> ...";
    cin.clear();
    while(cin.get() != '\n');
}

int menu();

int main()
{
    int ind;
    string temp;
    TelList list;
    int choice;
    bool run = true;
    while(run)
    {
        choice = menu();
        switch(choice)
        {
        case 1:
            cout << "\n[menu] -> [1]\n";
            list.print();
            break;

        case 2:
            cout << "\n[menu] -> [2]\n";
            cout << "First couple letters from the person: ";
            cin.ignore();
            getline(cin, temp);
            list.print(temp);
            break;

        case 3:
            cout << "\n[menu] -> [3]\n";
            list.getNewPerson();
            break;

        case 4:
            cout << "\n[menu] -> [4]\n";
            break;
        case 5:
            cout << "\n[menu] -> [5]\n";
            break;
        case 6:
            cout << "\n[menu] -> [6]\n";
            break;

        case 7:
            cout << "\n[menu] -> [7]\n";
            break;

        case 8:
            cout << "\n[menu] -> [8]\n";
            run = false;
            break;

        default:
            cout << "Not a available choice!\n";
            break;
        }
        if(run){
            wait();
            cls();
        }
    }
    cout << "\n*****\n"
    << "EXIT!\n"
    << "*****" << endl;
    return 0;
}

int menu()
{
    int choice = 0;
    cout << "\n********** Phone list **********\n\n"
         << "    1 -> Show every person\n"
         << "    2 -> Find the phone numbers\n"
         << "    3 -> Add a person\n"
         << "    4 -> Delete a person\n"
         << "--------------------------\n"
         << "    5 -> Open a file\n"
         << "    6 -> Save\n"
         << "    7 -> Save as ...\n"
         << "--------------------------\n"
         << "    8 -> Exit\n";

    cout << "\nYour choice(a number between 1 ~ 8): ";    
    cin.clear(); cin.sync();
    cin >> setw(1) >> choice;

    return choice;
}