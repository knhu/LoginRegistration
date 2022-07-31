#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool isRegistered() 
{
    string user;
    string psswd;
    string username, password;

    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter your password: ";
    cin >> psswd;

    ifstream read(user + ".txt");
    getline(read, username);
    getline(read, password);

    if (user == username && psswd == password)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main() 
{
    int userChoice;

    cout << endl;
    cout << "           Welcome to your login page          " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Register a new user" << endl;
    cout << "2. Login as existing user" << endl;
    cout << endl;
    cout << "Please enter a choice (1-2): ";
    cin >> userChoice;

    if (userChoice == 1) 
    {
        string user, psswd;

        cout << "Begin your registration: " << endl;
        cout << endl;
        cout << "Please enter a username: ";
        cin >> user;
        cout << "Please enter a password: ";
        cin >> psswd;

        ofstream userFile;
        userFile.open(user + ".txt");
        userFile << user << endl << psswd;
        userFile.close();
        cout << "Thank you for registering, " << user << "!" << endl;
    }
    else if (userChoice == 2) {
        bool userStatus = isRegistered();

        if (!userStatus) 
        {
            system("clear");
            cout << endl;
            cout << "I'm sorry. That login appears to be invalid." << endl;
            main();
            return 0;
        }
        else 
        {
            cout << "Congratulations! You've successfully logged in!" << endl;
            cout << endl;

            int secondChoice;

            cout << "Welcome back!" << endl;
            cout << endl;
            cout << "DASHBOARD" << endl;
            cout << "There are no outstanding messages for you." << endl;
            cout << endl;
            cout << "1. Log Out" << endl;
            cout << "2. Go back to main menu" << endl;
            cin >> secondChoice;

            if (secondChoice == 1)
            {
                system("exit");
            }
            else if (secondChoice == 2)
            {
                main();
            }
            return 1;
        }
    }
}