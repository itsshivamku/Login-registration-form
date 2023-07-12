#include <iostream>
#include <string>
#include <map>

using namespace std;

// to check if a username already exists
bool isUsernameTaken(const map<string, string>& users, const string& username) {
    return users.find(username) != users.end();
}

// to register a new user
void registerUser(map<string, string>& users) {
    string username, password;
    cout<< "enter a username: ";
    cin>> username;

    if (isUsernameTaken(users, username)) {
        cout<< "Username already taken. Please choose  another username"<< endl;
        return;
    }

    cout<< "enter a password: ";
    cin>> password;

    users[username] = password;
    cout<< "registration successfuliy" << endl;
}
bool authenticateUser(const map<string, string>& users, const string& username, const string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

//  to log in a user
void loginUser(const map<string, string>& users) {
    string username, password;
    cout<< "enter your username: ";
    cin>> username;

    cout<< "enter your password: ";
    cin>> password;

    if (authenticateUser(users, username, password)) {
        cout<< "Login successfully" << endl;
    } else {
        cout<< "wrong username or password. please try again" << endl;
    }
}

int main() {
    map<string, string> users;

    while (true) {
        cout<< "1. Register"<< endl;
        cout<< "2. Login"<< endl;
        cout<< "3. Exit"<< endl;
        cout<< "choose an option- ";

        int option;
        cin>> option;

        switch (option) {
            case 1:
                registerUser(users);
                break;
            case 2:
                loginUser(users);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "wrong option. Please choose again."<<endl;
                break;
        }

        cout<<endl;
    }

    return 0;
}
